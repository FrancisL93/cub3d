
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

# include "minilibx/mlx.h"
//# include "../mlx/mlx.h"    //M1 Mac @home
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/include/libft.h"

# define ESC 	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define LEFTA	123
# define RIGHTA 124

# define BYTE_SIZE 4
# define PI		3.14159265

typedef struct s_img {
	void	*screen_view;
	void	*north_text;
	void	*south_text;
	void	*east_text;
	void	*west_text;
	char	*screen_addr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		floor_color;
	int		ceiling_color;
	int		wall_color;
}t_img;

typedef struct s_game {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	ray_x;
	double	ray_y;
	double	raycos;
	double	raysin;
	double	movement;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**full_config;
	char	*mapdata[6];
	char	**map;
	double	focal_length;
	double	increment_angle;
	double	ray_precision;
	int		win_width;
	int		win_height;
	int		imgsize;
	int		map_start;
	int		one_start;
	t_game	*game;
	t_img	*img;
}	t_vars;

//assets.c
void	build_imgs(void);

//free.c
int		quit_game(int exit_num);

//game.c
void	launch_game(void);

//game_tools.c
void	set_movement(int keycode);

//main.c
t_vars	*get_data(void);

//map.c
int		find_map(char **fullconfig);
void	get_map(void);
void	is_valid_char(char c, char *str);

//map_info.c
int		get_element_index(char *element);
void	get_mapdata(void);
bool	check_full_config(t_vars *vars);

//map_parsing.c
void	spaces_handling(void);

//map_tools.c
void	set_up_start(void);

//map_validation.c
void	validate_map(char *mapfile);
void	read_map_file(int fd);

//print.c
void	generate_img(void);
void	draw_ray(int x, int wall_height);

//print_tools.c
void	set_colors(void);

//raycasting.c
void	raycasting(void);

#endif