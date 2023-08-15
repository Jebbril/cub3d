/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:35:54 by orakib            #+#    #+#             */
/*   Updated: 2023/08/15 18:37:40 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_info3(char **dir, char **str, char *id, int start)
{
	if (!ft_strncmp(str[0], id, 3) && str[1])
	{
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
	if (j != 6)
	{
		write(2, "Error\nIncorrect map info\n", 26);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
}
