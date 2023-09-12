/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:18:41 by orakib            #+#    #+#             */
/*   Updated: 2023/09/12 18:12:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_pos(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cube->p.map[++i])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == 'N' || cube->p.map[i][j] == 'S'
				|| cube->p.map[i][j] == 'W' || cube->p.map[i][j] == 'E')
			{
				cube->pl.pos.x = j * TILE_SIZE + TILE_SIZE / 2;
				cube->pl.pos.y = i * TILE_SIZE + TILE_SIZE / 2;
			}
		}
		j = -1;
	}
}

float	get_rotationangle(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cube->p.map[++i])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == 'E')
				return (0);
			else if (cube->p.map[i][j] == 'S')
				return (M_PI / 2);
			else if (cube->p.map[i][j] == 'W')
				return (M_PI);
			else if (cube->p.map[i][j] == 'N')
				return (1.5 * M_PI);
		}
		j = -1;
	}
	return (0);
}

void	init_rays(t_cube *cube)
{
	int		i;
	float	rayangle;
	float	inc;

	i = -1;
	rayangle = cube->pl.rotationangle - (FOV / 2);
	inc = FOV / (float)NUM_RAYS;
	while (++i < NUM_RAYS)
	{
		cube->rays[i].rayangle = rayangle;
		cube->rays[i].wallhitx = 0;
		cube->rays[i].wallhity = 0;
		cube->rays[i].distance = 0;
		cube->rays[i].washitvertical = FALSE;
		cube->rays[i].israyfacingdown = cube->rays[i].rayangle > 0
			&& cube->rays[i].rayangle < M_PI;
		cube->rays[i].israyfacingup = !cube->rays[i].israyfacingdown;
		cube->rays[i].israyfacingright = cube->rays[i].rayangle < M_PI * 0.5
			|| cube->rays[i].rayangle > 1.5 * M_PI;
		cube->rays[i].israyfacingleft = !cube->rays[i].israyfacingright;
		rayangle += inc;
	}
}

void	initialize(t_cube *cube)
{
	set_pos(cube);
	cube->pl.radius = RADIUS;
	cube->pl.turndirection = 0;
	cube->pl.walkdirection = 0;
	cube->pl.starfdirection = 0;
	cube->pl.rotationangle = get_rotationangle(cube);
	cube->pl.walkspeed = 2;
	cube->pl.turnspeed = 2 * (M_PI / 180);
	cube->img = NULL;
	init_rays(cube);
}
