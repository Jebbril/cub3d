/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:35:54 by orakib            #+#    #+#             */
/*   Updated: 2023/09/19 21:36:40 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_info3(char **dir, char **str, char *id, char *path)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] && !ft_strncmp(str[0], id, 3) && str[1])
	{
		if (*dir)
		{
			free(*dir);
			*dir = NULL;
			return (0);
		}
		while (path[i] && path[i] == ' ')
			i++;
		while (path[i] && path[i] != ' ')
			i++;
		while (path[i] && path[i] == ' ')
			i++;
		j = ft_strlen(path);
		while (path[j - 1] == ' ')
			j--;
		*dir = ft_substr(path, i, j - i);
		return (1);
	}
	return (0);
}

int	get_info2(t_cube *cube, int i)
{
	char	**str;
	int		ret;

	ret = 0;
	str = ft_split(cube->p.map[i], ' ');
	if (get_info3(&cube->p.no, str, "NO", cube->p.map[i]))
		ret = 1;
	else if (get_info3(&cube->p.so, str, "SO", cube->p.map[i]))
		ret = 1;
	else if (get_info3(&cube->p.we, str, "WE", cube->p.map[i]))
		ret = 1;
	else if (get_info3(&cube->p.ea, str, "EA", cube->p.map[i]))
		ret = 1;
	else if (get_info3(&cube->p.c, str, "C", cube->p.map[i]))
		ret = 1;
	else if (get_info3(&cube->p.f, str, "F", cube->p.map[i]))
		ret = 1;
	free_matrix(str);
	return (ret);
}

int	check_emptylines(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (cube->p.map[++i])
	{
		while (cube->p.map[i][j] && cube->p.map[i][j] == ' ')
			j++;
		if (j == ft_strlen(cube->p.map[i]))
			return (1);
	}
	return (0);
}

void	get_info(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	cube->p.no = NULL;
	cube->p.so = NULL;
	cube->p.we = NULL;
	cube->p.ea = NULL;
	cube->p.c = NULL;
	cube->p.f = NULL;
	while (cube->p.map[++i])
		j += get_info2(cube, i);
	if (j != 6 || check_emptylines(cube))
	{
		write(2, "Error\nIncorrect map info\n", 26);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
}
