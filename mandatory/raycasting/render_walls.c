/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:03:08 by orakib            #+#    #+#             */
/*   Updated: 2023/09/25 20:38:07 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_values(t_cube *cube, t_walls *v)
{
	v->correct_dist = cube->rays[v->i].distance
		* cos(cube->rays[v->i].rayangle - cube->pl.rotationangle);
	v->dist_projplane = (W_WIDTH / 2) / tan(cube->fov / 2);
	v->projwall_height = (TILE_SIZE / v->correct_dist) * v->dist_projplane;
	v->wallstrip_height = (int)v->projwall_height;
	v->walltop_pixel = (W_HEIGHT / 2) - (v->wallstrip_height / 2);
	if (v->walltop_pixel < 0)
		v->walltop_pixel = 0;
	v->wallbottom_pixel = (W_HEIGHT / 2) + (v->wallstrip_height / 2);
	if (v->wallbottom_pixel > W_HEIGHT)
		v->wallbottom_pixel = W_HEIGHT;
	v->y = v->walltop_pixel;
}

void	render_walls(t_cube *cube)
{
	t_walls	v;

	v.i = -1;
	while (++v.i < NUM_RAYS)
	{
		init_values(cube, &v);
		while (v.y++ < v.wallbottom_pixel)
		{
			if (cube->rays[v.i].israyfacingup
				&& !cube->rays[v.i].washitvertical)
				my_put_pixel(cube, v.i, v.y, get_textpixel_no(cube, &v));
			else if (cube->rays[v.i].israyfacingdown
				&& !cube->rays[v.i].washitvertical)
				my_put_pixel(cube, v.i, v.y, get_textpixel_so(cube, &v));
			else if (cube->rays[v.i].israyfacingright
				&& cube->rays[v.i].washitvertical)
				my_put_pixel(cube, v.i, v.y, get_textpixel_ea(cube, &v));
			else if (cube->rays[v.i].israyfacingleft
				&& cube->rays[v.i].washitvertical)
				my_put_pixel(cube, v.i, v.y, get_textpixel_we(cube, &v));
		}
	}
}
