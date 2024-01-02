/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:14:07 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 12:14:10 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_free(void *a1, void *a2, void *a3, void *a4)
{
	if (a1)
		free(a1);
	if (a2)
		free(a2);
	if (a3)
		free(a3);
	if (a4)
		free(a4);
	return (1);
}

void	ft_tab_len(t_file *file, char **tab)
{
	size_t	i;

	i = file->map_start;
	while (tab[i])
		i++;
	file->tab_len = i - file->map_start;
}

int	iscub(char *mapname)
{
	int	i;

	i = 0;
	if (!mapname)
		return (1);
	while (mapname[i])
		i++;
	i -= 1;
	if (mapname[i] == 'b' && mapname[i - 1] == 'u' && mapname[i - 2] == 'c'
		&& mapname[i - 3] == '.')
		return (1);
	return (0);
}

void	ft_read_map(int fd, t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	map->mat_map = ft_calloc(10, sizeof(char *));
	while (map->mat_map)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map->mat_map[i] = str;
		i++;
	}
	map->mat_map[i] = NULL;
	map->w_map = 25;
	map->h_map = 15;
}

int	are_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!ft_isspace(str[i++]))
			return (0);
	return (1);
}
