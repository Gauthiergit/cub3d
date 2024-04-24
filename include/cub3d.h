/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:20 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/24 18:21:49 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define BUFFER_SIZE 42
# define SQUARE_SIZE 64
# define FOV 60
# define H_CAM 32
# define ESC 65307

// screen

# define SCREEN_HEIGHT 			1000
# define SCREEN_WIDTH 			1500

typedef struct s_player
{
	size_t			map_x;
	size_t			map_y;
	int				px_x;
	int				px_y;
	double			angle;
	float			fov_rd;
}					t_player;

typedef struct s_img
{
	int			height;
	int			width;
	void		*pt_img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*address;
	/* char		*north_air;
	char 		*south_fire;
	char		*west_water;
	char		*east_earth;
	void		*img_north_air;
	void 		*img_south_fire;
	void		*img_west_water;
	void		*img_east_earth; */
}					t_img;

typedef struct s_data
{
	void			*mlx;
	void 			*win;
	char 			**scene;
	size_t			lgst_line;
	int				line_nb;
	unsigned long	floor_hex;
	unsigned long	ceiling_hex;
	char			**text_tab;
	int				NO;
	int				SO;
	int				WE;
	int				EA;
	int				F;
	int				C;
	int				wall[4][SQUARE_SIZE * SQUARE_SIZE];
	t_img			img[4];
	t_player		player;
	double 			ray_ngl;
}				t_data;

/* cub3d.c */
int		on_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);

/* data_init.c */
void	data_init(t_data *data, char **argv);
void	init_player(t_data *data);
void	extract_textures(t_data *data, char *file);

/* error_2.c */
int		check_walls(t_data *data);
void	find_lgst_line(t_data *data, char *file);

/* error.c */
void	print_error(const char *error);
void	check_error_file(int argc, char **argv);
int		is_valid_char(char **map);
void	check_error_map(t_data *data);

/* exit.c */
//void	ft_destroy_images(t_data *data);

/* get_next_line.c */
char	*get_next_line(int fd);

/* map_init.c */
int		is_map(char *line);
void	count_line_map(t_data *data, char *file);
void	find_lgst_line(t_data *data, char *file);
void	fill_in_map(t_data *data, int fd, char *cur_line);
void	extract_map(t_data *data, char *file);

/* textures_init.c */
void	convert_colors(t_data *data, char **color_tab, char c);
int		valid_colors(t_data *data, char *line);
int		valid_texture_we(t_data *data, char *line, char **path_tab);
int		valid_texture_ns(t_data *data, char *line);
int		check_scene_infos(t_data *data, char *file);

/* utils.c */
int		ft_tab_size(char **tab);
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);

#endif