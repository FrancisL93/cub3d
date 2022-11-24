#include "../include/cub3d.h"

//TODO Verifier les contours 
//TODO Fonction check_walls un coup nouvelle carte générée

void	check_walls(void)
{
	//REFACTOR for Norminette
	
	t_vars	*vars;
	int		line;
	int		column;

	vars = get_data();
	line = 0;
	column = 0;
	while (vars->map[line])
	{
		if (line == 0)
		{
			while (vars->map[0][column] && column < (int)ft_strlen(vars->map[0]) - 1)
			{
				if (vars->map[0][column] != '1')
				{
					printf("check_walls 1\n");
					quit_game(13);
				}
				column++;
			}
			column = 0;
			line++;
		}
		if (vars->map[line][0] != '1' || vars->map[line][ft_strlen(vars->map[line]) - 2] != '1')
		{
			printf("check_walls 2\n");
			quit_game(13);
		}
		if (!vars->map[line + 1])
		{
			column = 0;
			while (vars->map[line][column] && column < (int)ft_strlen(vars->map[line]))
			{
				if (vars->map[line][column] != '1')
				{
					printf("%c, check_walls 3\n", vars->map[line][column]);
					quit_game(13);
				}
				column++;
			}
		}
		line++;
	}
	printf("MAP EST OK\n");
}

void	check_spaces(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if ((column >= 0 && vars->map[line][column + 1]
		&& vars->map[line][column + 1] == '0')
		|| (column >= 0 && vars->map[line][column - 1]
		&& vars->map[line][column - 1] == '0')
			|| (line >= 0 && vars->map[line + 1]
			&& vars->map[line + 1][column] == '0')
				|| (line > 0 && vars->map[line - 1][column]
				&& vars->map[line - 1][column] == '0'))
	{
		printf("check_spaces\n");
		quit_game(13);
	}
	else
		vars->map[line][column] = '1';
}

static void	print_new_map(int i, int j)
{
	t_vars	*vars;

	vars = get_data();
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			printf("%c", vars->map[i][j]);
			j++;
		}
		i++;
	}
}

void	check_zeros(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (!vars->map[line + 1][column] || !(vars->map[line - 1][column])
		|| vars->map[line - 1][column] == '\n'
		|| vars->map[line + 1][column] == '\n')
	{
		printf("check_zeros\n");
		quit_game(13);
	}
}

void	spaces_handling(void)
{
	t_vars	*vars;
	int		i;
	int		j;

	vars = get_data();
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == ' ')
				check_spaces(i, j);
			if (vars->map[i][j] == '0' && vars->map[i + 1])
				check_zeros(i, j);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	printf("NOUVELLE MAP ------------------\n");
	print_new_map(i, j);
	check_walls();
}
