/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_modified.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:11:29 by acomet            #+#    #+#             */
/*   Updated: 2023/02/16 15:57:57 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	fdf_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

char	*fdf_join_with_sep(char *str, char *buffer)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char)
			* (fdf_strlen(str) + fdf_strlen(buffer) + 1));
	if (!new_str)
		return (NULL);
	i = fdf_strcpy(new_str + i, str);
	i = fdf_strcpy(new_str + i, buffer);
	if (str)
		free(str);
	free(buffer);
	return (new_str);
}
