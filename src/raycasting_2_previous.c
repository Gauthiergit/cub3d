/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2_previous.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:11:02 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/02 10:48:56 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/cub3d.h"

void	dir_step_first(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*step *= -1;
			*inter -= SQUARE_SIZE;
		}
		else
			*inter += 2 * SQUARE_SIZE;
	}
	else
	{
		if (angle > M_PI /2 && angle < 3 * M_PI / 2)
		{
			*step *= -1;
			*inter -= SQUARE_SIZE;
		}
		else
			*inter += 2 * SQUARE_SIZE;
	}
}

void	dir_step_second(float angle, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
			*step *= -1;
	}
	else
	{
		if (!(angle > 0 && angle < M_PI))
			*step *= -1;
	}
} */
