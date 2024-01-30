/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:11:09 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:33:26 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotations(t_fdf *fdf, int key)
{
	if (key == 'd' || key == 'a')
	{
		if (key == 'd')
			fdf->map.z_rotate--;
		else
			fdf->map.z_rotate++;
		new_and_rotate(&fdf->mlx, &fdf->dots, &fdf->duplic, &fdf->map);
	}
	else if (key == 'e' || key == 'q')
	{
		if (key == 'e')
			fdf->map.y_rotate--;
		else
			fdf->map.y_rotate++;
		new_and_rotate(&fdf->mlx, &fdf->dots, &fdf->duplic, &fdf->map);
	}
	else if (key == 'w' || key == 's')
	{
		if (key == 'w')
			fdf->map.x_rotate--;
		else
			fdf->map.x_rotate++;
		new_and_rotate(&fdf->mlx, &fdf->dots, &fdf->duplic, &fdf->map);
	}
}

void	new_and_rotate(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map *map)
{
	int	i;
	int	j;

	modify_rotations_values(map);
	free_and_new_img(mlx, dots, duplic, *map);
	i = 0;
	while (i < map->ordin_count)
	{
		j = 0;
		if (!dots->x[i] || !dots->y[i] || !dots->z[i]
			|| !duplic->x[i] || !duplic->y[i] || !duplic->z[i])
			free_mlx_dots_bns(mlx, dots, duplic, *map);
		while (j < map->axis_count)
		{
			set_duplic_to_initial(*dots, duplic, i, j);
			apply_rotate_values(&duplic->x[i][j], &duplic->y[i][j],
				&duplic->z[i][j], map);
			j++;
		}
		i++;
	}
	draw_str(mlx, duplic, *map);
}

void	set_duplic_to_initial(t_dots dots, t_dots *duplic, int i, int j)
{
	duplic->x[i][j] = dots.x[i][j];
	duplic->y[i][j] = dots.y[i][j];
	duplic->z[i][j] = dots.z[i][j];
}

void	apply_rotate_values(int *x, int *y, int *z, t_map *map)
{
	if (map->z_rotate)
	{
		map->temp = *x;
		*x = map->temp * cos(map->z_rotate * 30 * M_PI / 180)
			+ *y * sin(map->z_rotate * 30 * M_PI / 180);
		*y = -map->temp * sin(map->z_rotate * 30 * M_PI / 180)
			+ *y * cos(map->z_rotate * 30 * M_PI / 180);
	}
	if (map->y_rotate)
	{
		map->temp = *x;
		*x = map->temp * cos(map->y_rotate * 30 * M_PI / 180)
			- *z * sin(map->y_rotate * 30 * M_PI / 180);
		*z = map->temp * sin(map->y_rotate * 30 * M_PI / 180)
			+ *z * cos(map->y_rotate * 30 * M_PI / 180);
	}
	if (map->x_rotate)
	{
		map->temp = *y;
		*y = map->temp * cos(map->x_rotate * 30 * M_PI / 180)
			+ *z * sin(map->x_rotate * 30 * M_PI / 180);
		*z = -map->temp * sin(map->x_rotate * 30 * M_PI / 180)
			+ *z * cos(map->x_rotate * 30 * M_PI / 180);
	}
}
