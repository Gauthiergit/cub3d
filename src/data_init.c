/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/23 15:52:51 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_cam(t_data *data)
{
	int y;
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
