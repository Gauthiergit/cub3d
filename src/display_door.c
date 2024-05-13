/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:43:13 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/13 15:43:13 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_door_x(t_data *data)
{
	if (data->ray.flag == 1)
		data->text_x = fmodf(data->h_x, SQUARE_SIZE);
	else
		data->text_x = fmodf(data->v_y, SQUARE_SIZE);
}

void	draw_door(t_data *data, int ray, int t_pix, int b_pix)
{
	double	step;
	double	text_pos_y;

	step = SQUARE_SIZE / data->wall_h;
	text_pos_y = (t_pix - SCREEN_HEIGHT / 2 + data->wall_h / 2) * step;
	get_door_x(data);
	while (t_pix < b_pix)
	{
		data->text_y = text_pos_y;//& (SQUARE_SIZE - 1);
		data->color = data->door[0][SQUARE_SIZE * data->text_y + data->text_x];
		text_pos_y += step;
		if (data->ray.flag == 0)
			data->color = (data->color >> 1) & 8355711;
		ft_place_pixel(data, ray, t_pix, data->color);
		t_pix++;
	}
}

void	render_door(t_data *data, int ray) // render the wall
{
	double	b_pix;
	double	t_pix;

	data->ray.distance *= cos(nor_angle(data->ray.ray_ngl - data->player.angle)); // fix the fisheye
	data->wall_h = (SQUARE_SIZE / data->ray.distance) * ((SCREEN_WIDTH / 2) / tan(data->player.fov_rd / 2)); // get the wall height
	b_pix = (SCREEN_HEIGHT / 2) + (data->wall_h / 2); // get the bottom pixel
	t_pix = (SCREEN_HEIGHT / 2) - (data->wall_h / 2); // get the top pixel
	if (b_pix > SCREEN_HEIGHT) // check the bottom pixel
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_door(data, ray, t_pix, b_pix);
}
