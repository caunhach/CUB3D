/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:22:06 by macbookpro2       #+#    #+#             */
/*   Updated: 2024/01/02 13:10:46 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// void	free_map(t_map *map)
// {
// 	int	i;

// 	i = -1;
// 	if (!map)
// 		return ;
// 	if (map->mat_map)
// 	{
// 		while (++i < map->h_map)
// 		{
// 			if (map->mat_map[i])
// 				free(map->mat_map[i]);
// 		}
// 		free(map->mat_map[i]);
// 		free(map->mat_map);
// 	}
// 	free(map->no);
//     free(map->so);
//     free(map->we);
//     free(map->ea);
// 	free(map);
// }

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		if (map->mat_map)
		{
			while (map->mat_map[i])
			{
				free(map->mat_map[i]);
				i++;
			}
			free(map->mat_map);
		}
		free(map);
	}
}

void	free_img(t_img *img)
{
	if (img)
	{
		free(img->img);
		free(img);
	}
}

void	free_cub3d(t_cub3d *cub3d)
{
	free_img(cub3d->ea);
	free_img(cub3d->so);
	free_img(cub3d->no);
	free_img(cub3d->we);
	free_map(cub3d->map);
	if (cub3d->ray)
		free(cub3d->ray);
	if (cub3d->plyr)
		free(cub3d->plyr);
	free(cub3d);
}

void	free_all(t_cub3d *cub3d)
{
	if (cub3d->img)
		free(cub3d->img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	free_cub3d(cub3d);
}
