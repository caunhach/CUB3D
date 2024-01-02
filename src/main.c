/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/25 17:28:18 by wamonvor         ###   ########.fr       */
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

void	init_playersnew(t_cub3d *cub3d)
{
	cub3d->plyr->posx = cub3d->map->plyx;
	cub3d->plyr->posy = cub3d->map->plyy;
	if (cub3d->map->snwe == 'S')
		set_pos_s(cub3d);
	if (cub3d->map->snwe == 'N')
		set_pos_n(cub3d);
	if (cub3d->map->snwe == 'E')
		set_pos_e(cub3d);
	if (cub3d->map->snwe == 'W')
		set_pos_w(cub3d);
	cub3d->plyr->fr_x = 0;
	cub3d->plyr->fr_y = 0;
	cub3d->plyr->rg_x = 0;
	cub3d->plyr->rg_y = 0;
	unit_plane(cub3d);
}

int	init_cub3d(t_cub3d *cub3d, t_file *file)
{
	cub3d->img = (t_img *)malloc(sizeof(t_img));
	cub3d->ray = (t_ray *)malloc(sizeof(t_ray));
	cub3d->plyr = (t_player *)malloc(sizeof(t_player));
	if (!cub3d->img || !cub3d->ray || !cub3d->plyr)
		return (1);
	init_param(cub3d);
	init_file(file);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;
	t_map	*map;
	t_file	*file;

	if (argc != 2)
		ft_error("please try again Ex: ./cub3D <map_path>.cub");
	if (!iscub(argv[1]))
		ft_error("ERROR : FILE MAP TYPE *.cub");
	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	map = (t_map *)malloc(sizeof(t_map));
	file = malloc(sizeof(t_file));
	makemalloc(file, cub3d, map);
	if (init_cub3d(cub3d, file))
	{
		free_cub3d(cub3d);
		ft_error(ALLOC_FAIL);
	}
	if (parsingmap(cub3d, file, argv[1]))
		ft_error("ERROR : parsing map process");
	init_playersnew(cub3d);
	start_game(cub3d);
	free_cub3d(cub3d);
	return (0);
}
