/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:06:59 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/09/29 15:07:01 by mmesbahi         ###   ########.fr       */
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
