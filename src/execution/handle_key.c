/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:13:50 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 16:37:38 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
		close_win(cub3d);
	if (key == KEY_W)
		cub3d->ray->move[FORW] = 1;
	if (key == KEY_A)
		cub3d->ray->move[TURNL] = 1;
	if (key == KEY_S)
		cub3d->ray->move[BACKW] = 1;
	if (key == KEY_D)
		cub3d->ray->move[TURNR] = 1;
	if (key == KEY_RIGHT)
		cub3d->ray->move[ROTCW] = 1;
	if (key == KEY_LEFT)
		cub3d->ray->move[ROTCCW] = 1;
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->ray->move[FORW] = 0;
	if (key == KEY_A)
		cub3d->ray->move[TURNL] = 0;
	if (key == KEY_S)
		cub3d->ray->move[BACKW] = 0;
	if (key == KEY_D)
		cub3d->ray->move[TURNR] = 0;
	if (key == KEY_RIGHT)
		cub3d->ray->move[ROTCW] = 0;
	if (key == KEY_LEFT)
		cub3d->ray->move[ROTCCW] = 0;
	return (0);
}

int	close_win(t_cub3d *cub3d)
{
	free_all(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
