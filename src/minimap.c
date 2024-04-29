/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:16 by gdetourn          #+#    #+#             */
/*   Updated: 2024/04/29 15:52:49 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_print_image(t_data *data, void *img, t_pos pos)
{
	mlx_put_image_to_window(data->mlx, data->win, img, pos.x * 32,
		(pos.y * 32 + 532));
}

void	ft_init_minimap(t_data *data)
{
	t_mnmap	*mnmap;

	mnmap = calloc(1, sizeof(t_mnmap));
	if (!mnmap)
		exit(1);
	data->mnmap = mnmap;
	data->mnmap->height = SQUARE_SIZE;
	data->mnmap->width = SQUARE_SIZE;
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
				mlx_pixel_put(data->mlx, data->win, pos.x, pos.y, 0xffff00);
			pos.x++;
		}
		pos.y++;
	}
}
