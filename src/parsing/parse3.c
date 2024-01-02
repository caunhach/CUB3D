/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2024/01/02 14:07:57 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_tabnoret(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	free_tab(char **tab, int ret)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (ret);
}

int	take_map(t_file *file, t_map *map, char **tab)
{
	size_t	i;
	size_t	i2;

	if (!file->map_start)
		exit (write_error("Error\nMap error\n"));
	ft_tab_len(file, tab);
	map->mat_map = malloc(sizeof(char *) * (file->tab_len + 1));
	if (!map->mat_map)
		return (free_file(file));
	i = file->map_start;
	i2 = 0;
	while (tab[i])
	{
		map->mat_map[i2] = ft_strdup(tab[i]);
		if (!map->mat_map[i2++])
			return (free_file(file));
		i++;
	}
	map->mat_map[i2] = 0;
	map->map_len = file->tab_len;
	return (0);
}

int	checkfile(t_file *file, char **tab)
{
	(void)tab;
	if ((file->no[0] == 0) || (file->so[0] == 0)
		|| (file->we[0] == 0) || (file->ea[0] == 0)
		|| (file->f[0] == 0) || (file->c[0] == 0))
	{
		return (1);
	}
	if ((file->no[0] == '0') || (file->so[0] == '0')
		|| (file->we[0] == '0') || (file->ea[0] == '0')
		|| (file->f[0] == 'x') || (file->c[0] == 'x')
		|| (file->countpara != 6))
	{
		return (1);
	}
	return (0);
}

int	map_elem(t_file *file, char **tab)
{
	size_t	i;
	size_t	i2;
	int		ret;

	i = 0;
	i2 = 0;
	while (tab[i])
	{
		ret = map_face(file, tab[i], i2);
		if (ret == 1)
		{
			free_file(file);
			return (1);
		}
		else if (ret == 2)
		{
			if (checkfile(file, tab) != 0)
				return (1);
			file->map_start = i;
			return (0);
		}
		i++;
	}
	return (0);
}
