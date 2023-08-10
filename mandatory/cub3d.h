/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:41:03 by orakib            #+#    #+#             */
/*   Updated: 2023/08/10 17:09:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"

typedef struct s_cube // struct that i will use to store all the necessary data
{
	char	*mapstr; // map file content put into a string;
	char	**map; // i will split the map to lines so i can get a 2d array of map elements
}	t_cube;

// parsing
void	parsing(int ac, char **av, t_cube *cube);
int	check_ext(char *str);

#endif