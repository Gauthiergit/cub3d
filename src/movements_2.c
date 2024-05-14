/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:28 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/14 16:57:02 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void	ft_rotate_left(t_data *data)
{
	data->player.angle -= 0.04;//data->rotation_speed;
	if (data->player.angle < 0)
		data->player.angle += 2 * M_PI;
}
void	ft_rotate_right(t_data *data)
{
	data->player.angle += 0.04;//data->rotation_speed;
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
}

void	ft_init_keys(t_data *data)
{
	data->key.left = 0;
	data->key.right = 0;
	data->key.a = 0;
	data->key.d = 0;
	data->key.s = 0;
	data->key.w = 0;
	data->key.space = 0;
}
