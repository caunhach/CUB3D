/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/06 23:33:46 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_param(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < 6)
		cub3d->ray->move[i] = 0;
}

void	unit_plane(t_cub3d *cub3d)
{
	cub3d->plyr->u_plnx = cub3d->plyr->plnx / 0.66;
	cub3d->plyr->u_plny = cub3d->plyr->plny / 0.66;
}

void	init_player(t_cub3d *cub3d)
{
	cub3d->plyr->posx = 13.5;
	cub3d->plyr->posy = 2.5;
	cub3d->plyr->dirx = 1;
	cub3d->plyr->diry = 0;
	cub3d->plyr->plnx = 0;
	cub3d->plyr->plny = -0.66;
	cub3d->plyr->fr_x = 0;
	cub3d->plyr->fr_y = 0;
	cub3d->plyr->rg_x = 0;
	cub3d->plyr->rg_y = 0;
	unit_plane(cub3d);
}

int	init_cub3d(t_cub3d *cub3d)
{
	cub3d->img = (t_img *)malloc(sizeof(t_img));
	cub3d->ray = (t_ray *)malloc(sizeof(t_ray));
	cub3d->plyr = (t_player *)malloc(sizeof(t_player));
	if (!cub3d->img || !cub3d->ray || !cub3d->plyr)
		return (1);
	init_param(cub3d);
	init_player(cub3d);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!cub3d)
		ft_error(alloc_fail);
	if (init_cub3d(cub3d))
	{
		free_cub3d(cub3d);
		ft_error(alloc_fail);
	}
	cub3d->map = map_parse();
	// printf("%s\n", cub3d->map->mat_map[0]);
	// printf("%s\n", cub3d->map->mat_map[1]);
	// printf("%s\n", cub3d->map->mat_map[2]);
	// printf("%s\n", cub3d->map->mat_map[3]);
	// printf("%s\n", cub3d->map->mat_map[4]);
	// printf("%s\n", cub3d->map->mat_map[5]);
	// printf("%s\n", cub3d->map->mat_map[6]);
	// printf("%s\n", cub3d->map->mat_map[7]);
	// printf("%s\n", cub3d->map->mat_map[8]);
	// printf("%s\n", cub3d->map->mat_map[9]);
	start_game(cub3d);
	// free_cub3d(cub3d);
	(void)argv;
	(void)argc;
}
