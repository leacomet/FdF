/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:16:37 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:43:24 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx_dots_bns(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map map)
{
	free_mlx(mlx);
	free_dots(dots, map);
	free_dots(duplic, map);
	exit (1);
}

int	close_free_bns(t_fdf *fdf)
{
	free_dots(&fdf->duplic, fdf->map);
	free_dots(&fdf->dots, fdf->map);
	free_mlx(&fdf->mlx);
	exit(1);
}

void	free_and_new_img(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map map)
{
	mlx_destroy_image(mlx->mlx, mlx->data.img);
	mlx->data.img = mlx_new_image(mlx->mlx, 1500, 900);
	if (!mlx->data.img || !dots->x || !dots->y || !dots->z
		|| !duplic->x || !duplic->y || !duplic->z)
	{
		ft_printferr("Error\n");
		free_mlx_dots_bns(mlx, dots, duplic, map);
	}
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,
			&mlx->data.line_length, &mlx->data.endian);
	if (!mlx->data.addr)
	{
		ft_printferr("Error\n");
		free_mlx_dots_bns(mlx, dots, duplic, map);
	}
}
