/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:40:49 by orakib            #+#    #+#             */
/*   Updated: 2023/09/18 20:28:54 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	cube.no = NULL;
	cube.so = NULL;
	cube.ea = NULL;
	cube.we = NULL;
	cube.no_tab = NULL;
	cube.so_tab = NULL;
	cube.ea_tab = NULL;
	cube.we_tab = NULL;
	cube.state = MLX_MOUSE_NORMAL;
	parsing(ac, av, &cube);
	raycasting(&cube);
	garbage(&cube);
}
