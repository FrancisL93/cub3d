#include "../include/cub3d.h"

void	is_valid_char(char c, char *str)
{
	static int	one_start = 0;

	if (!ft_strchr("0 1NSEW", c))
	{
		free(str);
		quit_game(10);
	}
	if (ft_strchr("NSEW", c))
	{
		if (one_start == 0)
			one_start = 1;
		else
		{
			free(str);
			quit_game(11);
		}
	}
}

int	find_map(char **fullconfig)
{
	int		i;
	int		j;
	int		wall;
	char	*tmp;

	i = -1;
	while (fullconfig[++i])
	{
		tmp = ft_strtrim(fullconfig[i], "\n");
		j = 0;
		wall = 0;
		while (tmp[j] == '0' || tmp[j] == '1' || tmp[j] == ' ')
		{
			if (tmp[j] && tmp[j] == '1')
				wall = 1;
			if (tmp[j++ + 1] == '\0' && wall == 1)
			{
				free(tmp);
				return (i);
			}
		}
		free(tmp);
	}
	return (-1);
}

int	is_map(void)
{
	t_vars	*vars;
	int		i;
	int		j;
	char	*tmp;

	vars = get_data();
	vars->map_start = find_map(vars->full_config);
	if (vars->map_start < 5)
		return (-1);
	i = vars->map_start - 1;
	while (vars->full_config[++i])
	{
		tmp = ft_strtrim(vars->full_config[i], "\n");
		j = 0;
		while (tmp[j] != '\0')
			is_valid_char(tmp[j++], tmp);
		free(tmp);
	}
	return (vars->map_start);
}

void	get_map(void)
{
	int		index;
	int		i;
	t_vars	*vars;

	vars = get_data();
	index = is_map();
	if (index == -1)
		quit_game(3);
	i = index;
	while (vars->full_config[i])
		i++;
	vars->map = ft_calloc(sizeof(char *), i - index + 1);
	if (!vars->map)
		quit_game(4);
	i = 0;
	while (vars->full_config[index])
		vars->map[i++] = vars->full_config[index++];
	vars->map[i] = NULL;
}
