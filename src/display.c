/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:19 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/07 16:50:38 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_texture_nb(t_data *data, int flag) // get the color of the wall
{
	data->ray.ray_ngl = nor_angle(data->ray.ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (data->ray.ray_ngl > M_PI / 2 && data->ray.ray_ngl < 3 * (M_PI / 2))
			data->texture_number = 2; // west wall vert
		else
			data->texture_number = 3; // east wall jaune
	}
	else
	{
		if (data->ray.ray_ngl > 0 && data->ray.ray_ngl < M_PI)
			data->texture_number = 1; // south wall bleu
		else
			data->texture_number = 0; // north wall rouge
	}
}

void	draw_wall_stripe(t_data *data, int ray, int t_pix, int b_pix) // draw the wall
{
	double	step;
	double	text_pos_y;

	get_texture_nb(data, data->ray.flag);
	step = SQUARE_SIZE / data->wall_h;
	text_pos_y = (t_pix - SCREEN_HEIGHT / 2 + data->wall_h / 2) * step;
	if (data->ray.flag == 1)
		data->text_x = fmodf(data->h_x, SQUARE_SIZE);
	else
		data->text_x = fmodf(data->v_y, SQUARE_SIZE);
	while (t_pix < b_pix)
	{
		data->text_y = (int) text_pos_y & (SQUARE_SIZE - 1);
		data->color = data->wall[data->texture_number][SQUARE_SIZE * data->text_y + data->text_x];
		text_pos_y += step;
		if (data->ray.flag == 0)
			data->color = (data->color >> 1) & 8355711;
		ft_place_pixel(data, ray, t_pix, data->color);
		t_pix++;
	}
}

float	nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	render_wall(t_data *data, int ray) // render the wall
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
	draw_wall_stripe(data, ray, t_pix, b_pix); // draw the wall
}
