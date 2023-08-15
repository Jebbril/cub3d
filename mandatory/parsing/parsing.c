/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:23:39 by orakib            #+#    #+#             */
/*   Updated: 2023/08/15 18:37:21 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_fd(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		write(2, "Error\nProgram takes one argument !\n", 36);
		exit(EXIT_FAILURE);
	}
	if (check_ext(av[1], ".cub"))
	{
		write(2, "Error\nWrong extension\n", 23);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(errno);
	}
	return (fd);
}

char	*maptostr(int fd)
{
	char	*str;
	char	*line;

	str = get_next_line(fd);
	if (!str)
	{
		perror("Error\n");
		exit (errno);
	}
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin2(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

void	parsing(int ac, char **av, t_cube *cube)
{
	int	fd;

	fd = get_fd(ac, av);
	cube->mapstr = maptostr(fd);
	cube->map = NULL;
	cube->map = ft_split(cube->mapstr, '\n');
	get_info(cube);
	get_map(cube);
	parse_map(cube);
}
