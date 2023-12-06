#include "../../inc/cub3d.h"

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

int		get_color(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = cub3d->ray->pl_x;
	y = cub3d->ray->pl_y;
	return (cub3d->map->mat_map[y][x]);
}

void	draw(t_cub3d *cub3d)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	// int	color;

	lineHeight = (int)(WIN_H / cub3d->ray->prepwalldist);
	drawStart = WIN_H / 2 - lineHeight / 2;
	// color = get_color(cub3d);
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = WIN_H / 2 + lineHeight / 2;
	if (drawEnd >= WIN_H)
		drawEnd = WIN_H - 1;
	draw_vert(cub3d, 0, drawStart, AQUA);
	draw_vert(cub3d, drawStart, drawEnd, RED);
	draw_vert(cub3d, drawEnd, WIN_H, GRASS);
}
