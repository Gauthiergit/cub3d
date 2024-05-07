/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:04 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/07 17:25:25 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_place_pixel(t_data *data, int ray, int y, int color)
{
	char	*distance;

	distance = data->img_s.address + \
			(y * data->img_s.size_line + ray * (data->img_s.bits_per_pixel / 8));
	*(unsigned int *)distance = color;
}

void	ft_set_values(t_data *data, double dir_x, double dir_y,
		double plane_x, double plane_y)
{
	data->dir.x = dir_x;
	data->dir.y = dir_y;
	data->plane.x = plane_x;
	data->plane.y = plane_y;
}

void	ft_set_vectors(t_data *data, int y, int x)
{
	data->player.map_x = x + 0.5;//floor(data->player.px_x / SQUARE_SIZE)
	data->player.map_y = y + 0.5;
	if (data->scene[y][x] == 'N')
		ft_set_values(data, 0, -1, 0.66, 0);
	else if (data->scene[y][x] == 'S')
		ft_set_values(data, 0, 1, -0.66, 0);
	else if (data->scene[y][x] == 'W')
		ft_set_values(data, -1, 0, 0, -0.66);
	else if (data->scene[y][x] == 'E')
		ft_set_values(data, 1, 0, 0, 0.66);
}
