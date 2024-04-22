/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:20 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/22 17:15:37 by gpeyre           ###   ########.fr       */
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
# define H_WALL 64.00
# define W_WALL 64.00
# define H_CAM 32.00

typedef struct s_place
{
	size_t			x;
	size_t			y;
	char			dir;
}					t_place;

typedef struct s_data
{
	char 		**scene;
	size_t		lgst_line;
	int			line_nb;
	int			NO;
	int			SO;
	int			WE;
	int			EA;
	void		*north_air;
	void 		*south_fire;
	void		*west_water;
	void		*east_earth;
	t_place		cam;
}				t_data;

/* data_init.c */
void	data_init(t_data *data, char **argv);
void	find_cam(t_data *data);

/* map_init.c */
int		is_map(char *line);
void	count_line_map(t_data *data, char *file);
void	find_lgst_line(t_data *data, char *file);
void	fill_in_map(t_data *data, int fd, char *cur_line);
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