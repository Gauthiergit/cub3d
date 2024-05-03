/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:28:13 by gpeyre            #+#    #+#             */
/*   Updated: 2024/05/03 14:43:27 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(const char *error, t_data *data)
{
	printf("Error\n%s\n", error);
	//if (data->scene)
	clear_tab(data->scene);
	//if (data->text_tab)
	clear_tab(data->text_tab);
	mlx_destroy_display(data->mlx);
	//if (data->mlx)
	free(data->mlx);
	exit(1);
}

int	check_error_file(int argc, char **argv)
{
	char	*file_type;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		printf("Error\nNo scene in parameter (of type .cub)\n");
		return (1);
	}
	file_type = ft_strrchr(argv[1], '.');
	if (!file_type || ft_strncmp(file_type, ".cub", 4) != 0 || fd < 0)
	{
		printf("Error\nFail to open file (file has to be .cub)\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	is_valid_char(char **map)
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
			if (!ft_strchr("01NSEW ", map[i][j]))
				return ('e');
			else
				count++;
			j++;
		}
		i++;
	}
	return (count);
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
	if (is_valid_char(data->scene) == 'e')
		print_error("Character allowed are '10NSEW and space'", data);
	if (is_valid_char(data->scene) == 0)
		print_error("Map missing or scene empty", data);
	if (is_double(data->scene) == 0)
		print_error("There is no player position", data);
	if (is_double(data->scene) > 1)
		print_error("We need only one player position", data);
	if (check_walls(data))
		print_error("The map isn't closed", data);
}
