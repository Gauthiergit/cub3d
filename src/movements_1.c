/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:53 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/08 11:21:07 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_left(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle - M_PI / 2) * 2.0);//data->move_speed);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_x = x;
	y = roundf(data->player.px_y + sin(data->player.angle - M_PI / 2) * 2.0);//data->move_speed);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_y = y;
}

void	ft_move_right(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle + M_PI / 2) * 2.0);//data->move_speed);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_x = x;
	y = roundf(data->player.px_y + sin(data->player.angle + M_PI / 2) * 2.0);//data->move_speed);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_y = y;
}

void	ft_move_backwards(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle + M_PI) * 2.0);//data->move_speed);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_x = x;
	y = roundf(data->player.px_y + sin(data->player.angle + M_PI) * 2.0);//data->move_speed);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_y = y;
}

void	ft_move_forward(t_data *data)
{
	int	x;
	int	y;

	x = roundf(data->player.px_x + cos(data->player.angle) * 2.0);//data->move_speed);
	y = (int)data->player.px_y;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_x = x;
	y = roundf(data->player.px_y + sin(data->player.angle) * 2.0);//data->move_speed);
	x = (int)data->player.px_x;
	if (data->scene[(int)floor(y / SQUARE_SIZE)][(int)floor(x / SQUARE_SIZE)] != '1')
		data->player.px_y = y;
}

void	ft_movements(t_data *data)
{
	if (data->key.a == 1)
		ft_move_left(data);
	else if (data->key.d == 1)
		ft_move_right(data);
	else if (data->key.s == 1)// || keysym == 65364)
		ft_move_backwards(data);
	else if (data->key.w == 1)// || keysym == 65362)
		ft_move_forward(data);
	else if (data->key.left == 1)
		ft_rotate_left(data);
	else if (data->key.right == 1)
		ft_rotate_right(data);
}
