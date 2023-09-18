/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:39:18 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 19:31:07 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_ccolors(t_cube *cube)
{
	return (cube->p.c_red << 24
		| cube->p.c_green << 16 | cube->p.c_blue << 8 | 0xFF);
}

int	get_fcolors(t_cube *cube)
{
	return (cube->p.f_red << 24
		| cube->p.f_green << 16 | cube->p.f_blue << 8 | 0xFF);
}

int	draw_background(t_cube *cube)
{
	int	i;
	int	j;

	cube->background = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	if (!cube->background)
		return (1);
	i = -1;
	j = -1;
	while (++i < W_WIDTH)
	{
		while (++j < W_HEIGHT / 2)
			mlx_put_pixel(cube->background, i, j, get_fcolors(cube));
		j--;
		while (++j < W_HEIGHT)
			mlx_put_pixel(cube->background, i, j, get_ccolors(cube));
		j = -1;
	}
	mlx_image_to_window(cube->mlx, cube->background, 0, 0);
	return (0);
}
