#include "../../inc/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	if (map->mat_map)
	{
		while (++i < map->h_map)
		{
			if (map->mat_map[i])
				free(map->mat_map[i]);
		}
		free(map->mat_map[i]);
		free(map->mat_map);
	}
	free(map);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->map)
		free_map(cub3d->map);
	if (cub3d->img)
		free(cub3d->img);
	if (cub3d->plyr)
		free(cub3d->plyr);
	if (cub3d->ray)
		free(cub3d->ray);
	free(cub3d);
}

void	free_all(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	free_cub3d(cub3d);
}
