/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/24 18:07:44 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void	init_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.angle = M_PI / 2;
	else if (dir == 'S')
		data->player.angle = -M_PI / 2;
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
	init_angle(data, dir);
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
	init_player(data);
	extract_textures(data, argv[1]);
	data->ray_ngl = 0.0000;
}
