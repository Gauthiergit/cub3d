/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:28 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/06 16:30:38 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void	ft_rotate_left(t_data *data)
{
	data->player.angle -= data->rotation_speed;
	if (data->player.angle < 0)
		data->player.angle += 2 * M_PI;
	/* double	previous_dir_x;
	double	previous_plane_x;

	previous_dir_x = data->dir.x;
	data->dir.x = data->dir.x * cos(-data->rotation_speed) \
		- data->dir.y * sin(-data->rotation_speed);
	data->dir.y = previous_dir_x * sin(-data->rotation_speed) \
		+ data->dir.y * cos(-data->rotation_speed);
	previous_plane_x = data->plane.x;
	data->plane.x = data->plane.x * cos(-data->rotation_speed) \
		- data->plane.y * sin(-data->rotation_speed);
	data->plane.y = previous_plane_x * sin(-data->rotation_speed) \
		+ data->plane.y * cos(-data->rotation_speed); */
}
void	ft_rotate_right(t_data *data)
{
	data->player.angle += data->rotation_speed;
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	/* double	previous_dir_x;
	double	previous_plane_x;

	previous_dir_x = data->dir.x;
	data->dir.x = data->dir.x * cos(data->rotation_speed) \
		- data->dir.y * sin(data->rotation_speed);
	data->dir.y = previous_dir_x * sin(data->rotation_speed) \
		+ data->dir.y * cos(data->rotation_speed);
	previous_plane_x = data->plane.x;
	data->plane.x = data->plane.x * cos(data->rotation_speed) \
		- data->plane.y * sin(data->rotation_speed);
	data->plane.y = previous_plane_x * sin(data->rotation_speed) \
		+ data->plane.y * cos(data->rotation_speed); */
}

void	ft_init_keys(t_data *data)
{
	data->key.left = 0;
	data->key.right = 0;
	data->key.a = 0;
	data->key.d = 0;
	data->key.s = 0;
	data->key.w = 0;
}
