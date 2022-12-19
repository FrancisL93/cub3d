/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:52:16 by malord            #+#    #+#             */
/*   Updated: 2022/12/19 13:03:24 by malord           ###   ########.fr       */
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
# define SPACE	49
# define Y_KEY	16

# define CHARACT 4
# define FLOOR	5
# define CEILING 6
# define DOOR	7

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
	void	*text[8];
	int		text_height[8];
	int		text_width[8];
	char	*screen_addr;
	int		color[2];
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
	unsigned int	*data;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**full_config;
	char	*mapdata[6];
	char	**map;
	char	*valid_char;
	double	increment_angle;
	int		one_start;
	int		bonus;
	int		flag;
	int		tmpx;
	int		tmpy;
	bool	game_start;
	t_game	*game;
	t_img	*img;
}	t_vars;

//assets.c
void	destroy_images(void);
void	build_imgs(void);
//bonus_tools.c
void	draw_minimap(void);
int		mouse_move(int x, int y, t_vars *vars);
//doors.c
void	replace_door(void);
void	door_handling(t_vars *vars);
//floor_casting.c
void	print_floor(t_ray *ray, int i);
//game_tools.c
void	set_movement(int keycode);
//init_data.c
void	init_data(void);
int		key_hook(int keycode, t_vars *vars);
int		key_hook_bonus(int keycode, t_vars *vars);
//launcher.c
void	launch_game(void);
int		launch_game_bonus(void);
//main.c && main_bonus.c
t_vars	*get_data(void);
//quit.c
int		quit_game(int error);
//map_info.c
void	get_mapdata(void);
//map_parsing.c
void	format_map(void);
//map_tools.c
double	set_direction(char dir);
void	set_up_start(void);
void	map_square(void);
//map.c
void	validate_map(char *mapfile);
int		find_map(char **fullconfig);
void	get_map(void);
//print_tools.c
int		retrieve_color(char **color_line);
void	set_colors(void);
void	print_ceiling(t_vars *vars, t_ray *ray, int *i);
//print.c
void	generate_img(int win);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
char	*get_texture_pixel(void *text, int x, int y);
void	draw_ray(t_ray *ray, t_vars *vars);
//raycasting.c
double	init_increment(t_ray *ray);
char	*init_tmp(int x, int *i);
int		get_texture(t_ray *ray);
void	raycasting(void);
//start_screen.c
void	start_screen(void);

#endif