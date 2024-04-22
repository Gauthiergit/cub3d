/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:20 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/22 10:53:31 by gpeyre           ###   ########.fr       */
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
	size_t	lgst_line;
	int		line_nb;
	void	*north_texture;
	void 	*south_texture;
	void	*west_texture;
	void	*east_texture;
}				t_data;

/* data_init.c */
void		count_line_map(t_data *data, char *file);
void	extract_map(t_data *data, char *file);

/* error_2.c */
int		check_walls(t_data *data);
void	find_lgst_line(t_data *data, char *file);

/* error.c */
void	check_error_file(int argc, char **argv);
void	check_error_map(t_data *data);

/* get_next_line.c */
char	*get_next_line(int fd);

/* utils.c */
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);

#endif