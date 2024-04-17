/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:08:37 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/17 17:38:34 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		if (!ft_isalpha(*line) || *line != '\n')
			line_nb++;
		free(line);
	}
	close(fd);
	return (line_nb);
}

/* char	**extract_map(char *file)
{

} */