/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:13:46 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 12:13:47 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_wall(t_cub3d *cub3d)
{
	if (cub3d->ray->side == N || cub3d->ray->side == S)
	{
		cub3d->ray->wallx = cub3d->plyr->posy + cub3d->ray->prepwalldist \
			* cub3d->ray->raydiry;
		cub3d->ray->wallx -= floor(cub3d->ray->wallx);
		cub3d->ray->textx = (int)(cub3d->ray->wallx * (double)64);
		if (cub3d->ray->raydirx > 0)
			cub3d->ray->textx = 64 - cub3d->ray->textx - 1;
	}
	else if (cub3d->ray->side == E || cub3d->ray->side == W)
	{
		cub3d->ray->wallx = cub3d->plyr->posx + cub3d->ray->prepwalldist \
			* cub3d->ray->raydirx;
		cub3d->ray->wallx -= floor(cub3d->ray->wallx);
		cub3d->ray->textx = (int)(cub3d->ray->wallx * (double)64);
		if (cub3d->ray->raydiry < 0)
			cub3d->ray->textx = 64 - cub3d->ray->textx - 1;
	}
}

int	get_pixel(t_img	*img, int x, int y)
{
	int	*dst;

	dst = (void *)img->img + (y * img->ll + x * (img->bpp / 8));
	return (*(int *)dst);
}
