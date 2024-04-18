/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:20 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/18 16:05:53 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define BUFFER_SIZE 42

typedef struct s_data
{
	char 	**scene;
	int		i_start;
	int		i_end;
}				t_data;

/* data_init.c */
int		count_line_map(char *file);
char	**extract_map(char *file);

/* error_2.c */
int		check_walls(char **map);

/* error.c */
void	check_error_file(int argc, char **argv);

/* get_next_line.c */
char	*get_next_line(int fd);

/* utils.c */
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);

#endif