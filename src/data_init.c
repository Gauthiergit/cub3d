/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/25 17:28:54 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.angle = M_PI / 2;
	else if (dir == 'S')
		data->player.angle = - M_PI / 2;
	else if (dir == 'W')
		data->player.angle = M_PI;
	else if (dir == 'E')
		data->player.angle = 0;
}

void	init_player(t_data *data)
{
	int 	y;
	int		x;
	char	dir;

	y = 0;
	while (data->scene[y])
	{
		x = 0;
		while (data->scene[y][x])
		{
			if (ft_strchr("NSEW", data->scene[y][x]))
			{
				data->player.map_x = x;
				data->player.map_y = y;
				data->player.px_x = x * SQUARE_SIZE + SQUARE_SIZE / 2;
				data->player.px_y = y * SQUARE_SIZE + SQUARE_SIZE / 2;
				data->player.fov_rd = (FOV * M_PI) / 180;
				dir = data->scene[y][x];
			}
			x++;
		}
		y++;
	}
}

void	ft_fill_wall_array(t_data *data, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->img[i].height)
	{
		x = 0;
		while (x < data->img[i].width)
		{
			data->wall[i][data->img[i].height * y + x] = \
				(data->img[i].address[data->img[i].height * y + x]);
			x++;
		}
		y++;
	}
}

void	extract_textures(t_data *data, char *file)
{
	int		i;

	i = 0;
	if (check_scene_infos(data, file))
		print_error("Scene infos not correct");
	while (i < 4)
	{
		data->img[i].pt_img = mlx_xpm_file_to_image(data->mlx, \
						data->text_tab[i], &(data->img[i].width), \
						&(data->img[i].height));
		if (!data->img[i].pt_img)
			print_error("Fail to load texture");
		data->img[i].address = (int *)mlx_get_data_addr(data->img[i].pt_img, \
						&data->img[i].bits_per_pixel, &data->img[i].size_line, \
						&data->img[i].endian);
		if (!data->img[i].address)
			print_error("Fail to load texture");
		ft_fill_wall_array(data, i);
		mlx_destroy_image(data->mlx, data->img[i].pt_img);
		i++;
	}
}
	/* data->img->img_north_air = mlx_xpm_file_to_image(data->mlx,
			data->img->north_air, &(data->img->width), &(data->img->height));
	data->img->img_south_fire = mlx_xpm_file_to_image(data->mlx,
			data->img->south_fire, &(data->img->width), &(data->img->height));
	data->img->img_west_water = mlx_xpm_file_to_image(data->mlx,
			data->img->west_water, &(data->img->width), &(data->img->height));
	data->img->img_east_earth = mlx_xpm_file_to_image(data->mlx,
			data->img->east_earth, &(data->img->width), &(data->img->height)); */

void	data_init(t_data *data, char **argv)
{
	// t_img	*img;

	data->lgst_line = 0;
	data->line_nb = 0;
	data->text_tab = NULL;
	data->NO = 0;
	data->SO = 0;
	data->WE = 0;
	data->EA = 0;
	data->F = 0;
	data->C = 0;
	/* img = calloc(1, sizeof(t_img));
	if (!img)
		exit(1); */
	//data->img = img;
	int	i = 0;
	while (i < 4)
	{
		data->img[i].height = 64;
		data->img[i].width = 64;
		data->img[i].address = 0;
		i++;
	}
	/* data->img->north_air = NULL;
	data->img->south_fire = NULL;
	data->img->west_water = NULL;
	data->img->east_earth = NULL; */
	extract_map(data, argv[1]);
	init_player(data);
	extract_textures(data, argv[1]);
	data->ray_ngl = 0.0000;
}
