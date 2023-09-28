/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:20:43 by orakib            #+#    #+#             */
/*   Updated: 2023/09/28 16:29:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_content(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->p.map[++i])
	{
		j = -1;
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == '1' && cube->p.map[i][j] == '0'
				&& cube->p.map[i][j] == ' ' && cube->p.map[i][j] == 'N'
				&& cube->p.map[i][j] == 'S' && cube->p.map[i][j] == 'E'
				&& cube->p.map[i][j] == 'W')
			{
				write(2, "Error\nMap content is not correct !\n", 36);
				garbage(cube);
				exit(EXIT_FAILURE);
			}
		}
	}
}
