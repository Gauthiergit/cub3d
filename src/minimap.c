/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:16 by gdetourn          #+#    #+#             */
/*   Updated: 2024/05/14 10:51:21 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_put_player(t_data *data)
{
	int	x;
	int	y;

	y = data->minipl.px_y - data->minipl.radius;
	while (y <= data->minipl.px_y + data->minipl.radius)
	{
		x = data->minipl.px_x - data->minipl.radius;
		while (x <= data->minipl.px_x + data->minipl.radius)
		{
			if (pow(x - data->minipl.px_x, 2) + pow(y - data->minipl.px_y, 2)
				<= pow(data->minipl.radius, 2)) // make it a blue point, not a square pixel.
				ft_pixel(data, 0x3c00ff, y + data->minipl.map_y, x + data->minipl.map_x); //Bleu violet player
			x++;
		}
		y++;
	}
}

void	ft_init_player(t_data *data)
{
	data->minipl.radius = 4;
	data->minipl.px_x = data->mnmap->minixo - ((data->mnmap->minixo - data->mnmap->width + 3) / 3);
	data->minipl.px_y = data->mnmap->minixo - ((data->mnmap->miniyo - data->mnmap->height + 5) / 1.3);
	data->minipl.map_x = cos(data->player.angle) / 2 - 0.4;
	data->minipl.map_y = sin(data->player.angle) / 2;
}

void	ft_init_minimap(t_data *data)
{
	t_mnmap	*mnmap;

	mnmap = calloc(1, sizeof(t_mnmap));
	if (!mnmap)
		exit(1);
	data->mnmap = mnmap;
	data->mnmap->width = SCREEN_WIDTH / 30;
	data->mnmap->height = SCREEN_HEIGHT / 30;
	data->mnmap->minixo = SCREEN_WIDTH / 40 * 10;
	data->mnmap->miniyo =  SCREEN_HEIGHT / 40 * 10;
	// data->mnmap->mapxb = data->mnmap->width;
	// data->mnmap->mapyb = data->mnmap->height;
	data->mnmap->mapsx = 18;//7;
	data->mnmap->mapsy = data->mnmap->mapsx - 1;
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
				ft_pixel(data, 0xffff00, i, j); //Jaune background
			j++;
		}
		i++;
	}
	ft_init_player(data);
	ft_walls(data);
	ft_put_player(data);
	free(data->mnmap);
}
