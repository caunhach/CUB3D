#include "../../inc/cub3d.h"

void	check_position(t_cub3d *cub3d)
{
	if (!ft_strchr("1D", cub3d->map->mat_map[(int)(cub3d->plyr->posy)] \
			[(int)(cub3d->plyr->posx + cub3d->plyr->fr_x)]))
		cub3d->plyr->posx += cub3d->plyr->fr_x;
	if (!ft_strchr("1D", cub3d->map->mat_map[(int)(cub3d->plyr->posy + \
			cub3d->plyr->fr_y)][(int)(cub3d->plyr->posx)]))
		cub3d->plyr->posy += cub3d->plyr->fr_y;
	if (!ft_strchr("1D", cub3d->map->mat_map[(int)(cub3d->plyr->posy)] \
			[(int)(cub3d->plyr->posx + cub3d->plyr->rg_x)]))
		cub3d->plyr->posx += cub3d->plyr->rg_x;
	if (!ft_strchr("1D", cub3d->map->mat_map[(int)(cub3d->plyr->posy + \
			cub3d->plyr->rg_y)][(int)(cub3d->plyr->posx)]))
		cub3d->plyr->posy += cub3d->plyr->rg_y;
	printf("dirx : %lf, diry : %lf\n", cub3d->plyr->dirx, cub3d->plyr->diry);
	printf("uplnx : %lf, uplny : %lf\n", cub3d->plyr->u_plnx, cub3d->plyr->u_plny);
	printf("frx: %lf, fry: %lf, rgx: %lf, rgy:%lf\n", cub3d->plyr->fr_x, cub3d->plyr->fr_y, cub3d->plyr->rg_x, cub3d->plyr->rg_y);
	printf("posx : %lf, posy: %lf\n", cub3d->plyr->posx, cub3d->plyr->posy);
}

void	rot_dir(double rot, t_cub3d *cub3d)
{
	double	old_dirx;
	double	old_diry;

	old_dirx = cub3d->plyr->dirx;
	old_diry = cub3d->plyr->diry;
	cub3d->plyr->dirx = old_dirx * cos(rot) - old_diry * sin(rot);
	cub3d->plyr->diry = old_dirx * sin(rot) + old_diry * cos(rot);
}

void	rot_pln(double rot, t_cub3d *cub3d)
{
	double	old_plnx;
	double	old_plny;
	double	old_uplnx;
	double	old_uplny;

	old_plnx = cub3d->plyr->plnx;
	old_plny = cub3d->plyr->plny;
	old_uplnx = cub3d->plyr->u_plnx;
	old_uplny = cub3d->plyr->u_plny;
	cub3d->plyr->plnx = old_plnx * cos(rot) - old_plny * sin(rot);
	cub3d->plyr->plny = old_plnx * sin(rot) + old_plny * cos(rot);
	cub3d->plyr->u_plnx = old_uplnx * cos(rot) - old_uplny * sin(rot);
	cub3d->plyr->u_plny = old_uplnx * sin(rot) + old_uplny * cos(rot);
}

void	rot(t_cub3d *cub3d)
{
	double	rot;

	rot = 0;
	if (cub3d->ray->move[rot_ccw])
		rot += -0.07;
	if (cub3d->ray->move[rot_cw])
		rot += 0.07;
	rot_dir(rot, cub3d);
	rot_pln(rot, cub3d);
}

void	move(t_cub3d *cub3d)
{
	cub3d->plyr->fr_x = 0;
	cub3d->plyr->fr_y = 0;
	cub3d->plyr->rg_x = 0;
	cub3d->plyr->rg_y = 0;
	if (cub3d->ray->move[forward] == 1)
	{
		cub3d->plyr->fr_x += cub3d->plyr->dirx * Speed;
		cub3d->plyr->fr_y += cub3d->plyr->diry * Speed;
	}
	if (cub3d->ray->move[turnright] == 1)
	{
		cub3d->plyr->rg_x += cub3d->plyr->u_plnx * Speed;
		cub3d->plyr->rg_y += cub3d->plyr->u_plny * Speed;
	}
	if (cub3d->ray->move[backward] == 1)
	{
		cub3d->plyr->fr_x -= cub3d->plyr->dirx * Speed;
		cub3d->plyr->fr_y -= cub3d->plyr->diry * Speed;
	}
	if (cub3d->ray->move[turnleft] == 1)
	{
		cub3d->plyr->rg_x -= cub3d->plyr->u_plnx * Speed;
		cub3d->plyr->rg_y -= cub3d->plyr->u_plny * Speed;
	}
	check_position(cub3d);
}
