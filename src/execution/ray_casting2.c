/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:13:58 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 12:13:58 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	cal_prepwall(t_cub3d *cub3d)
{
	if (cub3d->ray->side == N || cub3d->ray->side == S)
		cub3d->ray->prepwalldist = (cub3d->ray->pl_x - cub3d->plyr->posx + \
			(1 - cub3d->ray->stepx) / 2) / cub3d->ray->raydirx;
	else if (cub3d->ray->side == E || cub3d->ray->side == W)
		cub3d->ray->prepwalldist = (cub3d->ray->pl_y - cub3d->plyr->posy + \
			(1 - cub3d->ray->stepy) / 2) / cub3d->ray->raydiry;
}
