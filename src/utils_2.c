/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:04 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/02 14:32:46 by gdetourn         ###   ########.fr       */
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

void	ft_get_text_x(t_data *data)
{
	if (data->ray.flag == 1)
		data->wall_x = data->pos.y + data->ray.distance * data->ray_dir.y;
	else
		data->wall_x = data->pos.x + data->ray.distance * data->ray_dir.x;
	data->wall_x -= floor(data->wall_x);
	data->text_x = (int)(data->wall_x * (double)SQUARE_SIZE);
	if (data->ray.flag == 1 && data->ray_dir.x > 0)
		data->text_x = SQUARE_SIZE - data->text_x - 1;
	if (data->ray.flag == 0 && data->ray_dir.y < 0)
		data->text_x = SQUARE_SIZE - data->text_x - 1;
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
	data->pos.x = x + 0.5;
	data->pos.y = y + 0.5;
	if (data->scene[y][x] == 'N')
		ft_set_values(data, 0, -1, 0.66, 0);
	else if (data->scene[y][x] == 'S')
		ft_set_values(data, 0, 1, -0.66, 0);
	else if (data->scene[y][x] == 'W')
		ft_set_values(data, -1, 0, 0, -0.66);
	else if (data->scene[y][x] == 'E')
		ft_set_values(data, 1, 0, 0, 0.66);
}
