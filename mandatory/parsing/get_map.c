/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:08:37 by orakib            #+#    #+#             */
/*   Updated: 2023/08/15 18:37:37 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_newline(t_cube *cube)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (cube->mapstr[++i])
	{
		if (cube->mapstr[i] == '\n')
			k++;
		while (cube->mapstr[i] && cube->mapstr[i] == ' ')
			i++;
		if ((cube->mapstr[i] == '1' || cube->mapstr[i] == '0')
			&& cube->mapstr[(i) - 1] && (cube->mapstr[i - 1] == '\n'
				|| cube->mapstr[i - 1] == ' '))
			break ;
	}
	while (cube->mapstr[i])
	{
		if (cube->mapstr[i++] == '\n' && cube->mapstr[i - 2] == '\n')
		{
			write(2, "Error\nNew line in the map\n", 27);
			garbage(cube);
			exit(EXIT_FAILURE);
		}
	}
}

void	get_map(t_cube *cube)
{
	int		i;
	char	**tmp;

	i = -1;
	check_newline(cube);
	tmp = ft_split(cube->mapstr, '\n');
	while (cube->map[++i])
	{
		free(cube->map[i]);
		cube->map[i] = NULL;
	}
	i = -1;
	while (tmp[++i + 6])
		cube->map[i] = tmp[i + 6];
	i = -1;
	while (++i < 6)
		free(tmp[i]);
	free(tmp);
	i = -1;
	while (cube->map[++i])
		printf("%s\n", cube->map[i]);
}
