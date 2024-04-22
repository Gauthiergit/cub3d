/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:38:25 by gdetourn          #+#    #+#             */
/*   Updated: 2024/04/22 13:07:04 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		valid_texture(t_data *data, char *line)
{
	char *path;

	if (line[2] == ' ' && line[3] == '.')
	{
		path = ft_strchr(line, '.');
		if (open(path, O_RDONLY) == 0)
			return (1);
		if (line[0] == 'N' && line[1] == 'O')
		{
			data->NO = 1;
			data->north_air = path;
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			data->SO = 1;
			data->south_fire = path;
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			data->WE = 1;
			data->west_water = path;
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			data->EA = 1;
			data->east_earth = path;
		}
		close(path);
	}
	else if (line[0] == 'F' && line[1] == ' ')
	{

	}
	else if (line[0] == 'C' && line[1] == ' ')
	{

	}

}

void	check_scene_infos(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (valid_texture(data, line))
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);

}

void	extract_textures(t_data *data, char *file)
{
	data->NO = 0;
	data->SO = 0;
	data->WE = 0;
	data->WE = 0;
	check_scene_infos(data, file);
	//mlx;
}
