/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:06:47 by acomet            #+#    #+#             */
/*   Updated: 2023/04/21 15:19:36 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**dots_str_to_double_tab(char *map_name)
{
	int		fd;
	char	*buffer;
	char	*str;
	char	**dots;

	fd = open(map_name, O_RDONLY);
	free(map_name);
	buffer = get_next_line(fd);
	str = NULL;
	while (buffer)
	{
		str = fdf_join_with_sep(str, buffer);
		if (!str)
		{
			free(buffer);
			buffer = get_next_line(-1);
			return (dots_str_free_and_close(fd, buffer, str));
		}
		buffer = get_next_line(fd);
	}
	dots = ft_split(str, '\n');
	dots_str_free_and_close(fd, buffer, str);
	return (dots);
}

char	**dots_str_free_and_close(int fd, char *buffer, char *str)
{
	if (buffer)
		free(buffer);
	close(fd);
	if (str)
		free(str);
	return (NULL);
}
