/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rotations_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:41:51 by acomet            #+#    #+#             */
/*   Updated: 2023/02/27 17:42:04 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_rotations_values(t_map *map)
{
	map->x_rotate = 0;
	map->y_rotate = 0;
	map->z_rotate = 0;
	map->mirror = 1;
}

void	modify_rotations_values(t_map *map)
{
	map->x_rotate %= 12;
	map->y_rotate %= 12;
	map->z_rotate %= 12;
}
