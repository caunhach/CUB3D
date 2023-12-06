/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:32:53 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/06 23:33:04 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx_opengl/mlx.h"
# include <math.h>

# define WIN_H 900
# define WIN_W 1440
# define WHITE 0xFFFFFF
# define CARROT 0xFFA500
# define YELLOW 0xFFFF00
# define GRASS 0x00FF00
# define AQUA 0x00FFFF
# define RED 0xFF0000

# define alloc_fail "Error : alloc fail"
# define pixel_size 32
# define FOV 60
# define hori 0
# define vert 1
# define Speed 0.04
# define E 2
# define W 3
# define N 4
# define S 5
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_RIGHT 123
# define KEY_LEFT 124
# define forward 0
# define turnleft 1
# define backward 2
# define turnright 3
# define rot_cw 4
# define rot_ccw 5

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	plnx;
	double	plny;
	double	u_plnx;
	double	u_plny;
	double	fr_x;
	double	fr_y;
	double	rg_x;
	double	rg_y;
}	t_player;

typedef struct s_map
{
	char **mat_map;
	int w_map;
	int	h_map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_ray
{
	int		win_x;
	double	raydirx;
	double	raydiry;
	int		pl_x;
	int		pl_y;
	double	delx;
	double	dely;
	double	idelx;
	double	idely;
	int		stepx;
	int		stepy;
	int		side;
	double	prepwalldist;
	int		move[6];
}	t_ray;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_ray		*ray;
	t_player	*plyr;
}	t_cub3d;

/* main */

void	init_param(t_cub3d *cub3d);
void	unit_plane(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
int		init_cub3d(t_cub3d *cub3d);

/* utils */

void	ft_error(char *msg);

void	free_map(t_map *map);
void	free_cub3d(t_cub3d *cub3d);
void	free_all(t_cub3d *cub3d);

/* parsing */

t_map	*map_parse();

/* execution */

void	draw_vert(t_cub3d *cub3d, int i, int f, int color);
void	img_pixel_put(t_cub3d *cub3d, int x, int y, int color);
int		get_color(t_cub3d *cub3d);
void	draw(t_cub3d *cub3d);

int		key_press(int key, t_cub3d *cub3d);
int		key_release(int key, t_cub3d *cub3d);
int		close_win(t_cub3d *cub3d);

void	check_position(t_cub3d *cub3d);
void	rot_dir(double rot, t_cub3d *cub3d);
void	rot_pln(double rot, t_cub3d *cub3d);
void	rot(t_cub3d *cub3d);
void	move(t_cub3d *cub3d);

void	find_side(t_cub3d *cub3d);
void	find_wall(t_cub3d *cub3d);
void	cal_sidedist(t_cub3d *cub3d);
void	cal_dda(t_cub3d *cub3d);
void	ray_cast(t_cub3d *cub3d);

void	cal_prepwall(t_cub3d *cub3d);

int		game_loop(void *cub);
void	init_mlx(t_cub3d *cub3d);
void	start_game(t_cub3d *cub3d);

#endif
