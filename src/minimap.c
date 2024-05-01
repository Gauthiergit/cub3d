/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwen <gwen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:16 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/01 17:14:55 by gwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* void	ft_print_image(t_data *data, void *img, t_pos pos)
{
	mlx_put_image_to_window(data->mlx, data->win, img, pos.x * 32,
		(pos.y * 32 + 532));
} */

void	ft_put_player(t_data *data)
{
	int	x;
	int	y;

	y = data->player.px_y - data->player.angle;
	while (y <= data->player.px_y + data->player.angle)
	{
		x = data->player.px_x - data->player.angle;
		while (x <= data->player.px_x + data->player.angle)
		{
			if (pow(x - data->player.px_x, 2) + pow(y - data->player.px_y, 2)
				<= pow(data->player.angle, 2))
				ft_pixel(data, 0x3c00ff, y, x); //Bleu violet player
			x++;
		}
		y++;
	}
}

void	ft_init_player(t_data *data)
{
	data->player.angle = 4.5;
	data->player.px_x = data->mnmap->minixo - ((data->mnmap->minixo - data->mnmap->width + 3) / 2);
	data->player.px_y = data->mnmap->minixo - ((data->mnmap->miniyo - data->mnmap->height + 5) / 2);
	data->player.map_x = cos(data->player.fov_rd) / 2 - 0.4;
	data->player.map_y = sin(data->player.fov_rd) / 2;
}

void	ft_init_minimap(t_data *data)
{
	t_mnmap	*mnmap;

	mnmap = calloc(1, sizeof(t_mnmap));
	if (!mnmap)
		exit(1);
	data->mnmap = mnmap;
	data->mnmap->height = SCREEN_HEIGHT / 30;
	data->mnmap->width = SCREEN_WIDTH / 30;
	data->mnmap->minixo = SCREEN_WIDTH / 40 * 10;
	data->mnmap->miniyo =  SCREEN_HEIGHT / 40 * 10;
	data->mnmap->mapxb = data->mnmap->width;
	data->mnmap->mapyb = data->mnmap->height;
	data->mnmap->mapsx = 7;
	data->mnmap->mapsy = data->mnmap->mapsx - 1;
	/* data->mnmap->img_wall = mlx_xpm_file_to_image(data->mlx, data->mnmap->wall,
			&(data->mnmap->width), &(data->mnmap->height));
	data->mnmap->img_space = mlx_xpm_file_to_image(data->mlx, data->mnmap->space,
			&(data->mnmap->width), &(data->mnmap->height)); */
}

void	ft_print_minimap(t_data *data)
{
	int	i;
	int	j;

	ft_init_minimap(data);
	i = data->mnmap->height;
	while (i < data->mnmap->miniyo)
	{
		j = data->mnmap->width;
		while (j < data->mnmap->minixo)
		{
			if (j % 2 == 0 && i % 2 == 0)
				ft_pixel(data, 0xffff00, i, j); //Jaune
			j++;
		}
		i++;
	}
	ft_init_player(data);
	ft_walls(data);
	ft_put_player(data);
}

/* void	ft_init_minimap(t_data *data)
{
	t_mnmap	*mnmap;

	mnmap = calloc(1, sizeof(t_mnmap));
	if (!mnmap)
		exit(1);
	data->mnmap = mnmap;
	data->mnmap->height = SCREEN_HEIGHT / 30;
	data->mnmap->width = SCREEN_WIDTH / 30;
	data->mnmap->wall = "./texture/wall.xpm";
	data->mnmap->space = "./texture/space.xpm";
	data->mnmap->img_wall = mlx_xpm_file_to_image(data->mlx, data->mnmap->wall,
			&(data->mnmap->width), &(data->mnmap->height));
	data->mnmap->img_space = mlx_xpm_file_to_image(data->mlx, data->mnmap->space,
			&(data->mnmap->width), &(data->mnmap->height));
}

void	ft_print_minimap(t_data *data)
{
	t_pos	pos;

	ft_init_minimap(data);
	pos.y = 0;
	while (data->scene[pos.y])
	{
		pos.x = 0;
		while (data->scene[pos.y][pos.x])
		{
			if (data->scene[pos.y][pos.x] == '1' || data->scene[pos.y][pos.x] == ' ')
				ft_print_image(data, data->mnmap->img_wall, pos);
			if (data->scene[pos.y][pos.x] == '0')
				ft_print_image(data, data->mnmap->img_space, pos);
			if (data->scene[pos.y][pos.x] == 'N'
				|| data->scene[pos.y][pos.x] == 'S'
				|| data->scene[pos.y][pos.x] == 'W'
				|| data->scene[pos.y][pos.x] == 'E')
				ft_pixel(data, 0xffff00, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
	}
}
 */