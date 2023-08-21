/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:35:54 by orakib            #+#    #+#             */
/*   Updated: 2023/08/21 16:46:32 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_info3(char **dir, char **str, char *id, int start)
{
	if (str[0] && !ft_strncmp(str[0], id, 3) && str[1])
	{
		if (*dir)
		{
			free(*dir);
			*dir = NULL;
			return (0);
		}
		*dir = ft_substr(str[1], start, ft_strlen(str[1]));
		return (1);
	}
	return (0);
}

int	get_info2(t_cube *cube, int i)
{
	char	**str;
	int		ret;

	ret = 0;
	str = ft_split(cube->map[i], ' ');
	if (get_info3(&cube->no, str, "NO", 2))
		ret = 1;
	else if (get_info3(&cube->so, str, "SO", 2))
		ret = 1;
	else if (get_info3(&cube->we, str, "WE", 2))
		ret = 1;
	else if (get_info3(&cube->ea, str, "EA", 2))
		ret = 1;
	else if (get_info3(&cube->c, str, "C", 0))
		ret = 1;
	else if (get_info3(&cube->f, str, "F", 0))
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
	while (cube->map[++i])
	{
		while (cube->map[i][j] && cube->map[i][j] == ' ')
			j++;
		if (j == ft_strlen(cube->map[i]))
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
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->ea = NULL;
	cube->c = NULL;
	cube->f = NULL;
	while (cube->map[++i])
		j += get_info2(cube, i);
	if (j != 6 || check_emptylines(cube))
	{
		write(2, "Error\nIncorrect map info\n", 26);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
}
