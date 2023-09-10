/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:54 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 18:10:19 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update(t_cube *cube)
{
	float	movestep;
	float	newx;
	float	newy;

	cube->pl.rotationangle += cube->pl.turndirection * cube->pl.turnspeed;
	movestep = cube->pl.walkdirection * cube->pl.walkspeed;
	newx = cube->pl.pos.x + cos(cube->pl.rotationangle) * movestep;
	newy = cube->pl.pos.y + sin(cube->pl.rotationangle) * movestep;
	if (!has_wall(cube, newx, newy) && 
		!has_wall(cube, newx, newy))
	{
		cube->pl.pos.x = newx;
		cube->pl.pos.y = newy;
	}
}

void	render(t_cube *cube)
{
	t_pos	pos;

	pos.x = cube->pl.pos.x + cos(cube->pl.rotationangle) * 60;
	pos.y = cube->pl.pos.y + sin(cube->pl.rotationangle) * 60;
	// draw_minimap(cube);
	draw_circle(cube->mlx, cube->pl.player, cube->pl.radius, cube->pl.pos);
	draw_line(cube->mlx, cube->pl.line, cube->pl.pos, pos);
	// mlx_delete_image(cube->mlx, cube->floor);
	// mlx_delete_image(cube->mlx, cube->wall);
	mlx_delete_image(cube->mlx, cube->pl.line);
	mlx_delete_image(cube->mlx, cube->pl.player);
}