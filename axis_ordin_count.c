/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_ordin_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:20:36 by acomet            #+#    #+#             */
/*   Updated: 2023/04/21 15:25:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	how_many_axis_arg(char **dots_str, int i, int j)
{
	if (dots_str && (dots_str[0][0] >= '0') && (dots_str[0][0] <= '9'))
		i++;
	while (dots_str && dots_str[0][j])
	{
		if ((dots_str[0][j] != ' ') && (dots_str[0][j - 1] == ' '))
			i++;
		j++;
	}
	return (i);
}

int	how_many_ordin_arg(char **dots_str, int i, int j)
{
	while (dots_str && dots_str[i])
	{
		while (dots_str[i][j])
		{
			if ((dots_str[i][j] >= '0') && (dots_str[i][j] <= '9'))
				break ;
			j++;
		}
		if ((dots_str[i][j] < '0') || (dots_str[i][j] > '9'))
			break ;
		i++;
	}
	return (i);
}
