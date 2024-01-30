/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:30:01 by acomet            #+#    #+#             */
/*   Updated: 2023/04/26 13:25:59 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "math.h"
# include "ft_printferr/ft_printferr.h"

	/* get next line */
# include "gnl/get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	data;
}	t_mlx;

typedef struct s_dots
{
	int	**x;
	int	**y;
	int	**z;
}	t_dots;

typedef struct s_map
{
	int	axis_count;
	int	ordin_count;
	int	x_rotate;
	int	y_rotate;
	int	z_rotate;
	int	mirror;
	int	temp;
}	t_map;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_dots	dots;
	t_map	map;
	t_dots	duplic;
}	t_fdf;

typedef struct s_coor
{
	int	x_0;
	int	x_1;
	int	y_0;
	int	y_1;
}	t_coor;

	/* main */
int		initialize_mlx(t_fdf *fdf, t_data *data);

	/* dots str */
char	**dots_str_to_double_tab(char *map_name);
char	**dots_str_free_and_close(int fd, char *buffer, char *str);

	/* axis ordin count */
int		how_many_axis_arg(char **dots_str, int i, int j);
int		how_many_ordin_arg(char **dots_str, int i, int j);

	/* dots int	*/
int		**dots_int(char **dots_str, t_map map);
int		**fullfill_dots_value(char **dots_str, int **dots, int axis_count);
int		fullfill_dots_atoi(const char *nptr, int *next);
int		skip_hex(const char *nptr);

	/* libft_modified */
char	*fdf_join_with_sep(char *str, char *buffer);
int		fdf_strcpy(char *dst, char *src);
int		fdf_strlen(char *str);

	/* draw map */
int		draw_map(t_mlx *mlx, t_dots *dots, t_map map);
int		allocate_axis_ordin(t_dots *dots, t_map map);

	/* draw_str */
int		draw_str(t_mlx *mlx, t_dots *dots, t_map map);
int		draw_str_last_axis(t_mlx *mlx, t_dots *dots, t_map map, int i);
t_coor	fill_coor(int x_0, int x_1, int y_0, int y_1);
int		point_on_map(t_coor coor);
void	parsing_case_bresenham(t_mlx *mlx, t_coor *coor);
void	bresenham(t_mlx *mlx, t_coor *coor, int x_neg, int y_neg);
void	reverse_bresenham(t_mlx *mlx, t_coor *coor, int x_neg, int y_neg);
int		coor_on_map(int x, int y);

	/* fdf pixel put */
void	fdf_pixel_put(t_data *data, int x, int y, int color);

	/* check key */
int		check_keycode(t_fdf *fdf, int key);

	/* free */
void	free_dots_str(char **dots_str);
int		free_dots(t_dots *dots, t_map map);
void	free_mlx(t_mlx *mlx);
int		free_dots_mlx(t_fdf *fdf, t_dots *dots, t_map map);
int		close_free(t_fdf *fdf);

		/* BONUS */

	/* main */
int		initialize_mlx_bns(t_fdf *fdf, t_data *data);

	/* draw str bonus */
int		draw_map_bns(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map *map);
int		allocate_axis_ordin_bonus(t_dots *dots, t_dots *duplic, t_map map);
void	allocate_dots_duplic(t_dots *dots, t_dots *duplic, t_map map, int i);

	/* check key bonus */
int		check_keycode_bns(t_fdf *fdf, int key);

	/* tramsformations */
void	transformations(t_fdf *fdf);

	/* rotations */
void	rotations(t_fdf *fdf, int key);
void	fill_rotations_values(t_map *map);
void	new_and_rotate(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map *map);
void	rotate_duplic(t_fdf *fdf, int i, int j);
void	set_duplic_to_initial(t_dots dots, t_dots *duplic, int i, int j);
void	apply_rotate_values(int *x, int *y, int *z, t_map *map);
void	modify_rotations_values(t_map *map);

	/* translations */
void	translations(t_fdf *fdf, int key);
void	translate_axis(t_fdf *fdf, t_dots *dots, t_map map, int neg);
void	translate_ordin(t_fdf *fdf, t_dots *dots, t_map map, int neg);

	/* mirror */
void	mirror(t_fdf *fdf, t_dots *dots, t_dots *mirror, t_map map);

	/* free bonus */
int		close_free_bns(t_fdf *fdf);
void	free_mlx_dots_bns(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map map);
void	free_and_new_img(t_mlx *mlx, t_dots *dots, t_dots *duplic, t_map map);

#endif
