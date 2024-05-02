/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:19 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/02 15:28:25 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_texture_nb(t_data *data, int flag) // get the color of the wall
{
	data->ray.ray_ngl = nor_angle(data->ray.ray_ngl); // normalize the angle
	if (flag == 0)
	{
		// if (data->map.x > data->pos.x)
		if (data->ray.ray_ngl > M_PI / 2 && data->ray.ray_ngl < 3 * (M_PI / 2))
			data->texture_number = 2; // west wall vert
		else
			data->texture_number = 3; // east wall jaune
	}
	else
	{
		// if (data->map.y > data->pos.y)
		if (data->ray.ray_ngl > 0 && data->ray.ray_ngl < M_PI)
			data->texture_number = 1; // south wall bleu
		else
			data->texture_number = 0; // north wall rouge
	}
}

void	draw_wall_stripe(t_data *data, int ray, int t_pix, int b_pix) // draw the wall
{
	double	step;
	double	text_pos;
	int		y;

	get_texture_nb(data, data->ray.flag);
	step = 1.0 * SQUARE_SIZE / data->line_nb;
	text_pos = (t_pix - SCREEN_HEIGHT / 2 + data->line_nb / 2) * step;
	y = t_pix;
	ft_get_text_x(data);
	while (y < b_pix)
	{
		data->text_y = (int) text_pos & (SQUARE_SIZE - 1);
		text_pos += step;
		data->color = data->wall[data->texture_number][SQUARE_SIZE * data->text_x + data->text_y];
		if (data->ray.flag == 0)
			data->color = (data->color >> 1) & 8355711;
		ft_place_pixel(data, ray, y, data->color);
		y++;
	}
}

// void	draw_wall_lines(t_data *data, int ray, int t_pix, int b_pix) // draw the wall
// {
// 	//int	color;
// 	//color = get_color(data, data->ray.flag);
// 	int	y;

// 	y = t_pix;
// 	while (y < b_pix)
// 	{
// 		ft_place_pixel(data, ray, y, 0x33CC33);
// 		y++;
// 	}
// 	/* while (t_pix < b_pix)
// 	{
// 		//mlx_pixel_put(data->mlx, data->win, ray, t_pix, color);
// 		ft_pixel(data, 0x33CC33, t_pix, b_pix);
// 		t_pix++;
// 	} */
// }

void	ft_ray_pos_and_dir(t_data *data, int ray)
{
	data->cam_x = 2 * ray / (double) SCREEN_WIDTH - 1;
	data->ray_dir.x = data->dir.x + data->plane.x * data->cam_x;
	data->ray_dir.y = data->dir.y + data->plane.y * data->cam_x;
	data->map.x = (int) data->pos.x;
	data->map.y = (int) data->pos.y;
}

float	nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	render_wall(t_data *data, int ray) // render the wall
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	data->ray.distance *= cos(nor_angle(data->ray.ray_ngl - data->player.angle)); // fix the fisheye
	wall_h = (SQUARE_SIZE / data->ray.distance) * ((SCREEN_WIDTH / 2) / tan(data->player.fov_rd / 2)); // get the wall height
	b_pix = (SCREEN_HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (SCREEN_HEIGHT / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > SCREEN_HEIGHT) // check the bottom pixel
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	ft_ray_pos_and_dir(data, ray);
	draw_wall_stripe(data, ray, t_pix, b_pix); // draw the wall
}
