/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:54 by orakib            #+#    #+#             */
/*   Updated: 2023/09/11 20:02:56 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update(t_cube *cube)
{
	float	movestep;
	float	starfstep;
	float	newx;
	float	newy;

	cube->pl.rotationangle += cube->pl.turndirection * cube->pl.turnspeed;
	cube->pl.rotationangle = normalize_angle(cube->pl.rotationangle);
	movestep = cube->pl.walkdirection * cube->pl.walkspeed;
	starfstep = cube->pl.starfdirection * cube->pl.walkspeed;
	newx = cube->pl.pos.x + cos(cube->pl.rotationangle) * movestep
		+ sin(cube->pl.rotationangle) * starfstep;
	newy = cube->pl.pos.y + sin(cube->pl.rotationangle) * movestep
		+ cos(cube->pl.rotationangle) * starfstep;
	if (!has_wall(cube, newx, newy))
	{
		cube->pl.pos.x = newx;
		cube->pl.pos.y = newy;
	}
}

void	render(t_cube *cube)
{
	t_pos	p;

	p.x = cube->pl.pos.x + cos(cube->pl.rotationangle) * 60;
	p.y = cube->pl.pos.y + sin(cube->pl.rotationangle) * 60;
	if (cube->img)
		mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	draw_minimap(cube);
	draw_disc(cube, 0x00FFAAFF, cube->pl.radius);
	draw_line(cube, 0x00FFAAFF, cube->pl.pos, p);
	mlx_image_to_window(cube->mlx, cube->img, 0, 0);
}
