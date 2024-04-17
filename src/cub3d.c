/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:17 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/17 17:40:12 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	// t_data	data;

	check_error_file(argc, argv);
	printf("line nb :%d\n", count_line_map(argv[1]));
	return (0);
}

// reparer la fonction qui compte les lignes