/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:08:37 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 19:27:31 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_newline(t_cube *cube)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (cube->p.mapstr[++i])
	{
		if (cube->p.mapstr[i] == '\n')
			k++;
		while (cube->p.mapstr[i] && cube->p.mapstr[i] == ' ')
			i++;
		if ((cube->p.mapstr[i] == '1' || cube->p.mapstr[i] == '0')
			&& cube->p.mapstr[(i) - 1] && (cube->p.mapstr[i - 1] == '\n'
				|| cube->p.mapstr[i - 1] == ' '))
			break ;
	}
	while (cube->p.mapstr[i])
	{
		if (cube->p.mapstr[i++] == '\n' && cube->p.mapstr[i - 2] == '\n')
		{
			write(2, "Error\nNew line in the map\n", 27);
			garbage(cube);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_lastline(t_cube *cube)
{
	if (cube->p.mapstr[ft_strlen(cube->p.mapstr) - 1] == '\n')
	{
		write(2, "Error\nNew line in the map\n", 27);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
}

void	get_map(t_cube *cube)
{
	int		i;
	char	**tmp;

	i = -1;
	check_newline(cube);
	check_lastline(cube);
	tmp = ft_split(cube->p.mapstr, '\n');
	while (cube->p.map[++i])
	{
		free(cube->p.map[i]);
		cube->p.map[i] = NULL;
	}
	i = -1;
	while (tmp[++i + 6])
		cube->p.map[i] = tmp[i + 6];
	i = -1;
	while (++i < 6)
		free(tmp[i]);
	free(tmp);
}
