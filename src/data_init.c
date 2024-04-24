/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/24 16:21:39 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_cam(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->scene[y])
	{
		x = 0;
		while (data->scene[y][x])
		{
			if (ft_strchr("NSEW", data->scene[y][x]))
			{
				data->cam.x = x;
				data->cam.y = y;
				data->cam.dir = data->scene[y][x];
			}
			x++;
		}
		y++;
	}
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

void	data_init(t_data *data, char **argv)
{
	t_img	*img;

	data->lgst_line = 0;
	data->line_nb = 0;
	data->NO = 0;
	data->SO = 0;
	data->WE = 0;
	data->EA = 0;
	data->F = 0;
	data->C = 0;
	img = calloc(1, sizeof(t_img));
	if (!img)
		exit(1);
	data->img = img;
	data->img->height = 64;
	data->img->width = 64;
	data->img->north_air = NULL;
	data->img->south_fire = NULL;
	data->img->west_water = NULL;
	data->img->east_earth = NULL;
	extract_map(data, argv[1]);
	find_cam(data);
	extract_textures(data, argv[1]);
}
