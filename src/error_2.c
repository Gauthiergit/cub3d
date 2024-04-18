/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:08:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/18 16:18:48 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	first_last_line(char **map, size_t cur_line)
{
	int i;

	i = 0;
	while (map[cur_line][i] && map[cur_line][i] != '\n')
	{
		while (map[cur_line][i] == ' ')
			i++;
		while (map[cur_line][i] == '1')
			i++;
		if (map[cur_line][i] == ' ')
		{
			
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	size_t	cur_line;
	int		i;

	cur_line = 0;
	while (map[cur_line])
	{
		if (cur_line == 0 || cur_line == (count_line_map(map) - 1))
		{
			if (first_last_line(map, cur_line))
				return (1);
		}
		else
		{
			if (map[cur_line][0] != '1' ||
				map[cur_line][ft_strlen(map[cur_line]) - 2] != '1')
				return (1);
		}
		cur_line++;
	}
	return (0);
}
