/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwen <gwen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:53 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/15 16:33:55 by gwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_left(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle - M_PI / 2) * 2.0);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_x = x;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
	y = roundf(data->player.px_y + sin(data->player.angle - M_PI / 2) * 2.0);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_y = y;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
}

void	ft_move_right(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle + M_PI / 2) * 2.0);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_x = x;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
	y = roundf(data->player.px_y + sin(data->player.angle + M_PI / 2) * 2.0);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_y = y;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
}

void	ft_move_backwards(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle + M_PI) * 2.0);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_x = x;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
	y = roundf(data->player.px_y + sin(data->player.angle + M_PI) * 2.0);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_y = y;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
}

void	ft_move_forward(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle) * 2.0);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_x = x;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
	y = roundf(data->player.px_y + sin(data->player.angle) * 2.0);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1'
		&& data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != 'D')
	{
		data->player.px_y = y;
		data->player.map_x = (int)floor(x / SQUARE_SIZE);
		data->player.map_y = (int)floor(y / SQUARE_SIZE);
	}
}

void	ft_movements(t_data *data)
{
	if (data->key.a == 1)
		ft_move_left(data);
	else if (data->key.d == 1)
		ft_move_right(data);
	else if (data->key.s == 1)
		ft_move_backwards(data);
	else if (data->key.w == 1)
		ft_move_forward(data);
	else if (data->key.left == 1)
		ft_rotate_left(data);
	else if (data->key.right == 1)
		ft_rotate_right(data);
	else if (data->key.space == 1)
		ft_open_door(data);
}
