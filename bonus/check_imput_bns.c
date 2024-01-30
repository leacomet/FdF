/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_imput_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:06:48 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:11:52 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_keycode_bns(t_fdf *fdf, int key)
{
	if (key == 65307)
	{
		free_dots(&fdf->duplic, fdf->map);
		free_dots(&fdf->dots, fdf->map);
		free_mlx(&fdf->mlx);
		exit (1);
	}
	else if (key == 'a' || key == 'd' || key == 'e'
		|| key == 'q' || key == 's' || key == 'w')
		rotations(fdf, key);
	else if (key == XK_Up || key == XK_Down
		|| key == XK_Right || key == XK_Left)
		translations(fdf, key);
	else if (key == 'p')
		mirror(fdf, &fdf->dots, &fdf->duplic, fdf->map);
	return (1);
}
