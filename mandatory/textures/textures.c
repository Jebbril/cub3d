/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:03:14 by orakib            #+#    #+#             */
/*   Updated: 2023/09/17 19:51:01 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	**convert_texture_to_color_array(mlx_texture_t *image)
{
	int	**tab;
	int	count;
	int	i;
	int	j;

	tab = malloc(sizeof(int *) * (image->height + 1));
	tab[image->height] = 0;
	count = 0;
	i = -1;
	while (++i < (int)image->height)
	{
		tab[i] = malloc(sizeof(int) * (image->width + 1));
		tab[i][image->width] = 0;
		j = -1;
		while (++j < (int)image->width)
		{
			tab[i][j] = ft_pixel(
					image->pixels[count + 0],
					image->pixels[count + 1],
					image->pixels[count + 2],
					image->pixels[count + 3]);
			count += 4;
		}
	}
	return (tab);
}

uint32_t	get_textpixel(t_cube *cube, t_walls *v, int side)
{
	int			text_x;
	int			text_y;

	if (cube->rays[v->i].washitvertical)
		text_x = (int)((cube->rays[v->i].wallhity / TILE_SIZE)
				* cube->no->width) % cube->no->width;
	else
		text_x = (int)((cube->rays[v->i].wallhitx * cube->no->width)
				/ TILE_SIZE) % cube->no->width;
	text_y = v->y + (v->wallstrip_height / 2) - (W_HEIGHT / 2);
	text_y = text_y * ((double)cube->no->height / v->wallstrip_height);
	if (text_y == 64)
		text_y = 63;
	if (side == 1)
		return (cube->no_tab[text_y][text_x]);
	else if (side == 2)
		return (cube->so_tab[text_y][text_x]);
	else if (side == 3)
		return (cube->ea_tab[text_y][text_x]);
	else if (side == 4)
		return (cube->we_tab[text_y][text_x]);
	return (0);
}

int	load_pngs(t_cube *cube)
{
	cube->no = mlx_load_png(cube->p.no);
	cube->so = mlx_load_png(cube->p.so);
	cube->ea = mlx_load_png(cube->p.ea);
	cube->we = mlx_load_png(cube->p.we);
	if (!cube->no || !cube->so || !cube->ea || !cube->we)
		return (1);
	cube->no_tab = convert_texture_to_color_array(cube->no);
	cube->so_tab = convert_texture_to_color_array(cube->so);
	cube->ea_tab = convert_texture_to_color_array(cube->ea);
	cube->we_tab = convert_texture_to_color_array(cube->we);
	return (0);
}
