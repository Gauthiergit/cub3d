/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:00:14 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/24 18:01:13 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_h_inter(t_data *data, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = SQUARE_SIZE;
	x_step = SQUARE_SIZE / tan(angle);
	h_y = floor(data->player.px_y / SQUARE_SIZE) * SQUARE_SIZE;
	h_x = data->player.px_x + (h_y - data->player.px_y) / tan(angle);
}

void	raycasting(t_data *data)
{
	double	h_inter;

	data->ray_ngl = data->player.angle - (data->player.fov_rd / 2);
	h_inter = get_h_inter(data, data->ray_ngl);
}
