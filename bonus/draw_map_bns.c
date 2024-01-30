/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:02 by acomet            #+#    #+#             */
/*   Updated: 2023/04/25 17:50:40 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map_bns(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map *map)
{
	fill_rotations_values(map);
	dots->x = malloc(sizeof(int *) * map->ordin_count);
	dots->y = malloc(sizeof(int *) * map->ordin_count);
	duplic->x = malloc(sizeof(int *) * map->ordin_count);
	duplic->y = malloc(sizeof(int *) * map->ordin_count);
	duplic->z = malloc(sizeof(int *) * map->ordin_count);
	if (!dots->x || !dots->y || !duplic->x || !duplic->y || !duplic->z)
		return (1);
	if (allocate_axis_ordin_bonus(dots, duplic, *map))
		return (1);
	draw_str(mlx, dots, *map);
	return (0);
}

int	allocate_axis_ordin_bonus(t_dots *dots, t_dots *duplic, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.ordin_count)
	{
		j = 0;
		allocate_dots_duplic(dots, duplic, map, i);
		if (!dots->x[i] || !dots->y[i]
			|| !duplic->x[i] || !duplic->y[i] || !duplic->z[i])
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

void	allocate_dots_duplic(t_dots *dots, t_dots *duplic, t_map map, int i)
{
	dots->x[i] = malloc(sizeof(int) * map.axis_count);
	dots->y[i] = malloc(sizeof(int) * map.axis_count);
	duplic->x[i] = malloc(sizeof(int) * map.axis_count);
	duplic->y[i] = malloc(sizeof(int) * map.axis_count);
	duplic->z[i] = malloc(sizeof(int) * map.axis_count);
}
