/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/29 18:34:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.angle = M_PI / 2;
	else if (dir == 'S')
		data->player.angle = 3 * M_PI / 2;
	else if (dir == 'W')
		data->player.angle = M_PI;
	else if (dir == 'E')
		data->player.angle = 0;
}

void	init_player(t_data *data)
{
	int		y;
	int		x;
	char	dir;

	y = 0;
	while (data->scene[y])
	{
		x = 0;
		while (data->scene[y][x])
		{
			if (ft_strchr("NSEW", data->scene[y][x]))
			{
				data->player.map_x = x;
				data->player.map_y = y;
				data->player.px_x = x * SQUARE_SIZE + SQUARE_SIZE / 2;
				data->player.px_y = y * SQUARE_SIZE + SQUARE_SIZE / 2;
				data->player.fov_rd = (FOV * M_PI) / 180;
				dir = data->scene[y][x];
			}
			x++;
		}
		y++;
	}
	init_angle(data, dir);
}

void	ft_fill_wall_array(t_data *data, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->img_t[i].height)
	{
		x = 0;
		while (x < data->img_t[i].width)
		{
			data->wall[i][data->img_t[i].height * y + x] = \
				(data->img_t[i].address[data->img_t[i].height * y + x]);
			x++;
		}
		y++;
	}
}

void	extract_textures(t_data *data, char *file)
{
	int		i;

	i = 0;
	if (check_scene_infos(data, file))
		print_error("Scene infos not correct");
	while (i < 4)
	{
		data->img_t[i].pt_img = mlx_xpm_file_to_image(data->mlx, \
						data->text_tab[i], &(data->img_t[i].width), \
						&(data->img_t[i].height));
		if (!data->img_t[i].pt_img)
			print_error("Fail to load texture");
		data->img_t[i].address = (int *)mlx_get_data_addr(data->img_t[i].pt_img, \
						&data->img_t[i].bits_per_pixel, &data->img_t[i].size_line, \
						&data->img_t[i].endian);
		if (!data->img_t[i].address)
			print_error("Fail to load texture");
		ft_fill_wall_array(data, i);
		mlx_destroy_image(data->mlx, data->img_t[i].pt_img);
		i++;
	}
}

void	data_init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->lgst_line = 0;
	data->line_nb = 0;
	data->text_tab = NULL;
	data->NO = 0;
	data->SO = 0;
	data->WE = 0;
	data->EA = 0;
	data->F = 0;
	data->C = 0;
	extract_map(data, argv[1]);
	init_player(data);
	while (i < 4)
	{
		data->img_t[i].width = SQUARE_SIZE;
		data->img_t[i].height = SQUARE_SIZE;
		i++;
	}
	extract_textures(data, argv[1]);
	data->ray.ray_ngl = 0.0000;
}
