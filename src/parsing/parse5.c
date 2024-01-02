/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2024/01/02 13:14:13 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_pos_e(t_cub3d *cub3d)
{
	cub3d->plyr->dirx = 0;
	cub3d->plyr->diry = -1;
	cub3d->plyr->plnx = -0.66;
	cub3d->plyr->plny = 0;
}

void	set_pos_s(t_cub3d *cub3d)
{
	cub3d->plyr->dirx = -1;
	cub3d->plyr->diry = 0;
	cub3d->plyr->plnx = 0;
	cub3d->plyr->plny = 0.66;
}

void	set_pos_n(t_cub3d *cub3d)
{
	cub3d->plyr->dirx = 1;
	cub3d->plyr->diry = 0;
	cub3d->plyr->plnx = 0;
	cub3d->plyr->plny = -0.66;
}

void	set_pos_w(t_cub3d *cub3d)
{
	cub3d->plyr->dirx = 0;
	cub3d->plyr->diry = 1;
	cub3d->plyr->plnx = 0.66;
	cub3d->plyr->plny = 0;
}

void	processmain(t_cub3d *cub3d, t_file *file, char **argv)
{
	if (init_cub3d(cub3d, file))
	{
		free_cub3d(cub3d);
		ft_error(ALLOC_FAIL);
	}
	if (parsingmap(cub3d, file, argv[1]))
		ft_error("ERROR : parsing map process");
	init_playersnew(cub3d);
	start_game(cub3d);
}
