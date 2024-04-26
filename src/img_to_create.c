/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:41:53 by gdetourn          #+#    #+#             */
/*   Updated: 2024/04/26 11:49:18 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    put_ceiling(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < SCREEN_WIDTH)
    {
        j = 0;
        while (j < SCREEN_HEIGHT / 2)
        {
            mlx_pixel_put(data->mlx, data->win, i, j, data->ceiling_hex);
            j++;
        }
        i++;
    }
}

void    put_floor(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < SCREEN_WIDTH)
    {
        j = SCREEN_HEIGHT / 2;
        while (j < SCREEN_HEIGHT)
        {
            mlx_pixel_put(data->mlx, data->win, i, j, data->floor_hex);
            j++;
        }
        i++;
    }
}
