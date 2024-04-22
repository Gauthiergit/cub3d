/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:19 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/22 18:14:14 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	perceived_height(t_data *data)
{
	float	p_height;

	p_height = 0;
	
}

float	dist_wall(t_data *data)
{
	float	d_wall;
	int		x;
	int		y;

	d_wall = 0;
	x = data->cam.x;
	y = data->cam.y;
	if (data->cam.dir == 'N')
	{
		while (data->scene[y][x] == '0')
		{
			d_wall += 64;
			y--;
		}
	}
}
//Pas bon trouver comment faire autrement 