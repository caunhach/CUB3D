#include "../../inc/cub3d.h"

void	find_side(t_cub3d *cub3d)
{
	if (cub3d->ray->side == vert)
	{
		if (cub3d->ray->raydiry > 0)
			cub3d->ray->side = N;
		else if (cub3d->ray->raydiry < 0)
			cub3d->ray->side = S;
	}
	else if (cub3d->ray->side == hori)
	{
		if (cub3d->ray->raydirx < 0)
			cub3d->ray->side = E;
		else if (cub3d->ray->raydirx > 0)
			cub3d->ray->side = W;
	}
}

void	find_wall(t_cub3d *cub3d)
{
	// printf("plx : %d\n", cub3d->ray->pl_x);
	// printf("ply : %d\n", cub3d->ray->pl_y);
	// printf("idelx : %lf\n", cub3d->ray->idelx);
	// printf("idely : %lf\n", cub3d->ray->idely);
	while (1)
	{
		if (cub3d->ray->idelx < cub3d->ray->idely)
		{
			cub3d->ray->idelx += cub3d->ray->delx;
			cub3d->ray->pl_x += cub3d->ray->stepx;
			cub3d->ray->side = hori;
		}
		else
		{
			cub3d->ray->idely += cub3d->ray->dely;
			cub3d->ray->pl_y += cub3d->ray->stepy;
			cub3d->ray->side = vert;
		}
		if (cub3d->map->mat_map[cub3d->ray->pl_y] \
			[cub3d->ray->pl_x] - '0')
		{
			find_side(cub3d);
			break;
		}
	}
	// printf("%c\n", cub3d->map->mat_map[2][13]);
	// printf("%c\n", cub3d->map->mat_map[5][3]);
	// printf("plx : %d\n", cub3d->ray->pl_x);
	// printf("ply : %d\n", cub3d->ray->pl_y);
	// printf("idelx : %lf\n", cub3d->ray->idelx);
	// printf("idely : %lf\n", cub3d->ray->idely);
	// printf("side : %d\n", cub3d->ray->side);
}

void	cal_sidedist(t_cub3d *cub3d)
{
	if (cub3d->ray->raydirx < 0)
	{
		cub3d->ray->stepx = -1;
		cub3d->ray->idelx = (cub3d->plyr->posx - \
			cub3d->ray->pl_x) * cub3d->ray->delx;
	}
	else
	{
		cub3d->ray->stepx = 1;
		cub3d->ray->idelx = (cub3d->ray->pl_x - \
			cub3d->plyr->posx + 1) * cub3d->ray->delx;
	}
	if (cub3d->ray->raydiry < 0)
	{
		cub3d->ray->stepy = -1;
		cub3d->ray->idely = (cub3d->plyr->posy - \
			cub3d->ray->pl_y) * cub3d->ray->dely;
	}
	else
	{
		cub3d->ray->stepy = 1;
		cub3d->ray->idely = (cub3d->ray->pl_y - \
			cub3d->plyr->posy + 1) * cub3d->ray->dely;
	}
}

void	cal_dda(t_cub3d *cub3d)
{
	double	pln_ratio;

	pln_ratio = (double) 2 * cub3d->ray->win_x / WIN_W - 1;
	cub3d->ray->raydirx = cub3d->plyr->dirx + cub3d->plyr->plnx * pln_ratio;
	cub3d->ray->raydiry = cub3d->plyr->diry + cub3d->plyr->plny * pln_ratio;
	cub3d->ray->pl_x = (int)cub3d->plyr->posx;
	cub3d->ray->pl_y = (int)cub3d->plyr->posy;
	cub3d->ray->delx = fabs(1 / cub3d->ray->raydirx);
	cub3d->ray->dely = fabs(1 / cub3d->ray->raydiry);
	cal_sidedist(cub3d);
	find_wall(cub3d);
	cal_prepwall(cub3d);
	// printf("raydirx: %lf\n", cub3d->ray->raydirx);
	// printf("raydiry: %lf\n", cub3d->ray->raydiry);
	// printf("pl_x: %d\n", cub3d->ray->pl_x);
	// printf("pl_y: %d\n", cub3d->ray->pl_y);
	// printf("posx: %lf\n", cub3d->plyr->posx);
	// printf("posy: %lf\n", cub3d->plyr->posy);
	// printf("delx: %lf\n", cub3d->ray->delx);
	// printf("dely: %lf\n", cub3d->ray->dely);
	// printf("stepx: %d\n", cub3d->ray->stepx);
	// printf("idelx: %lf\n", cub3d->ray->idelx);
	// printf("stepy: %d\n", cub3d->ray->stepy);
	// printf("idely: %lf\n", cub3d->ray->idely);
	// printf("side: %d\n", cub3d->ray->side);
	// printf("prepwall: %lf\n", cub3d->ray->prepwalldist);
}

void	ray_cast(t_cub3d *cub3d)
{
	cub3d->ray->win_x = 0;
	while (cub3d->ray->win_x < WIN_W)
	{
		// cub3d->ray->win_x = WIN_W/2;
		cal_dda(cub3d);
		draw(cub3d);
		cub3d->ray->win_x++;
	}
}
