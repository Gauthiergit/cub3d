/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:38:25 by gdetourn          #+#    #+#             */
/*   Updated: 2024/04/23 15:54:01 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_colors(t_data *data, char *line)
{
	char	**color_tab;
	int		i;

	if (line[1] == ' ')
	{
		color_tab = ft_split(ft_strchr(line, line[2]), ',');
		if (!color_tab)
			return (1);
		i = 0;
		while (color_tab[i])
		{
			if (ft_atoi(color_tab[i]) < 0 || 255 < ft_atoi(color_tab[i]))
				return (1);
			i++;
		}
		if (line[0] == 'F')
			data->F++;
		else if (line[0] == 'C')
			data->C++;
		clear_tab(color_tab);
	}
	return (0);
}

void	valid_texture_WE(t_data *data, char *line, char *path)
{
	if (line[0] == 'W' && line[1] == 'E')
	{
		data->WE++;
		data->img->west_water = path;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		data->EA++;
		data->img->east_earth = path;
	}
}

int		valid_texture_NS(t_data *data, char *line)
{
	char	*path;
	int		fd;

	if (line[2] == ' ' && line[3] == '.')
	{
		path = ft_strchr(line, '.');
		fd = open(path, O_RDONLY);
		if (fd == -1)
			return (1);
		if (line[0] == 'N' && line[1] == 'O')
		{
			data->NO++;
			data->img->north_air = path;
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			data->SO++;
			data->img->south_fire = path;
		}
		else if ((line[0] == 'W' && line[1] == 'E')
				|| (line[0] == 'E' && line[1] == 'A'))
			valid_texture_WE(data, line, path);
		close(fd);
	}
	else if  (line[0] == 'F' || line[0] == 'C' || line[0] == '\n')
		return (valid_colors(data, line));
	return (1);
}

int	check_scene_infos(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (!valid_texture_NS(data, line))
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	printf("NO = %d SO = %d WE = %d EA = %d F = %d C = %d\n", data->NO,
		data->SO, data->WE, data->EA, data->F, data->C);
	if (data->NO != 1 && data->SO != 1 && data->WE != 1 && data->EA != 1
		&& data->F != 1 && data->C != 1)
		return (1);
	return (0);
}

void	extract_textures(t_data *data, char *file)
{
	if (check_scene_infos(data, file))
		print_error("Scene infos not correct");
	data->img->img_north_air = mlx_xpm_file_to_image(data->mlx,
			data->img->north_air, &(data->img->width), &(data->img->height));
	data->img->img_south_fire = mlx_xpm_file_to_image(data->mlx,
			data->img->south_fire, &(data->img->width), &(data->img->height));
	data->img->img_west_water = mlx_xpm_file_to_image(data->mlx,
			data->img->west_water, &(data->img->width), &(data->img->height));
	data->img->img_east_earth = mlx_xpm_file_to_image(data->mlx,
			data->img->east_earth, &(data->img->width), &(data->img->height));
}
