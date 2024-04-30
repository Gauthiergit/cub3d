/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:20 by gpeyre            #+#    #+#             */
/*   Updated: 2024/04/30 10:31:47 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
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
# define RIGHT 65363
# define LEFT 65361
# define A 97
# define D 100
# define S 115
# define W 119

/*screen*/

# define SCREEN_HEIGHT 			600
# define SCREEN_WIDTH 			800

typedef struct s_player
{
	size_t			map_x;
	size_t			map_y;
	int				px_x;
	int				px_y;
	double			angle;
	float			fov_rd;
}					t_player;

typedef struct s_ray
{
 double	ray_ngl;
 double	distance;
}				t_ray;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

/* typedef struct s_vector
{
	t_point		position;
	t_point		direction;
	t_point		plane;
}				t_vector; */

/*texture struct*/

typedef struct s_mnmap
{
	int			height;
	int			width;
	int			minixo;
	int			miniyo;
	char		*wall;
	char		*space;
	void		*img_wall;
	void		*img_space;
}				t_mnmap;

typedef struct s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			right;
	int			left;
}				t_key;

typedef struct s_img_t
{
	void		*pt_img;
	int			*address;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}					t_img_t;
	/* char		*north_air;
	char 		*south_fire;
	char		*west_water;
	char		*east_earth;*/

/*screen struct*/

typedef struct s_img_s
{
	void		*pt_img;
	char		*address;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img_s;


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
	t_img_t			img_t[4];
	t_img_s			img_s;
	t_mnmap			*mnmap;
	t_pos			pos;
	t_key			key;
	t_player		player;
	t_ray			ray;
}				t_data;

/* cub3d.c */
int		on_destroy(t_data *data);
int		on_keyrelease(int keysym, t_data *data);
int		on_keypress(int keysym, t_data *data);
int		game(t_data *data);

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

/* img_to_create */
void	ft_pixel(t_data *data, int color, int i, int j);
void	put_ceiling_and_floor(t_data *data);

/* map_init.c */
int		is_map(char *line);
void	count_line_map(t_data *data, char *file);
void	find_lgst_line(t_data *data, char *file);
void	fill_in_map(t_data *data, int fd, char *cur_line);
void	extract_map(t_data *data, char *file);

/* minimap.c */
void	ft_print_image(t_data *data, void *img, t_pos pos);
void	ft_init_minimap(t_data *data);
void	ft_print_minimap(t_data *data);

/* raycasting_1.c */
int		wall_hit(t_data *data, float x, float y);
double 	dist_ray(t_data *data, float x, float y);
double	get_dist_h_inter(t_data *data, float angle);
double	get_dist_v_inter(t_data *data, float angle);
void	raycasting(t_data *data);

/* raycasting_2.c */
void	dir_step_first(float angle, float *inter, float *step, int is_horizon);
void	dir_step_second(float angle, float *step, int is_horizon);

/* textures_init.c */
void	convert_colors(t_data *data, char **color_tab, char c);
int		valid_colors(t_data *data, char *line);
int		valid_texture_we(t_data *data, char *line, char *dup);
int		valid_texture_ns(t_data *data, char *line);
int		check_scene_infos(t_data *data, char *file);

/* utils.c */
int		ft_tab_size(char **tab);
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);

#endif