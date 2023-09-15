/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:03:14 by orakib            #+#    #+#             */
/*   Updated: 2023/09/15 22:34:58 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_textpixel(t_cube *cube, t_walls *v, int side)
{
	
}

int	load_pngs(t_cube *cube)
{
	printf("%s\n", cube->p.no);
	printf("%s\n", cube->p.so);
	printf("%s\n", cube->p.ea);
	printf("%s\n", cube->p.we);
	cube->no = mlx_load_png(cube->p.no);
	cube->so = mlx_load_png(cube->p.so);
	cube->ea = mlx_load_png(cube->p.ea);
	cube->we = mlx_load_png(cube->p.we);
	if (!cube->no || !cube->so || !cube->ea || !cube->we)
		return (1);
	return (0);
}
