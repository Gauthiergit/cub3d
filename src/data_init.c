/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/22 17:36:46 by gpeyre           ###   ########.fr       */
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
	data->lgst_line = 0;
	data->line_nb = 0;
	extract_map(data, argv[1]);
	find_cam(data);
	extract_textures(data, argv[1]);
}
