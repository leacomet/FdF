/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:52:00 by acomet            #+#    #+#             */
/*   Updated: 2023/05/04 19:55:03 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_dots_str(char **dots_str)
{
	int	i;

	i = 0;
	while (dots_str[i])
	{
		free(dots_str[i]);
		i++;
	}
	free(dots_str);
}

int	free_dots(t_dots *dots, t_map map)
{
	int	i;

	i = 0;
	while (i < map.ordin_count)
	{
		if (dots->x && dots->x[i])
			free(dots->x[i]);
		if (dots->y && dots->y[i])
			free(dots->y[i]);
		if (dots->z && dots->z[i])
			free(dots->z[i]);
		i++;
	}
	if (dots->x)
		free(dots->x);
	if (dots->y)
		free(dots->y);
	if (dots->z)
		free(dots->z);
	return (1);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->data.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

int	free_dots_mlx(t_fdf *fdf, t_dots *dots, t_map map)
{
	free_mlx(&fdf->mlx);
	return (free_dots(dots, map));
}

int	close_free(t_fdf *fdf)
{
	free_dots(&fdf->dots, fdf->map);
	free_mlx(&fdf->mlx);
	exit(1);
}
