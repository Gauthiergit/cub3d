/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:12:36 by gwen              #+#    #+#             */
/*   Updated: 2024/05/07 14:01:34 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_pixel_mnmap(t_data *data, int color)
{
	int	i;
	int	j;

	i = data->mnmap->height;
	while (i < data->mnmap->height + data->mnmap->mapsy - 1)
	{
		j = data->mnmap->width;
		while (j < data->mnmap->width + data->mnmap->mapsx - 1)
		{
			if (i < data->mnmap->miniyo - 2 && j < data->mnmap->minixo - 2
				&& i > data->mnmap->mapyb && j > data->mnmap->mapxb)
				ft_pixel(data, color, i, j);
			j++;
		}
		i++;
	}
}

void	ft_read_map(t_data *data, int io, int jo)
{
	if (io < data->line_nb && 0 <= io && 0 <= jo
		&& jo < (int)ft_strlen(data->scene[io]))
	{
		if (data->scene[io] && data->scene[io][jo]
			&& data->scene[io][jo] == '1')
			ft_pixel_mnmap(data, 0x5d0606); //rouge foncé
		else if (data->scene[io][jo] == '0')
			ft_pixel_mnmap(data, 0xffffff); //blanc
		else if (data->scene[io][jo] == 'N' || data->scene[io][jo] == 'S'
			|| data->scene[io][jo] == 'W' || data->scene[io][jo] == 'E')
			ft_pixel_mnmap(data, 0xff0000); //jaune
		else
			return ;
	}
}

void	ft_walls(t_data *data)
{
	int	i;
	int	io;
	int	j;
	int	jo;

	i = -12;//-4
	while (i < 13)//5
	{
		j = -18;//-6
		io = (int)data->player.map_y + i;
		while (j < 7)
		{
			jo = (int)data->player.map_x + j;
			ft_read_map(data, io, jo);
			j++;
			data->mnmap->width += data->mnmap->mapsx;
		}
		data->mnmap->width -= data->mnmap->mapsx * (7 - (-18));
		data->mnmap->height += data->mnmap->mapsy;
		i++;
	}
}
