/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:13:55 by wamonvor          #+#    #+#             */
/*   Updated: 2024/01/02 13:07:26 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	find_side(t_cub3d *cub3d)
{
	if (cub3d->ray->side == HORI)
	{
		if (cub3d->ray->raydiry > 0)
			cub3d->ray->side = E;
		else if (cub3d->ray->raydiry < 0)
			cub3d->ray->side = W;
	}
	else if (cub3d->ray->side == VERT)
	{
		if (cub3d->ray->raydirx < 0)
			cub3d->ray->side = N;
		else if (cub3d->ray->raydirx > 0)
			cub3d->ray->side = S;
	}
}

void	find_wall(t_cub3d *cub3d)
{
	while (1)
	{
		if (cub3d->ray->idelx < cub3d->ray->idely)
		{
			cub3d->ray->idelx += cub3d->ray->delx;
			cub3d->ray->pl_x += cub3d->ray->stepx;
			cub3d->ray->side = VERT;
		}
		else
		{
			cub3d->ray->idely += cub3d->ray->dely;
			cub3d->ray->pl_y += cub3d->ray->stepy;
			cub3d->ray->side = HORI;
		}
		if (cub3d->map->mat_map[cub3d->ray->pl_y] \
			[cub3d->ray->pl_x] - '0' == 1)
		{
			find_side(cub3d);
			break ;
		}
	}
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

	pln_ratio = 2 * (double)cub3d->ray->win_x / (double)WIN_W - 1;
	cub3d->ray->raydirx = cub3d->plyr->dirx + cub3d->plyr->plnx * pln_ratio;
	cub3d->ray->raydiry = cub3d->plyr->diry + cub3d->plyr->plny * pln_ratio;
	cub3d->ray->pl_x = (int)cub3d->plyr->posx;
	cub3d->ray->pl_y = (int)cub3d->plyr->posy;
	cub3d->ray->delx = fabs(1 / cub3d->ray->raydirx);
	cub3d->ray->dely = fabs(1 / cub3d->ray->raydiry);
	cal_sidedist(cub3d);
	find_wall(cub3d);
	cal_prepwall(cub3d);
}

void	ray_cast(t_cub3d *cub3d)
{
	cub3d->ray->win_x = 0;
	while (cub3d->ray->win_x < WIN_W)
	{
		cal_dda(cub3d);
		draw(cub3d);
		cub3d->ray->win_x++;
	}
}
