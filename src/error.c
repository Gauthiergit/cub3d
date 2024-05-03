/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:28:13 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/03 10:40:23 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(const char *error)
{
	printf("Error\n%s\n", error);
	exit(1);
}

void	check_error_file(int argc, char **argv)
{
	char	*file_type;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		print_error("No scene in parameter");
	file_type = ft_strrchr(argv[1], '.');
	if (!file_type || ft_strncmp(file_type, ".cub", 4) != 0)
		print_error("The file isn't of type .cub");
	if (fd == -1)
		print_error("File not found or empty");
	close(fd);
}

int	is_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!ft_strchr("01NSEW ", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_double(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (ft_strchr("NSEW", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_error_map(t_data *data)
{
	if (is_valid_char(data->scene))
		print_error("Character allowed are '10NSEW and space'");
	if (is_double(data->scene) == 0)
		print_error("There is no player position");
	if (is_double(data->scene) > 1)
		print_error("We need only one player position");
	if (check_walls(data))
		print_error("The map isn't closed");
}
