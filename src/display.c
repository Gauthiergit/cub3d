/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:19 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/02 10:44:07 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int get_color(t_data *data, int flag) // get the color of the wall
{
	data->ray.ray_ngl = nor_angle(data->ray.ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (data->ray.ray_ngl > M_PI / 2 && data->ray.ray_ngl < 3 * (M_PI / 2))
			return (0x33CC33); // west wall vert
		else
			return (0xFFFF33); // east wall jaune
	}
	else
	{
		if (data->ray.ray_ngl > 0 && data->ray.ray_ngl < M_PI)
			return (0x0033FF); // south wall bleu
		else
			return (0xCC0033); // north wall rouge
	}
}

void draw_wall(t_data *data, int ray, int t_pix, int b_pix) // draw the wall
{
	int	color;

	color = get_color(data, data->ray.flag);
	while (t_pix < b_pix)
	{
		mlx_pixel_put(data->mlx, data->win, ray, t_pix, color);
		t_pix++;
	}
}


void render_wall(t_data *data, int ray) // render the wall
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	data->ray.distance *= cos(nor_angle(data->ray.ray_ngl - data->player.angle)); // fix the fisheye
	wall_h = (SQUARE_SIZE / data->ray.distance) * ((SCREEN_WIDTH / 2) / tan(data->player.fov_rd / 2)); // get the wall height
	b_pix = (SCREEN_HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (SCREEN_HEIGHT / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > SCREEN_HEIGHT) // check the bottom pixel
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(data, ray, t_pix, b_pix); // draw the wall
}
