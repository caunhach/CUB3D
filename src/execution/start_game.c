#include "../../inc/cub3d.h"

int		game_loop(void *cub)
{
	t_cub3d	*cub3d;

	cub3d = cub;
	mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	cub3d->img->img = mlx_new_image(cub3d->mlx, WIN_W, WIN_H);
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img,
			&cub3d->img->bpp, &cub3d->img->ll, &cub3d->img->endian);
	rot(cub3d);
	move(cub3d);
	ray_cast(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	return (EXIT_SUCCESS);
}

void	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_W, WIN_H, "CUB3D");
	cub3d->img->img = mlx_new_image(cub3d->mlx, WIN_W, WIN_H);
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img,
			&cub3d->img->bpp, &cub3d->img->ll, &cub3d->img->endian);
}

void	start_game(t_cub3d *cub3d)
{
	init_mlx(cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, key_release, cub3d);
	mlx_hook(cub3d->win, 17, 1L << 17, close_win, cub3d);
	mlx_loop_hook(cub3d->mlx, &game_loop, cub3d);
	mlx_loop(cub3d->mlx);
}