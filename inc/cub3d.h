/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:02:25 by flahoud           #+#    #+#             */
/*   Updated: 2022/11/15 11:10:27 by malord           ###   ########.fr       */
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

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "libft/inc/libft.h"

# define ESC 	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define LEFTA	123
# define RIGHTA 124

typedef struct s_img {
	void	*floor;
	void	*ceiling;
	void	*north;
	void	*south;
	void	*east;
	void	*west;

}t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**mapdata;
	char	**map;
	char	f_color[3];
	char	c_color[3];
	int		height;
	int		width;
	int		imgsize;
	int		x;
	int		y;
	t_img	*img;
}t_vars;

//free.c
int		quit_game(t_vars *vars);

//game.c
void	launch_game(t_vars *vars);

//main.c
void	build_imgs(t_vars *vars);
void	init_data(t_vars *vars);

//map_validation.c
int		validate_map(t_vars *vars, char *mapfile);

//print.c
void	print_result(t_vars *vars);

//data.c
t_vars	*get_data(void);

#endif