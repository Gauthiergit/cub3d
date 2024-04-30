/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:11:17 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/30 17:34:30 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	wall_hit(t_data *data, float x, float y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (1);
	x_m = floor (x / SQUARE_SIZE);
	y_m = floor (y / SQUARE_SIZE);
	if (data->scene[y_m] && data->scene[y_m][x_m])
		if (data->scene[y_m][x_m] == '1')
			return (1);
	return (0);
}

double dist_ray(t_data *data, float x, float y)
{
	double	dif_x;
	double	dif_y;

	if (x < data->player.px_x)
		dif_x = data->player.px_x - x;
	else
		dif_x = x - data->player.px_x;
	if (y < data->player.px_y)
		dif_y = data->player.px_y - y;
	else
		dif_y = y - data->player.px_y;
	return (sqrt(pow(dif_x, 2) + pow(dif_y, 2)));
}

double	get_dist_h_inter(t_data *data, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;

	y_step = SQUARE_SIZE;
	x_step = SQUARE_SIZE / tan(angle);
	h_y = floor(data->player.px_y / SQUARE_SIZE) * SQUARE_SIZE;
	dir_step_first(data->ray.ray_ngl, &h_y, &y_step, 1);
	if (h_y < data->player.px_y)
		h_x = data->player.px_x + (data->player.px_y - h_y) / tan(angle);
	else
		h_x = data->player.px_x + (h_y - data->player.px_y) / tan(angle);
	dir_step_second(data->ray.ray_ngl, &x_step, 1);
	while (!wall_hit(data, h_x, h_y))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (dist_ray(data, h_x, h_y));
}

double	get_dist_v_inter(t_data *data, float angle)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;

	x_step = SQUARE_SIZE;
	y_step = SQUARE_SIZE / tan(angle);
	v_x = floor(data->player.px_x / SQUARE_SIZE) * SQUARE_SIZE;
	dir_step_first(data->ray.ray_ngl, &v_x, &x_step, 0);
	if (v_x < data->player.px_x)
		v_y = data->player.px_y + (data->player.px_x - v_x) / tan(angle);
	else
		v_y = data->player.px_y + (v_x - data->player.px_x) / tan(angle);
	dir_step_second(data->ray.ray_ngl, &y_step, 0);
	while (!wall_hit(data, v_x, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (dist_ray(data, v_x, v_y));
}

void	raycasting(t_data *data)
{
	double	dist_h_inter;
	double	dist_v_inter;
	int		ray;

	ray = 0;
	data->ray.ray_ngl = data->player.angle + (data->player.fov_rd / 2);
	data->ray.ray_ngl = nor_angle(data->ray.ray_ngl);
	while (ray < SCREEN_WIDTH)
	{
		dist_h_inter = get_dist_h_inter(data, data->ray.ray_ngl);
		dist_v_inter = get_dist_v_inter(data, data->ray.ray_ngl);
		if (dist_h_inter <= dist_v_inter)
		{
			data->ray.distance = dist_h_inter;
			data->ray.flag = 1;
		}
		else
		{
			data->ray.distance = dist_v_inter;
			data->ray.flag = 0;
		}
		render_wall(data, ray);
		data->ray.ray_ngl += (data->player.fov_rd / SCREEN_WIDTH);
		data->ray.ray_ngl = nor_angle(data->ray.ray_ngl);
		ray++;
	}
}
