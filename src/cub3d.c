/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:17 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/26 16:33:32 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*should return an int but exit(0) is required to quit the program properly*/
int	on_destroy(t_data *data)
{
	//ft_destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	clear_tab(data->scene);
	clear_tab(data->text_tab);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		printf("Don't want to play anymore?\n");
		on_destroy(data);
	}
	/*  else if (keysym == LEFT)
		ft_move(data, &(data->pos_p), ROT_LEFT);
	 else if (keysym == RIGHT)
		ft_move(data, &(data->pos_p), ROT_RIGHT);
	else if (keysym == A)
		ft_move(data, &(data->pos_p), LEFT);
	else if (keysym == D)
		ft_move(data, &(data->pos_p), RIGHT);
	else if (keysym == S)// || keysym == 65364)
		ft_move(data, &(data->pos_p), DOWN);
	else if (keysym == W)// || keysym == 65362)
		ft_move(data, &(data->pos_p), UP); */
	return (0);
}

int	game(t_data *data)
{
	data->img_s.pt_img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_s.address = mlx_get_data_addr(data->img_s.pt_img, \
						&data->img_s.bits_per_pixel, &data->img_s.size_line, \
						&data->img_s.endian);
	put_floor(data);
	put_ceiling(data);
	//raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_s.pt_img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_s.pt_img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_error_file(argc, argv);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data_init(&data, argv);
	check_error_map(&data);
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!data.win)
		return (free(data.mlx), 1);
	mlx_loop_hook(data.mlx, game, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
