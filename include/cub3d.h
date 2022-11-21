
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
	char	*screen_addr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		floor_color;
}t_img;

typedef struct s_game {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	float	focal_length;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**full_config;
	char	*mapdata[6];
	char	**map;
	float	resolution;
	int		win_width;
	int		win_height;
	int		imgsize;
	int		map_start;
	t_game	*game;
	t_img	*img;
}	t_vars;

//assets.c
void	build_imgs(void);

//free.c
int		quit_game(int exit_num);

//game.c
void	launch_game(void);

//main.c
t_vars	*get_data(void);

//map.c
void	get_map(void);
int		find_map(char **fullconfig);

//map_info.c
char	*get_element_name(int *i);
int		get_element_index(char *element);
bool	check_line(char *line);
void	fill_mapdata(t_vars *vars, int index, int i);
bool	check_full_config(t_vars *vars);

//map_tools.c
void	set_up_start(void);

//map_validation.c
void	validate_map(char *mapfile);
void	read_map_file(int fd);
void	get_mapdata(void);
bool	gap_til_map(t_vars *vars, int i);

//print.c
void	generate_img(void);

//print_tools.c
void	set_colors(void);

#endif