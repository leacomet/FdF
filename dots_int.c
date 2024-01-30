/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:31:00 by acomet            #+#    #+#             */
/*   Updated: 2023/04/25 16:21:35 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**dots_int(char **dots_str, t_map map)
{
	int	i;
	int	j;
	int	**dots;

	i = 0;
	j = 0;
	if (!map.axis_count || !map.ordin_count)
		return (NULL);
	dots = malloc(sizeof(int *) * (map.ordin_count));
	if (!dots)
		return (NULL);
	while (i < map.ordin_count)
	{
		dots[i] = malloc(sizeof(int) * map.axis_count);
		if (!dots[i])
			return (NULL);
		i++;
	}
	return (fullfill_dots_value(dots_str, dots, map.axis_count));
}

int	**fullfill_dots_value(char **dot_str, int **dots, int axis_count)
{
	int	i;
	int	j;
	int	*next;

	i = 0;
	next = malloc(sizeof(int));
	if (!next)
		return (NULL);
	*next = 0;
	while ((dot_str) && (dot_str[i]))
	{
		j = 0;
		*next = 0;
		while (j < axis_count)
		{
			dots[i][j] = fullfill_dots_atoi(dot_str[i] + *next, next);
			j++;
		}
		i++;
	}
	(void)axis_count;
	free(next);
	return (dots);
}

int	fullfill_dots_atoi(const char *nptr, int *next)
{
	int	i;
	int	neg;
	int	nbr;

	neg = 1;
	nbr = 0;
	i = skip_hex(nptr);
	while (nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+')
		&& (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += (nptr[i] - '0');
		i++;
	}
	*next += i;
	return (nbr * neg);
}

int	skip_hex(const char *nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == ',')
	{
		i++;
		while (nptr[i] && nptr[i] != ' ')
			i++;
	}
	return (i);
}
