#include "../include/cub3d.h"

int	get_element_index(char *element)
{
	char	*elem_list[6];
	int		i;

	i = 0;
	elem_list[0] = "NO";
	elem_list[1] = "SO";
	elem_list[2] = "WE";
	elem_list[3] = "EA";
	elem_list[4] = "F";
	elem_list[5] = "C";

	while (i < 6)
	{
		if (ft_strncmp(element, elem_list[i], ft_strlen(elem_list[i])) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_element_name(int *i)
{
	t_vars	*vars;
	char	**temp;
	char	*element_name;

	vars = get_data();
	while (check_line(vars->full_config[*i]) == false)
		(*i)++;
	temp = ft_split(vars->full_config[*i], ' ');
	if (temp[0] && temp[0][0] == '1')
		return (NULL);
	if (get_element_index(temp[0]) == -1 || !temp[1])
	{
		free_double_array((void **)temp);
		return (NULL);
	}
	else
	{
		element_name = ft_strdup(temp[0]);
		free_double_array((void **)temp);
		return (element_name);
	}
	free_double_array((void **)temp);
	return (NULL);
}

bool	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isalpha(line[i]) == 0)
		i++;
	if (get_element_index(&line[i]) == -1)
		return (false);
	return (true);
}

void	fill_mapdata(t_vars *vars, int index, int i)
{
	if (index != -1 && vars->mapdata[index] == NULL)
			vars->mapdata[index] = vars->full_config[i];
	else
	{
		printf("Error and goodbye\n");
		return ;
	}
}

bool	check_full_config(t_vars *vars)
{
	int	j;

	j = 0;
	while (vars->mapdata[j++])
	{
		if (j >= 6)
			return (true);
	}
	return (false);
}
