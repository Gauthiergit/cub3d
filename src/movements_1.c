/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:53 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/06 17:45:51 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* void	ft_move_player(t_data *data, double move_x, double move_y)
{
	int	grid_pos_x;
	int	grid_pos_y;
	int	x;
	int	y;

	x = roundf(data->player.px_x + move_x);
	y = roundf(data->player.px_y + move_y);
	grid_pos_x = x / SQUARE_SIZE;
	grid_pos_y = y / SQUARE_SIZE;
	if (data->scene[grid_pos_y][grid_pos_x] != '1'
		&& data->scene[grid_pos_y][data->player.px_x / SQUARE_SIZE] != '1'
		&& data->scene[data->player.px_y / SQUARE_SIZE][grid_pos_x] != '1')
	{
		data->player.px_x = x;
		data->player.px_y = y;
	}
}

void	ft_movements(t_data *data, double move_x, double move_y)
{
	if (data->key.a == 1)
	{
		move_x = sin(data->player.angle) * data->move_speed;
		move_y = -cos(data->player.angle) * data->move_speed;
	}
	else if (data->key.d == 1)
	{
		move_x = -sin(data->player.angle) * data->move_speed;
		move_y = cos(data->player.angle) * data->move_speed;
	}
	else if (data->key.s == 1)// || keysym == 65364)
	{
		move_x = -sin(data->player.angle) * data->move_speed;
		move_y = -cos(data->player.angle) * data->move_speed;
	}
	else if (data->key.w == 1)// || keysym == 65362)
	{
		move_x = sin(data->player.angle) * data->move_speed;
		move_y = cos(data->player.angle) * data->move_speed;
	}
	else if (data->key.left == 1)
		ft_rotate_left(data);
	else if (data->key.right == 1)
		ft_rotate_right(data);
	ft_move_player(data, move_x, move_y);
} */

void	ft_move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->pos.x + data->dir.y * data->move_speed);
	y = (int)data->pos.y;
	if (data->scene[y][x] != '1')
		data->pos.x += data->dir.y * data->move_speed;
	y = (int)(data->pos.y - data->dir.x * data->move_speed);
	x = (int)data->pos.x;
	if (data->scene[y][x] != '1')
		data->pos.y -= data->dir.x * data->move_speed;
}

void	ft_move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->pos.x - data->dir.y * data->move_speed);
	y = (int)data->pos.y;
	if (data->scene[y][x] != '1')
		data->pos.x -= data->dir.y * data->move_speed;
	y = (int)(data->pos.y + data->dir.x * data->move_speed);
	x = (int)data->pos.x;
	if (data->scene[y][x] != '1')
		data->pos.y += data->dir.x * data->move_speed;
}

void	ft_move_backwards(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->pos.x - data->dir.x * data->move_speed);
	y = (int)data->pos.y;
	if (data->scene[y][x] != '1')
		data->pos.x -= data->dir.x * data->move_speed;
	y = (int)(data->pos.y - data->dir.y * data->move_speed);
	x = (int)data->pos.x;
	if (data->scene[y][x] != '1')
		data->pos.y -= data->dir.y * data->move_speed;
}

void	ft_move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->pos.x + data->dir.x * data->move_speed);
	y = (int)data->pos.y;
	if (data->scene[y][x] != '1')
		data->pos.x += data->dir.x * data->move_speed;
	y = (int)(data->pos.y + data->dir.y * data->move_speed);
	x = (int)data->pos.x;
	if (data->scene[y][x] != '1')
		data->pos.y += data->dir.y * data->move_speed;
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
