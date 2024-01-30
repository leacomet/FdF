/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:02 by acomet            #+#    #+#             */
/*   Updated: 2023/04/25 17:20:33 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map(t_mlx *mlx, t_dots *dots, t_map map)
{
	dots->x = malloc(sizeof(int *) * map.ordin_count);
	dots->y = malloc(sizeof(int *) * map.ordin_count);
	if (!dots->x || !dots->y)
		return (1);
	if (allocate_axis_ordin(dots, map))
		return (1);
	return (draw_str(mlx, dots, map));
}

int	allocate_axis_ordin(t_dots *dots, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.ordin_count)
	{
		j = 0;
		dots->x[i] = malloc(sizeof(int) * map.axis_count);
		dots->y[i] = malloc(sizeof(int) * map.axis_count);
		if (!dots->x[i] || !dots->y[i])
			return (1);
		while (j < map.axis_count)
		{
			dots->x[i][j] = ((j - i) * 20)
				- ((map.axis_count - map.ordin_count) * 10);
			dots->y[i][j] = ((i + j) * 10)
				- (map.ordin_count * 10) - dots->z[i][j];
			j++;
		}
		i++;
	}
	return (0);
}
