/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2024/01/02 13:39:42 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	createmap2(t_map *map, t_file *file, char **tab)
{
	map->countsnwe = 0;
	map->snwe = '0';
	if (map_elem(file, tab))
	{
		ft_error("ERROR : file can not use [2]\n");
		return (free_tab(tab, 1));
	}
	if (take_map(file, map, tab))
		exit (write_error("Error\nOpen failed2\n"));
	if (check_map(map))
	{
		free_file(file);
		exit (write_error("Error\nOpen failed1\n"));
	}
	return (0);
}
