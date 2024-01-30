/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_imput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:06:48 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:53:28 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_keycode(t_fdf *fdf, int key)
{
	if (key == 65307)
	{
		free_dots(&fdf->dots, fdf->map);
		free_mlx(&fdf->mlx);
		exit (1);
	}
	return (1);
}
