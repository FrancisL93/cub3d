
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

# include <mlx.h>
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

# define PI		3.14159265

typedef struct s_img {
	void	*floor;
	void	*ceiling;
	void	*north;
	void	*south;
	void	*east;
	void	*west;

	void	*screen_view;
	char	*screen_data;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_game {
	int	posx;
	int	posy;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**full_config;
	char	*mapdata[6];
	char	**map;
	void	*screenview;
	char	f_color[3];
	char	c_color[3];
	int		win_width;
	int		win_height;
	int		imgsize;
	int		map_start;
	t_game	*game;
	t_img	*img;
}	t_vars;

//assets.c
void	build_imgs(void);

//data.c
t_vars	*get_data(void);
void	init_data(void);

//free.c
int		quit_game(int exit_num);

//game.c
void	launch_game(void);

//main.c

//map.c
void	get_map(void);
int		find_map(char **fullconfig);

//map_info.c
char	*get_element_name(int *i);
int		get_element_index(char *element);
bool	check_line(char *line);
void	fill_mapdata(t_vars *vars, int index, int i);
bool	check_full_config(t_vars *vars);

//map_validation.c
void	validate_map(char *mapfile);
void	read_map_file(int fd);
void	get_mapdata(void);
bool	gap_til_map(t_vars *vars, int i);

//print.c
void	print_result(void);

#endif