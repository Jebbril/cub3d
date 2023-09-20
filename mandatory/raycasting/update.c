/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:54 by orakib            #+#    #+#             */
/*   Updated: 2023/09/20 17:07:20 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update2(t_cube *cube, float newx, float newy)
{
	if (!has_wall2(cube, newx + RADIUS, newy, cube->pl.pos)
		&& !has_wall2(cube, newx - RADIUS, newy, cube->pl.pos)
		&& !has_wall2(cube, newx, newy + RADIUS, cube->pl.pos)
		&& !has_wall2(cube, newx, newy - RADIUS, cube->pl.pos))
	{
		cube->pl.pos.x = newx;
		cube->pl.pos.y = newy;
	}
}

void	update(t_cube *cube)
{
	float	movestep;
	float	newx;
	float	newy;

	cube->pl.rotationangle += cube->pl.turndirection * cube->pl.turnspeed;
	cube->pl.rotationangle = normalize_angle(cube->pl.rotationangle);
	movestep = cube->pl.walkdirection * cube->pl.walkspeed;
	newx = cube->pl.pos.x + cos(cube->pl.rotationangle) * movestep;
	newy = cube->pl.pos.y + sin(cube->pl.rotationangle) * movestep;
	if (cube->pl.starfdirection == 1)
	{
		newx += cos(cube->pl.rotationangle - M_PI_2) * cube->pl.walkspeed;
		newy += sin(cube->pl.rotationangle - M_PI_2) * cube->pl.walkspeed;
	}
	if (cube->pl.starfdirection == -1)
	{
		newx += cos(cube->pl.rotationangle + M_PI_2) * cube->pl.walkspeed;
		newy += sin(cube->pl.rotationangle + M_PI_2) * cube->pl.walkspeed;
	}
	update2(cube, newx, newy);
}

void	render(t_cube *cube)
{
	t_pos	p;

	p.x = cube->pl.pos.x + cos(cube->pl.rotationangle) * 60;
	p.y = cube->pl.pos.y + sin(cube->pl.rotationangle) * 60;
	if (cube->img)
		mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	cast_rays(cube);
	render_walls(cube);
	mlx_image_to_window(cube->mlx, cube->img, 0, 0);
}
	// draw_minimap(cube);
	// draw_disc(cube, 0x00FFAAFF, cube->pl.radius);
	// draw_line(cube, 0x00FFAAFF, cube->pl.pos, p);
	// render_rays(cube);
