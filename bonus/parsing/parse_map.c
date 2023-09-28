/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:07 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/09/28 15:21:57 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_edges(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (cube->p.map[0] == NULL)
	{
		write(2, "Error\nThere is no map\n", 23);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	while (cube->p.map[0][++i])
		if (cube->p.map[0][i] != ' ' && cube->p.map[0][i] != '1')
			return (1);
	i = -1;
	while (cube->p.map[j])
		j++;
	j--;
	while (cube->p.map[j][++i])
		if (cube->p.map[j][i] != ' ' && cube->p.map[j][i] != '1')
			return (1);
	return (0);
}

int	check_sides(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->p.map[++i + 1])
	{
		while (cube->p.map[i][j] == ' ')
			j++;
		if (cube->p.map[i][j] != '1')
			return (1);
		while (cube->p.map[i][j])
			j++;
		j--;
		while (cube->p.map[i][j] == ' ')
			j--;
		if (cube->p.map[i][j] != '1')
			return (1);
		j = 0;
	}
	return (0);
}

int	check_zeros(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (cube->p.map[++i + 1])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == '0' || cube->p.map[i][j] == 'N'
				|| cube->p.map[i][j] == 'W' || cube->p.map[i][j] == 'E'
				|| cube->p.map[i][j] == 'S')
			{
				if (cube->p.map[i + 1][j] == ' ' || cube->p.map[i - 1][j] == ' '
					|| cube->p.map[i][j + 1] == ' '
					|| cube->p.map[i][j - 1] == ' ')
					return (1);
			}
		}
		j = -1;
	}
	return (0);
}

int	check_player(t_cube *cube)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = -1;
	count = 0;
	while (cube->p.map[++i + 1])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == 'S' || cube->p.map[i][j] == 'N'
				|| cube->p.map[i][j] == 'W' || cube->p.map[i][j] == 'E')
				count++;
		}
		j = -1;
	}
	if (count != 1)
		return (1);
	return (0);
}

void	parse_map(t_cube *cube)
{
	if (check_edges(cube))
	{
		write(2, "Error\nMap edges are not correct\n", 33);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	if (check_sides(cube))
	{
		write(2, "Error\nMap sides are not correct\n", 33);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	if (check_zeros(cube))
	{
		write(2, "Error\nMap have space in wrong position\n", 40);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	if (check_player(cube))
	{
		write(2, "Error\nwrong player count\n", 26);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	check_content(cube);
}
