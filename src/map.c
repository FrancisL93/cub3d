#include "../include/cub3d.h"

bool	is_valid_char(char c)
{
	static int	one_start;

	if (c != ' ' && c != '1' && c != '0' && !ft_strchr("NSEW", c))
		return (false);
	if (ft_strchr("NSEW", c))
	{
		if (one_start == 0)
			one_start = 1;
		else
		{
			printf("Error: More than one start position");
			return (false);
		}
	}
	return (true);
}

//REFACTOR for Norminette
int	find_map(char **fullconfig)
{
	int		i;
	int		j;
	int		wall;
	char	*tmp;

	i = 0;
	while (fullconfig[i])
	{
		tmp = ft_strtrim(fullconfig[i], "\n");
		j = 0;
		wall = 0;
		while (tmp[j] == '0' || tmp[j] == '1' || tmp[j] == ' ')
		{
			if (tmp[j] && tmp[j] == '1')
				wall = 1;
			if (tmp[j + 1] == '\0' && wall == 1)
			{
				free(tmp);
				return (i);
			}
			j++;
		}
		free(tmp);
		i++;
	}
	return (-1);
}

//REFACTOR for Norminette
int	is_map(char **fullconfig)
{
	int		i;
	int		j;
	int		mapstart;
	char	*tmp;

	mapstart = find_map(fullconfig);
	if (mapstart == -1)
		return (-1);
	i = mapstart;
	while (fullconfig[i])
	{
		tmp = ft_strtrim(fullconfig[i], "\n");
		j = 0;
		while (tmp[j] != '\0')
		{
			if (is_valid_char(tmp[j]) == false)
			{
				free(tmp);
				return (-1);
			}
			j++;
		}
		free(tmp);
		i++;
	}
	return (mapstart);
}

bool	get_map(void)
{
	int		index;
	int		i;
	t_vars	*vars;

	vars = get_data();
	index = is_map(vars->full_config);
	if (index == -1)
		return (false);
	i = index;
	while (vars->full_config[i])
		i++;
	vars->map = ft_calloc(sizeof(char *), i - index + 1);
	if (!vars->map)
		return (false);
	i = 0;
	while (vars->full_config[index])
		vars->map[i++] = vars->full_config[index++];
	vars->map[i] = NULL;
	return (true);
}