/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:28:13 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/17 15:36:11 by gpeyre           ###   ########.fr       */
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
