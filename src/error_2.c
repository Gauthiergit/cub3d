/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:08:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/19 19:18:10 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	first_last_line(t_data *data, size_t cur_line)
{
	int	i;

	i = 0;
	if (data->scene[cur_line][0] == '0')
		return (1);
	while (data->scene[cur_line][i])
	{
		if (data->scene[cur_line][i] != '1'
			&& data->scene[cur_line][i] != ' '
			&& data->scene[cur_line][i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	other_line(t_data *data, size_t cur_line)
{
	int i;

	i = 0;
	if (data->scene[cur_line][0] == '0')
		return (1);
	while (data->scene[cur_line][i])
	{
		if (data->scene[cur_line][i] == '0')
		{
			if (!data->scene[cur_line][i + 1] || data->scene[cur_line][i + 1] == ' '
				|| (!data->scene[cur_line][i - 1] || data->scene[cur_line][i - 1] == ' ')
				|| (!data->scene[cur_line - 1][i] || data->scene[cur_line - 1][i] == ' ')
				|| (!data->scene[cur_line + 1][i] || data->scene[cur_line + 1][i] == ' ')
				|| (!data->scene[cur_line - 1][i - 1] || data->scene[cur_line - 1][i - 1] == ' ')
				|| (!data->scene[cur_line - 1][i + 1] || data->scene[cur_line - 1][i + 1] == ' ')
				|| (!data->scene[cur_line + 1][i - 1] || data->scene[cur_line + 1][i - 1] == ' ')
				|| (!data->scene[cur_line + 1][i + 1] || data->scene[cur_line + 1][i + 1] == ' '))
				return (1);
		}
		i++;
	}
	return (0);
}


int	check_walls(t_data *data)
{
	size_t	cur_line;

	cur_line = 0;
	while (data->scene[cur_line])
	{
		if (cur_line == 0 || cur_line == (count_line_tab(data->scene) - 1))
		{
			if (first_last_line(data, cur_line))
				return (1);
		}
		else
		{
			if (other_line(data, cur_line))
				return (1);
		}
		cur_line++;
	}
	return (0);
}
