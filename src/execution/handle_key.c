#include "../../inc/cub3d.h"

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
		close_win(cub3d);
	if (key == KEY_W)
		cub3d->ray->move[forward] = 1;
	if (key == KEY_A)
		cub3d->ray->move[turnleft] = 1;
	if (key == KEY_S)
		cub3d->ray->move[backward] = 1;
	if (key == KEY_D)
		cub3d->ray->move[turnright] = 1;
	if (key == KEY_RIGHT)
		cub3d->ray->move[rot_cw] = 1;
	if (key == KEY_LEFT)
		cub3d->ray->move[rot_ccw] = 1;
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->ray->move[forward] = 0;
	if (key == KEY_A)
		cub3d->ray->move[turnleft] = 0;
	if (key == KEY_S)
		cub3d->ray->move[backward] = 0;
	if (key == KEY_D)
		cub3d->ray->move[turnright] = 0;
	if (key == KEY_RIGHT)
		cub3d->ray->move[rot_cw] = 0;
	if (key == KEY_LEFT)
		cub3d->ray->move[rot_ccw] = 0;
	return (0);
}

int	close_win(t_cub3d *cub3d)
{
	free_all(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
