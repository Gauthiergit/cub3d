/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:48:54 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/09 15:20:57 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	extract_text_door(t_data *data)
{
	data->text_door[0].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D1_PATH, &(data->text_door[0].width), \
						&(data->text_door[0].height));
	if (!data->text_door[0].pt_img)
			print_error("Fail to load texture 0", data);
	data->text_door[1].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D2_PATH, &(data->text_door[1].width), \
						&(data->text_door[1].height));
	if (!data->text_door[1].pt_img)
			print_error("Fail to load texture 1", data);
	data->text_door[2].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D3_PATH, &(data->text_door[2].width), \
						&(data->text_door[2].height));
	if (!data->text_door[2].pt_img)
			print_error("Fail to load texture 2", data);
	data->text_door[3].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D4_PATH, &(data->text_door[3].width), \
						&(data->text_door[3].height));
	if (!data->text_door[3].pt_img)
			print_error("Fail to load texture 3", data);
	data->text_door[4].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D5_PATH, &(data->text_door[4].width), \
						&(data->text_door[4].height));
	if (!data->text_door[4].pt_img)
			print_error("Fail to load texture 4", data);
	data->text_door[5].pt_img = mlx_xpm_file_to_image(data->mlx, \
						D6_PATH, &(data->text_door[5].width), \
						&(data->text_door[5].height));
	if (!data->text_door[5].pt_img)
			print_error("Fail to load texture 5", data);
}

void	fill_door_array(t_data *data, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->text_door[i].height)
	{
		x = 0;
		while (x < data->text_door[i].width)
		{
			data->door[i][data->text_door[i].height * y + x] = \
				(data->text_door[i].address[data->text_door[i].height * y + x]);
			x++;
		}
		y++;
	}	
}

void	get_text_door_addr(t_data *data)
{

	int	i;

	i = 0;
	while (i < 6)
	{
		data->text_door[i].address =
			(int *)mlx_get_data_addr(data->text_door[i].pt_img, \
			&data->text_door[i].bits_per_pixel, &data->text_door[i].size_line, \
			&data->text_door[i].endian);
		if (!data->text_door[i].address)
			print_error("Fail to load texture addr", data);
		fill_door_array(data, i);
		mlx_destroy_image(data->mlx, data->text_door[i].pt_img);
		i++;
	}
}

void	texture_init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img_t[i].width = SQUARE_SIZE;
		data->img_t[i].height = SQUARE_SIZE;
		i++;
	}
	extract_textures(data, argv[1]);
	i = 0;
	while (i < 6)
	{
		data->text_door[i].width = SQUARE_SIZE;
		data->text_door[i].height = SQUARE_SIZE;
		i++;
	}
	extract_text_door(data);
	get_text_door_addr(data);
}
