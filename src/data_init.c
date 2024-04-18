/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:08:37 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/18 14:43:52 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
int	is_map(char *line)
{
	if (ft_isalpha(line[0]) && ft_isalpha(line[1]))
		return (0);
	else if (ft_isalpha(line[0]) && line[1] == ' ')
		return (0);
	else if (line[0] == '\n')
		return (0);
	return (1);
}

int	count_line_map(char *file)
{
	int		fd;
	int		line_nb;
	char	*line;

	fd = open(file, O_RDONLY);
	line_nb = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (is_map(line))
			line_nb++;
		free(line);
	}
	close(fd);
	return (line_nb);
}

char	**extract_map(char *file)
{
	int		fd;
	int		len;
	char	**map;
	char	*line;
	int		i;

	len = count_line_map(file);
	map = (char **)malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (!is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	while (1)
	{
		if (line == NULL)
			break;
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map[i] = 0;
	return (map);
}
