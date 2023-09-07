/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:53:01 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 19:27:31 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_commas(t_cube *cube)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (cube->p.c[++i])
		if (cube->p.c[i] == ',')
			j++;
	if (j != 2)
		return (1);
	i = -1;
	j = 0;
	while (cube->p.f[++i])
		if (cube->p.f[i] == ',')
			j++;
	if (j != 2)
		return (1);
	return (0);
}

int	parse_colors2(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (1);
	i = -1;
	j = -1;
	while (colors[++i])
	{
		while (colors[i][++j])
			if (!ft_isdigit(colors[i][j]))
				return (1);
		if (j > 3)
			return (1);
		j = -1;
		if (ft_atoi(colors[i]) > 255)
			return (1);
	}
	return (0);
}

int	parse_colors(t_cube *cube)
{
	char	**f;
	char	**c;

	if (count_commas(cube))
		return (1);
	c = ft_split(cube->p.c, ',');
	f = ft_split(cube->p.f, ',');
	if (parse_colors2(c) || parse_colors2(f))
		return (1);
	cube->p.c_red = ft_atoi(c[0]);
	cube->p.c_green = ft_atoi(c[1]);
	cube->p.c_blue = ft_atoi(c[2]);
	cube->p.f_red = ft_atoi(f[0]);
	cube->p.f_green = ft_atoi(f[1]);
	cube->p.f_blue = ft_atoi(f[2]);
	free_matrix(c);
	free_matrix(f);
	return (0);
}

void	parse_info(t_cube *cube)
{
	if (parse_colors(cube))
	{
		write(2, "Error\nIncorrect color values\n", 30);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
	if (!cube->p.no || !cube->p.so || !cube->p.ea || !cube->p.we
		|| !cube->p.no[0] || !cube->p.so[0] || !cube->p.ea[0] || !cube->p.we[0])
	{
		write(2, "Error\nEmpty textures\n", 30);
		garbage(cube);
		exit(EXIT_FAILURE);
	}
}
