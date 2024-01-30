/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:13:31 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:35:55 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mirror(t_fdf *fdf, t_dots *dots, t_dots *duplic, t_map map)
{
	int	i;
	int	j;

	free_and_new_img(&fdf->mlx, dots, duplic, map);
	i = 0;
	while (i < map.ordin_count)
	{
		j = 0;
		if (!dots->x[i] || !dots->y[i] || !dots->z[i])
			free_mlx_dots_bns(&fdf->mlx, dots, duplic, map);
		while (j < map.axis_count)
		{
			dots->x[i][j] *= -1;
			j++;
		}
		i++;
	}
	if (map.x_rotate != 0 || map.y_rotate != 0 || map.z_rotate != 0)
		new_and_rotate(&fdf->mlx, dots, &fdf->duplic, &fdf->map);
	else
		draw_str(&fdf->mlx, dots, map);
}
