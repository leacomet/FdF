/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:49 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:30:24 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translations(t_fdf *fdf, int key)
{
	if (key == 65361)
		translate_axis(fdf, &fdf->dots, fdf->map, -1);
	else if (key == 65363)
		translate_axis(fdf, &fdf->dots, fdf->map, 1);
	else if (key == 65364)
		translate_ordin(fdf, &fdf->dots, fdf->map, 1);
	else if (key == 65362)
		translate_ordin(fdf, &fdf->dots, fdf->map, -1);
}

void	translate_axis(t_fdf *fdf, t_dots *dots, t_map map, int neg)
{
	int	i;
	int	j;

	free_and_new_img(&fdf->mlx, dots, &fdf->duplic, map);
	i = 0;
	while (i < map.ordin_count)
	{
		j = 0;
		if (!dots->x[i] || !dots->y[i] || !dots->z[i])
			free_mlx_dots_bns(&fdf->mlx, dots, &fdf->duplic, map);
		while (j < map.axis_count)
		{
			dots->x[i][j] += 15 * neg;
			j++;
		}
		i++;
	}
	if (map.x_rotate != 0 || map.y_rotate != 0 || map.z_rotate != 0)
		new_and_rotate(&fdf->mlx, dots, &fdf->duplic, &fdf->map);
	else
		draw_str(&fdf->mlx, dots, map);
}

void	translate_ordin(t_fdf *fdf, t_dots *dots, t_map map, int neg)
{
	int	i;
	int	j;

	free_and_new_img(&fdf->mlx, dots, &fdf->duplic, map);
	i = 0;
	while (i < map.ordin_count)
	{
		j = 0;
		if (!dots->x[i] || !dots->y[i] || !dots->z[i])
			free_mlx_dots_bns(&fdf->mlx, dots, &fdf->duplic, map);
		while (j < map.axis_count)
		{
			dots->y[i][j] += 15 * neg;
			j++;
		}
		i++;
	}
	if (map.x_rotate != 0 || map.y_rotate != 0 || map.z_rotate != 0)
		new_and_rotate(&fdf->mlx, dots, &fdf->duplic, &fdf->map);
	else
		draw_str(&fdf->mlx, dots, map);
}
