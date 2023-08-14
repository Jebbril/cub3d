/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:08:37 by orakib            #+#    #+#             */
/*   Updated: 2023/08/14 18:03:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	check_newline(cube);
	free(cube->map[0]);
	free(cube->map[1]);
	free(cube->map[2]);
	free(cube->map[3]);
	free(cube->map[4]);
	free(cube->map[5]);
	cube->map += 6;
	int	i = -1;
	while (cube->map[++i])
		printf("%s\n", cube->map[i]);
}
