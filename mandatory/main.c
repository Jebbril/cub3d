/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:40:49 by orakib            #+#    #+#             */
/*   Updated: 2023/08/28 15:30:30 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void leaks(){system("leaks cub3d");}
int	main(int ac, char **av)
{
	t_cube	cube;


	parsing(ac, av, &cube);
	raycasting(&cube);
	garbage(&cube);
	atexit(leaks);
}
