/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:57:05 by orakib            #+#    #+#             */
/*   Updated: 2023/09/17 21:56:30 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_dist(t_cube *cube, t_cast *v, int i)
{
	if (v->foundhwallhit)
		v->hhitdist = distancexy(cube->pl.pos.x, cube->pl.pos.y,
				v->hwallhitx, v->hwallhity);
	else
		v->hhitdist = MAXFLOAT;
	if (v->foundvwallhit)
		v->vhitdist = distancexy(cube->pl.pos.x, cube->pl.pos.y,
				v->vwallhitx, v->vwallhity);
	else
		v->vhitdist = MAXFLOAT;
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

void	render_rays(t_cube *cube)
{
	int		i;
	t_pos	p;

	i = -1;
	while (++i < NUM_RAYS)
	{
		p.x = cube->rays[i].wallhitx;
		p.y = cube->rays[i].wallhity;
		draw_line(cube, 0xFF0000FF, cube->pl.pos, p);
	}
}
