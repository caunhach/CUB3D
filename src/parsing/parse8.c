/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:14:22 by wamonvor          #+#    #+#             */
/*   Updated: 2024/01/02 13:11:20 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	alm(char c)
{
	if (c == '1' || is_nsew(c) || isfl(c))
		return (1);
	return (0);
}

int	is_nsew(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_error_check(char *errormessage)
{
	ft_printf("\n****************************\n");
	ft_printf(errormessage);
	ft_printf("\n****************************\n");
	exit(0);
}

int	init_file(t_file *file)
{
	file->c = "x";
	file->f = "x";
	file->ea = "0";
	file->no = "0";
	file->so = "0";
	file->we = "0";
	file->countpara = 0;
	return (0);
}

void	makemalloc(t_file *file, t_cub3d *cub3d, t_map *map)
{
	if (!cub3d)
		ft_error(ALLOC_FAIL);
	if (!map)
		ft_error(ALLOC_FAIL);
	if (!file)
		ft_error(ALLOC_FAIL);
	cub3d->map = map;
}
