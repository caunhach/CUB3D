/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:32:53 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/25 16:46:48 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx_opengl/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIN_H 900
# define WIN_W 1440
# define WHITE 0xFFFFFF
# define CARROT 0xFFA500
# define YELLOW 0xFFFF00
# define GRASS 0x00FF00
# define AQUA 0x00FFFF
# define RED 0xFF0000

# define ALLOC_FAIL "Error : alloc fail"
# define PIXEL_SIZE 32
# define FOV 60
# define HORI 0
# define VERT 1
# define SPEED 0.04
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
# define FORW 0
# define TURNL 1
# define BACKW 2
# define TURNR 3
# define ROTCW 4
# define ROTCCW 5

# define MAX_ROWS 100
# define MAX_COLS 100
# define MAX_STRING_LENGTH 50

typedef struct s_item
{
	char	type;
	int		px;
	int		py;
}	t_item;

typedef struct s_file
{
	int		countpara;
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	size_t	map_start;
	size_t	tab_len;
}	t_file;

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
	size_t	map_len;
	char	**mat_map;

	int		w_map;
	int		h_map;
	float	plyx;
	float	plyy;
	int		f;
	int		c;
	char	snwe;
	int		countsnwe;
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
	int		lineheight;
	double	wallx;
	int		textx;
	double	wallpos;
}	t_ray;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*ea;
	t_img		*so;
	t_img		*no;
	t_img		*we;
	t_map		*map;
	t_ray		*ray;
	t_player	*plyr;
}	t_cub3d;

/* main */
void	init_param(t_cub3d *cub3d);
void	unit_plane(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
int		init_cub3d(t_cub3d *cub3d, t_file *file);

/* utils */

void	ft_error(char *msg);

void	free_map(t_map *map);
void	free_cub3d(t_cub3d *cub3d);
void	free_all(t_cub3d *cub3d);

/* parsing */

t_map	*map_parse(void);

/* execution */

void	draw_wall(t_cub3d *cub3d, int drawStart, int drawEnd);
void	draw_vert(t_cub3d *cub3d, int i, int f, int color);
void	img_pixel_put(t_cub3d *cub3d, int x, int y, int color);
int		get_color(t_cub3d *cub3d, int x, int y);
void	draw(t_cub3d *cub3d);

void	set_wall(t_cub3d *cub3d);
int		get_pixel(t_img	*img, int x, int y);

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

t_map	*map_parse_fixmap(char*map);
void	ft_add_imgs(t_cub3d *data);
int		ft_checkerrors(t_cub3d *cub3d);
void	ft_error_check(char *errormessage);
int		is_nsew(char c);
int		alm(char c);
int		isfl(char c);
int		checkwall(t_map *map, size_t *map_len);
int		write_error(char *str);
char	*ft_free_join(char const *s1, char const *s2, int e);
void	free_join(void *s1, void *s2, int e);
void	ft_tab_len(t_file *file, char **tab);
int		free_tab(char **tab, int ret);
int		read_file(char **str, int fd);
int		is_allowmapchar(char **map, size_t	**map_len);
int		ft_free(void *a1, void *a2, void *a3, void *a4);
int		set_vlauenosoweea(t_file *file, char *str, size_t start, int face);
char	**split1(char const *s, char c);
int		ft_count_words(const char *str, char c);
char	**ft_to_create_tab(char **tab, const char *s, char c);
void	imageswall(t_cub3d *cub3d, t_file *file);
int		iscub(char *mapname);
int		parsingmap(t_cub3d *cube3d, t_file *file, char *mapname);
int		createmap(t_map *map, t_file *file, char *mapname);
int		free_file(t_file *file);
int		checkfile(t_file *file, char **tab);
char	**split1(char const *s, char c);
int		readmap_file(int fd, char ***tab);
int		find_nosoweea(char *str, size_t i);
int		map_face(t_file *file, char *str, size_t i);
int		map_elem(t_file *file, char **tab);

int		take_map(t_file *file, t_map *map, char **tab);
int		free_tab(char **tab, int ret);
int		init_file(t_file *file);
void	init(int *i, int *count, int *start, int *trig);
int		check_map(t_map *map);

int		createmap(t_map *map, t_file *file, char *mapname);
int		parsingmap(t_cub3d *cube3d, t_file *file, char *mapname);
void	set_pos_w(t_cub3d *cub3d);
void	set_pos_n(t_cub3d *cub3d);
void	set_pos_s(t_cub3d *cub3d);
void	set_pos_e(t_cub3d *cub3d);
int		createmap2(t_map *map, t_file *file, char **tab);
void	init_playersnew(t_cub3d *cub3d);
void	makemalloc(t_file *file, t_cub3d *cub3d, t_map *map);
int		fp(char *filename);
int		checkpath(t_file *file);
int		isxpm(char *mapname);
size_t	search(char *str, size_t start);
int		ft_rgb(int *color, unsigned int rgb[3], int i);
int		ft_atoi_color(const char *str);
char	**color_split(char *str);
int		check_color_str(char *str);
int		conv_color(int *color, char *str);
void	free_tabnoret(char **tab);

#endif
