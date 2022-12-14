/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:52:16 by malord            #+#    #+#             */
/*   Updated: 2022/12/14 09:01:08 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 open, close, read, write,
printf, malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm man man 3 math)
• All functions of the MinilibX
*/
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/include/libft.h"
# include "../cub3d_settings.h"

# define ESC 	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define LEFTA	123
# define RIGHTA 124

# define FLOOR	4
# define CEILING 5

# define BYTE_SIZE 4
# define PI		3.14159265

typedef struct s_ray {
	double	x;
	double	y;
	double	cos;
	double	sin;
	double	angle;
	double	distance;
	double	text_increment;
	int		pos;
	int		wall_height;
	int		texture;
	int		text_pos;
	int		text[2];
}		t_ray;

typedef struct s_img {
	void	*screen_view;
	void	*text[5];
	void	*character;
	void	*floor;
	void	*ceiling;
	char	*character_file;
	int		character_size[2];
	int		floor_size[2];
	int		ceiling_size[2];
	int		text_height[5];
	int		text_width[5];
	char	*screen_addr;
	int		floor_color;
	int		ceiling_color;
	int		bpp;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_game {
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			movement;
	double			xa;
	double			ya;
	unsigned int	*data;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**full_config;
	char	*mapdata[6];
	char	**map;
	double	increment_angle;
	int		one_start;
	int		text_pos;
	int		texture;
	int		bonus;
	t_game	*game;
	t_img	*img;
}	t_vars;

//assets.c
void	destroy_images(int num);
void	*get_text(char *texture, int num);
void	build_imgs(void);

//data.c
t_vars	*get_data(void);

//floor_casting.c
void	floor_casting(t_ray *ray, int y);

//free.c
void	free_bonus(void);
int		closewin(void);
int		quit_game(int exit_num);

//game_tools.c
void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);
void	set_movement(int keycode);

//game.c
int		key_hook(int keycode, t_vars *vars);
void	init_data(void);
void	launch_game(void);

//map_info.c
int		get_element_index(char *element);
bool	check_full_config(t_vars *vars);
void	get_mapdata(void);

//map_parsing.c
void	check_ones(int line, int column);
void	check_walls(void);
void	check_spaces(int line, int column);
void	check_zeros(int line, int column);
void	map_square(void);

//map_tools.c
double	set_direction(char dir);
void	fill_minimap(void);
void	set_up_start(void);
void	format_map(void);

//map_validation.c
int		check_file(char *map);
void	read_map_file(int fd);
void	validate_map(char *mapfile);

//map.c
void	is_valid_char(char c, char *str);
int		find_map(char **fullconfig);
int		is_map(void);
void	get_map(void);

//print_tools.c
void	free_n_quit(char **color_line, char **rgb);
void	validate_rgb(char **color_line, char **rgb);
int		retrieve_color(char **color_line);
void	set_colors(void);

//print.c
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
char	*get_texture_pixel(void *text, int x, int y);
void	draw_ray(t_ray *ray, t_vars *vars);
void	generate_img(int win);
double	init_increment(t_ray *ray);

//raycasting.c
int		get_texture(t_ray *ray);
void	init_ray(double angle);
void	raycasting(void);

//raycasting_tools.c
double	init_increment(t_ray *ray);
char	*init_tmp(int x, int *i);

//minimap.c
char	*get_color(int map_item);
void	sqmmap(int x, int y, int map_itemp, t_vars *vars);
void	draw_minimap(void);

//mouse_move.c
int		mouse_move(int x, int y, t_vars *vars);

//parsing_bonus.c
void    is_valid_char_bonus(char c, char *str);

#endif