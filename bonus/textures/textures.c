/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:04:51 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/09/29 15:04:53 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_colorarray2(mlx_texture_t *image, int **tab, int *i)
{
	int	j;
	int	count;

	count = 0;
	while (++(*i) < (int)image->height)
	{
		tab[*i] = malloc(sizeof(int) * (image->width + 1));
		if (!tab[*i])
			return (1);
		tab[*i][image->width] = 0;
		j = -1;
		while (++j < (int)image->width)
		{
			tab[*i][j] = ft_pixel(
					image->pixels[count + 0],
					image->pixels[count + 1],
					image->pixels[count + 2],
					image->pixels[count + 3]);
			count += 4;
		}
	}
	return (0);
}

int	**get_colorarray(mlx_texture_t *image)
{
	int	**tab;
	int	count;
	int	i;

	tab = malloc(sizeof(int *) * (image->height + 1));
	if (!tab)
		return (NULL);
	tab[image->height] = 0;
	count = 0;
	i = -1;
	if (get_colorarray2(image, tab, &i))
	{
		free_matrix2(tab);
		return (NULL);
	}
	return (tab);
}

int	load_pngs(t_cube *cube)
{
	cube->no = mlx_load_png(cube->p.no);
	cube->so = mlx_load_png(cube->p.so);
	cube->ea = mlx_load_png(cube->p.ea);
	cube->we = mlx_load_png(cube->p.we);
	if (!cube->no || !cube->so || !cube->ea || !cube->we)
		return (1);
	cube->no_tab = get_colorarray(cube->no);
	cube->so_tab = get_colorarray(cube->so);
	cube->ea_tab = get_colorarray(cube->ea);
	cube->we_tab = get_colorarray(cube->we);
	return (0);
}
