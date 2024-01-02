/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:13:41 by wamonvor          #+#    #+#             */
/*   Updated: 2024/01/02 13:16:00 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_wall(t_cub3d *cub3d, int drawStart, int drawEnd)
{
	int		color;
	double	step;

	set_wall(cub3d);
	step = 1.0 * 64 / cub3d->ray->lineheight;
	cub3d->ray->wallpos = (drawStart - WIN_H / 2
			+ cub3d->ray->lineheight / 2) * step;
	while (drawStart < drawEnd - 1)
	{
		cub3d->ray->wallpos += step;
		color = RED;
		color = get_color(cub3d, cub3d->ray->textx, cub3d->ray->wallpos);
		img_pixel_put(cub3d, cub3d->ray->win_x, drawStart, color);
		drawStart++;
	}
}

void	draw_vert(t_cub3d *cub3d, int i, int f, int color)
{
	while (i < f)
	{
		img_pixel_put(cub3d, cub3d->ray->win_x, i, color);
		i++;
	}
}

void	img_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	int		pixel;
	char	*dst;

	if (y >= WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * cub3d->img->ll) + (x * (cub3d->img->bpp / 8));
	dst = cub3d->img->addr + (y * cub3d->img->ll) + (x * (cub3d->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->ray->side == N)
		return (get_pixel(cub3d->no, x, y));
	else if (cub3d->ray->side == S)
		return (get_pixel(cub3d->so, x, y));
	else if (cub3d->ray->side == E)
		return (get_pixel(cub3d->ea, x, y));
	else if (cub3d->ray->side == W)
		return (get_pixel(cub3d->we, x, y));
	else
		return (0);
}

void	draw(t_cub3d *cub3d)
{
	int	drawstart;
	int	drawend;

	cub3d->ray->lineheight = (int)(WIN_H / cub3d->ray->prepwalldist);
	drawstart = WIN_H / 2 - cub3d->ray->lineheight / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = WIN_H / 2 + cub3d->ray->lineheight / 2;
	if (drawend >= WIN_H)
		drawend = WIN_H - 1;
	draw_vert(cub3d, 0, drawstart, cub3d->map->c);
	draw_wall(cub3d, drawstart, drawend);
	draw_vert(cub3d, drawend - 1, WIN_H, cub3d->map->f);
}
