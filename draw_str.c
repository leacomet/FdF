/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:13:14 by acomet            #+#    #+#             */
/*   Updated: 2023/04/25 15:23:32 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_str(t_mlx *mlx, t_dots *dots, t_map map)
{
	int		i;
	int		j;
	t_coor	coor;

	i = 0;
	while (i + 1 < map.ordin_count)
	{
		j = 0;
		while (j + 1 < map.axis_count)
		{
			coor = fill_coor(dots->x[i][j], dots->x[i][j + 1], dots->y[i][j],
					dots->y[i][j + 1]);
			parsing_case_bresenham(mlx, &coor);
			coor = fill_coor(dots->x[i][j], dots->x[i + 1][j], dots->y[i][j],
					dots->y[i + 1][j]);
			parsing_case_bresenham(mlx, &coor);
			j++;
		}
		coor = fill_coor(dots->x[i][j], dots->x[i + 1][j], dots->y[i][j],
				dots->y[i + 1][j]);
		parsing_case_bresenham(mlx, &coor);
		i++;
	}
	draw_str_last_axis(mlx, dots, map, i);
	return (0);
}

int	draw_str_last_axis(t_mlx *mlx, t_dots *dots, t_map map, int i)
{
	int		j;
	t_coor	coor;

	j = 0;
	while (j + 1 < map.axis_count)
	{
		coor = fill_coor(dots->x[i][j], dots->x[i][j + 1], dots->y[i][j],
				dots->y[i][j + 1]);
		parsing_case_bresenham(mlx, &coor);
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->data.img, 0, 0);
	return (0);
}

void	parsing_case_bresenham(t_mlx *mlx, t_coor *coor)
{
	int	delta_x;
	int	delta_y;

	if (!point_on_map(*coor))
		return ;
	delta_x = coor->x_1 - coor->x_0;
	delta_y = coor->y_1 - coor->y_0;
	if (delta_x >= 0 && delta_y >= 0 && (abs(delta_x) >= abs(delta_y)))
		bresenham(mlx, coor, 1, 1);
	else if (delta_x >= 0 && delta_y >= 0)
		reverse_bresenham(mlx, coor, 1, 1);
	else if (delta_x < 0 && delta_y >= 0 && (abs(delta_x) >= abs(delta_y)))
		bresenham(mlx, coor, -1, 1);
	else if (delta_x < 0 && delta_y >= 0)
		reverse_bresenham(mlx, coor, -1, 1);
	else if (delta_x >= 0 && delta_y < 0 && (abs(delta_x) >= abs(delta_y)))
		bresenham(mlx, coor, 1, -1);
	else if (delta_x >= 0 && delta_y < 0)
		reverse_bresenham(mlx, coor, 1, -1);
	else if (delta_x < 0 && delta_y < 0 && (abs(delta_x) >= abs(delta_y)))
		bresenham(mlx, coor, -1, -1);
	else
		reverse_bresenham(mlx, coor, -1, -1);
}

void	bresenham(t_mlx *mlx, t_coor *coor, int x_neg, int y_neg)
{
	int	delta_x;
	int	delta_y;
	int	pk;

	delta_x = abs(coor->x_1 - coor->x_0);
	delta_y = abs(coor->y_1 - coor->y_0);
	pk = (2 * delta_y) - delta_x;
	while (coor->x_0 != coor->x_1)
	{
		coor->x_0 += x_neg;
		if (pk < 0)
		{
			pk += 2 * delta_y;
			if (coor_on_map(coor->x_0, coor->y_0))
				fdf_pixel_put(&mlx->data, coor->x_0, coor->y_0, 0xFFFFFF);
		}
		else
		{
			pk += 2 * delta_y - 2 * delta_x;
			coor->y_0 += y_neg;
			if (coor_on_map(coor->x_0, coor->y_0))
				fdf_pixel_put(&mlx->data, coor->x_0, coor->y_0, 0xFFFFFF);
		}
	}
}

void	reverse_bresenham(t_mlx *mlx, t_coor *coor, int x_neg, int y_neg)
{
	int	delta_x;
	int	delta_y;
	int	pk;

	delta_x = abs(coor->x_1 - coor->x_0);
	delta_y = abs(coor->y_1 - coor->y_0);
	pk = (2 * delta_x) - delta_y;
	while (coor->y_0 != coor->y_1)
	{
		coor->y_0 += y_neg;
		if (pk < 0)
		{
			pk += 2 * delta_x;
			if (coor_on_map(coor->x_0, coor->y_0))
				fdf_pixel_put(&mlx->data, coor->x_0, coor->y_0, 0xFFFFFF);
		}
		else
		{
			pk += 2 * delta_x - 2 * delta_y;
			coor->x_0 += x_neg;
			if (coor_on_map(coor->x_0, coor->y_0))
				fdf_pixel_put(&mlx->data, coor->x_0, coor->y_0, 0xFFFFFF);
		}
	}
}
