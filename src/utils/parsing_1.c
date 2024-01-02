/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:19:39 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 12:19:52 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	checkwall2(t_map *m, int x, int y)
{
	m->snwe = m->mat_map[y][x];
	m->countsnwe++;
	m->plyx = x + 0.5;
	m->plyy = y + 0.5;
}

int	checkwall(t_map *m, size_t *map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (m->mat_map[y])
	{
		x = 0;
		while (m->mat_map[y][x])
		{
			if (isfl(m->mat_map[y][x]) && !(x && alm(m->mat_map[y][x - 1])
				&& m->mat_map[y][x + 1] && alm(m->mat_map[y][x + 1])
				&& y && map_len[y - 1] >= x + 1 && alm(m->mat_map[y - 1][x - 1])
				&& alm(m->mat_map[y - 1][x]) && alm(m->mat_map[y - 1][x + 1])
				&& m->mat_map[y + 1] && map_len[y + 1] >= x
				&& alm(m->mat_map[y + 1][x - 1])
				&& alm(m->mat_map[y + 1][x]) && alm(m->mat_map[y + 1][x + 1])))
				return (write_error("Error\nMap isnt close\n"));
			if (is_nsew(m->mat_map[y][x]))
				checkwall2(m, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_items_characters(char **map)
{
	int	i;
	int	line;
	int	result;

	line = -1;
	result = 0;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == '1' || map[line][i] == '\n')
				result++;
			else if (map[line][i] == 'P' || map[line][i] == '0')
				result++;
			else
				return (0);
		}
	}
	return (result);
}

int	ft_check_map_sides(char **mat_map)
{
	int	i;
	int	line;

	line = 0;
	i = -1;
	while (mat_map[line][++i] != '\n')
	{
		if (mat_map[line][i] != '1')
			return (0);
	}
	i = -1;
	while (mat_map[++line])
	{
		if (mat_map[line][0] != '1')
			return (0);
		if (mat_map[line][ft_strlen(mat_map[line]) - 2] != '1')
			return (0);
	}
	while (mat_map[line - 1][++i])
	{
		if (mat_map[line - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	is_allowmapchar(char **map, size_t	**map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(alm(map[y][x]) || map[y][x] == 32 || map[y][x] == '\n'))
				return (write_error("Error\nmap can use only [0 1 N S E W]\n"));
			x++;
		}
		(*map_len)[y] = x;
		y++;
	}
	return (0);
}
