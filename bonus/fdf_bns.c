/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:27:00 by acomet            #+#    #+#             */
/*   Updated: 2023/04/25 18:21:37 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key_bns(int key, t_fdf *fdf)
{
	check_keycode_bns(fdf, key);
	return (0);
}

int	fdf_bns(char *map_name, t_fdf *fdf, t_data *data)
{
	char	**dots_str;

	dots_str = dots_str_to_double_tab(map_name);
	if (!dots_str)
		return (ft_printferr("no map\n"));
	fdf->map.axis_count = how_many_axis_arg(dots_str, 0, 1);
	fdf->map.ordin_count = how_many_ordin_arg(dots_str, 0, 0);
	fdf->dots.z = dots_int(dots_str, fdf->map);
	free_dots_str(dots_str);
	if (!fdf->dots.z || initialize_mlx_bns(fdf, data))
		return (ft_printferr("Error\n"));
	if (draw_map_bns(&fdf->mlx, &fdf->dots, &fdf->duplic, &fdf->map))
	{
		free_dots(&fdf->dots, fdf->map);
		return (free_dots(&fdf->duplic, fdf->map));
	}
	mlx_key_hook(fdf->mlx.win, deal_key_bns, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, close_free_bns, fdf);
	mlx_loop(fdf->mlx.mlx);
	return (0);
}

int	initialize_mlx_bns(t_fdf *fdf, t_data *data)
{
	fdf->mlx.mlx = mlx_init();
	if (!fdf->mlx.mlx)
		return (free_dots_mlx(fdf, &fdf->dots, fdf->map));
	fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, 1500, 900, "mlx_42");
	data->img = mlx_new_image(fdf->mlx.mlx, 1500, 900);
	if (!fdf->mlx.win || !data->img)
		return (free_dots_mlx(fdf, &fdf->dots, fdf->map));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (free_dots_mlx(fdf, &fdf->dots, fdf->map));
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*map_name;
	t_fdf	fdf_struct;

	i = 0;
	map_name = NULL;
	if (argc != 2)
		return (write(2, "wrong arguments\n", 16));
	map_name = ft_strdup(argv[1]);
	fdf_bns(map_name, &fdf_struct, &fdf_struct.mlx.data);
	return (0);
}
