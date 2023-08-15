/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:42:46 by orakib            #+#    #+#             */
/*   Updated: 2023/08/15 18:37:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_ext(char *str, char *ext)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(str);
	if (str[len - i])
		if (str[len - i] == ext[3])
			i++;
	if (str[len - i])
		if (str[len - i] == ext[2])
			i++;
	if (str[len - i])
		if (str[len - i] == ext[1])
			i++;
	if (str[len - i])
		if (str[len - i] == ext[0])
			i++;
	if (i == 5 && i <= len)
		return (0);
	return (1);
}
