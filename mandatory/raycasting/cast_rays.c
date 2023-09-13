/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:55 by orakib            #+#    #+#             */
/*   Updated: 2023/09/13 21:32:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horiz_intersection2(t_cube *cube, t_cast *v, int i)
{
	while (v->nexthtouchx >= 0 && v->nexthtouchx <= W_WIDTH
		&& v->nexthtouchy >= 0 && v->nexthtouchy <= W_HEIGHT)
	{
		if (has_wall(cube, v->nexthtouchx, v->nexthtouchy
				- cube->rays[i].israyfacingup))
		{
			v->foundhwallhit = TRUE;
			v->hwallhitx = v->nexthtouchx;
			v->hwallhity = v->nexthtouchy;
			break ;
		}
		else
		{
			v->nexthtouchx += v->xstep;
			v->nexthtouchy += v->ystep;
		}
	}
}

void	horiz_intersection(t_cube *cube, t_cast *v, int i)
{
	v->foundhwallhit = FALSE;
	v->hwallhitx = 0;
	v->hwallhity = 0;
	v->yintercept = floor(cube->pl.pos.y / TILE_SIZE) * TILE_SIZE;
	if (cube->rays[i].israyfacingdown)
		v->yintercept += TILE_SIZE;
	v->xintercept = cube->pl.pos.x + (v->yintercept - cube->pl.pos.y)
		/ tan(cube->rays[i].rayangle);
	v->ystep = TILE_SIZE;
	if (cube->rays[i].israyfacingup)
		v->ystep *= -1;
	v->xstep = TILE_SIZE / tan(cube->rays[i].rayangle);
	if (cube->rays[i].israyfacingleft && v->xstep > 0)
		v->xstep *= -1;
	if (cube->rays[i].israyfacingright && v->xstep < 0)
		v->xstep *= -1;
	v->nexthtouchx = v->xintercept;
	v->nexthtouchy = v->yintercept;
	horiz_intersection2(cube, v, i);
}

void	verti_intersection2(t_cube *cube, t_cast *v, int i)
{
	while (v->nextvtouchx >= 0 && v->nextvtouchx <= W_WIDTH
		&& v->nextvtouchy >= 0 && v->nextvtouchy <= W_HEIGHT)
	{
		if (has_wall(cube, v->nextvtouchx - cube->rays[i].israyfacingleft
				, v->nextvtouchy))
		{
			v->foundvwallhit = TRUE;
			v->vwallhitx = v->nextvtouchx;
			v->vwallhity = v->nextvtouchy;
			break ;
		}
		else
		{
			v->nextvtouchx += v->xstep;
			v->nextvtouchy += v->ystep;
		}
	}
}

void	verti_intersection(t_cube *cube, t_cast *v, int i)
{
	v->foundvwallhit = FALSE;
	v->vwallhitx = 0;
	v->vwallhity = 0;
	v->xintercept = floor(cube->pl.pos.x / TILE_SIZE) * TILE_SIZE;
	if (cube->rays->israyfacingright)
		v->xintercept += TILE_SIZE;
	v->yintercept = cube->pl.pos.y + (v->xintercept - cube->pl.pos.x)
		* tan(cube->rays[i].rayangle);
	v->xstep = TILE_SIZE;
	if (cube->rays[i].israyfacingleft)
		v->xstep *= -1;
	v->ystep = TILE_SIZE * tan(cube->rays[i].rayangle);
	if (cube->rays[i].israyfacingup && v->ystep > 0)
		v->ystep *= -1;
	if (cube->rays[i].israyfacingdown && v->ystep < 0)
		v->ystep *= -1;
	v->nextvtouchx = v->xintercept;
	v->nextvtouchy = v->yintercept;
	verti_intersection2(cube, v, i);
}

void	choose_dist(t_cube *cube, t_cast *v, int i)
{
	if (v->foundhwallhit)
		v->hhitdist = distancexy(cube->pl.pos.x, cube->pl.pos.y,
				v->hwallhitx, v->hwallhity);
	else
		v->hhitdist = INT_MAX;
	if (v->foundvwallhit)
		v->vhitdist = distancexy(cube->pl.pos.x, cube->pl.pos.y,
				v->vwallhitx, v->vwallhity);
	else
		v->hhitdist = INT_MAX;
	if (v->vhitdist < v->hhitdist)
	{
		cube->rays[i].wallhitx = v->vwallhitx;
		cube->rays[i].wallhity = v->vwallhity;
		cube->rays[i].distance = v->vhitdist;
		cube->rays[i].washitvertical = TRUE;
	}
	else
	{
		cube->rays[i].wallhitx = v->hwallhitx;
		cube->rays[i].wallhity = v->hwallhity;
		cube->rays[i].distance = v->hhitdist;
		cube->rays[i].washitvertical = FALSE;
	}
}

void	render_ray(t_cube *cube, int i)
{
	t_pos	p;

	p.x = cube->rays[i].wallhitx;
	p.y = cube->rays[i].wallhity;
	draw_line(cube, 0xFF0000FF, cube->pl.pos, p);
}

void	cast_rays(t_cube *cube)
{
	int		i;
	t_cast	v;
	float	rayangle;
	float	inc;

	i = -1;
	rayangle = cube->pl.rotationangle - (cube->fov / 2);
	inc = cube->fov / (float)NUM_RAYS;
	while (++i < NUM_RAYS)
	{
		init_ray(cube, i, rayangle);
		horiz_intersection(cube, &v, i);
		verti_intersection(cube, &v, i);
		choose_dist(cube, &v, i);
		render_ray(cube, i);
		rayangle += inc;
	}
}
