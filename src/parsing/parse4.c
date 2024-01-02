/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/25 16:49:18 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init(int *i, int *count, int *start, int *trig)
{
	*i = 0;
	*count = 0;
	*start = 0;
	*trig = 0;
}

int	check_map(t_map *map)
{
	size_t	*map_len;

	map_len = malloc(sizeof(size_t) * map->map_len);
	if (!map_len)
		return (write_error("map_len allocate_fail"));
	if (is_allowmapchar(map->mat_map, &map_len))
	{
		free(map_len);
		exit (write_error("Error\nmap can use only [ 1 0 S N E W ]\n"));
		return (1);
	}
	if (checkwall(map, map_len))
	{
		free(map_len);
		exit (write_error("Error\nOpen failedwall\n"));
		return (1);
	}
	if (map->countsnwe != 1)
	{
		free(map_len);
		exit (write_error("Error use [S N E W] for player start only 1\n"));
		return (write_error("Error\nNeed spawn\n"));
	}
	free(map_len);
	return (0);
}

int	createmap(t_map *map, t_file *file, char *mapname)
{
	char	**tab;
	int		fd;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		exit (write_error("Error\nFile cub can not open\n"));
	if (readmap_file(fd, &tab))
	{
		free_file(file);
		ft_error("ERROR : Readfile map process");
		return (1);
	}
	close(fd);
	if (createmap2(map, file, tab) == 1)
		return (1);
	return (free_tab(tab, 0));
}

int	parsingmap(t_cub3d *cube3d, t_file *file, char *mapname)
{
	int	i;

	if (createmap(cube3d->map, file, mapname))
		ft_error(ALLOC_FAIL);
	cube3d->mlx = mlx_init();
	if (cube3d->mlx == NULL)
		ft_error(ALLOC_FAIL);
	i = checkpath(file);
	if (i != 0)
		ft_error("file can not used");
	if (conv_color(&cube3d->map->f, file->f)
		|| conv_color(&cube3d->map->c, file->c))
		ft_error("parameter f c is error");
	cube3d->ea = malloc(sizeof(t_img));
	cube3d->so = malloc(sizeof(t_img));
	cube3d->no = malloc(sizeof(t_img));
	cube3d->we = malloc(sizeof(t_img));
	imageswall(cube3d, file);
	free_file(file);
	return (0);
}

int	free_file(t_file *file)
{
	free(file->so);
	free(file->no);
	free(file->we);
	free(file->ea);
	free(file->f);
	free(file->c);
	free(file);
	return (1);
}
