/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:10:15 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/09/28 16:03:59 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	get_textpixel_no(t_cube *cube, t_walls *v)
{
	int			text_x;
	int			text_y;

	if (cube->rays[v->i].washitvertical)
		text_x = fmod(cube->rays[v->i].wallhity, TILE_SIZE)
			* cube->no->width / TILE_SIZE;
	else
		text_x = fmod(cube->rays[v->i].wallhitx, TILE_SIZE)
			* cube->no->width / TILE_SIZE;
	text_y = v->y + (v->wallstrip_height / 2) - (W_HEIGHT / 2);
	text_y = text_y * ((double)cube->no->height / v->wallstrip_height);
	if (text_y >= (int)cube->no->height)
		text_y = cube->no->height - 1;
	return (cube->no_tab[text_y][text_x]);
	return (0);
}

uint32_t	get_textpixel_so(t_cube *cube, t_walls *v)
{
	int			text_x;
	int			text_y;

	if (cube->rays[v->i].washitvertical)
		text_x = fmod(cube->rays[v->i].wallhity, TILE_SIZE)
			* cube->so->width / TILE_SIZE;
	else
		text_x = fmod(cube->rays[v->i].wallhitx, TILE_SIZE)
			* cube->so->width / TILE_SIZE;
	text_y = v->y + (v->wallstrip_height / 2) - (W_HEIGHT / 2);
	text_y = text_y * ((double)cube->so->height / v->wallstrip_height);
	if (text_y >= (int)cube->so->height)
		text_y = cube->so->height - 1;
	return (cube->so_tab[text_y][text_x]);
	return (0);
}

uint32_t	get_textpixel_ea(t_cube *cube, t_walls *v)
{
	int			text_x;
	int			text_y;

	if (cube->rays[v->i].washitvertical)
		text_x = fmod(cube->rays[v->i].wallhity, TILE_SIZE)
			* cube->ea->width / TILE_SIZE;
	else
		text_x = fmod(cube->rays[v->i].wallhitx, TILE_SIZE)
			* cube->ea->width / TILE_SIZE;
	text_y = v->y + (v->wallstrip_height / 2) - (W_HEIGHT / 2);
	text_y = text_y * ((double)cube->ea->height / v->wallstrip_height);
	if (text_y >= (int)cube->ea->height)
		text_y = cube->ea->height - 1;
	return (cube->ea_tab[text_y][text_x]);
	return (0);
}

uint32_t	get_textpixel_we(t_cube *cube, t_walls *v)
{
	int			text_x;
	int			text_y;

	if (cube->rays[v->i].washitvertical)
		text_x = fmod(cube->rays[v->i].wallhity, TILE_SIZE)
			* cube->we->width / TILE_SIZE;
	else
		text_x = fmod(cube->rays[v->i].wallhitx, TILE_SIZE)
			* cube->we->width / TILE_SIZE;
	text_y = v->y + (v->wallstrip_height / 2) - (W_HEIGHT / 2);
	text_y = text_y * ((double)cube->we->height / v->wallstrip_height);
	if (text_y >= (int)cube->we->height)
		text_y = cube->we->height - 1;
	return (cube->we_tab[text_y][text_x]);
	return (0);
}
