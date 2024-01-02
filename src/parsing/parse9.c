/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:14:25 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 13:42:35 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	fp(char *filename)
{
	FILE	*file;

	if (!isxpm(filename))
		return (1);
	file = fopen(filename, "r");
	if (file != NULL)
		fclose(file);
	else
		return (1);
	return (0);
}

int	checkpath(t_file *file)
{
	if (fp(file->no) == 0 && fp(file->we) == 0
		&& fp(file->so) == 0 && fp(file->ea) == 0)
		return (0);
	else
		return (1);
}

int	isxpm(char *mapname)
{
	int	i;

	i = 0;
	if (!mapname)
		return (1);
	while (mapname[i])
		i++;
	i -= 1;
	if (mapname[i] == 'm' && mapname[i - 1] == 'p' && mapname[i - 2] == 'x'
		&& mapname[i - 3] == '.')
		return (1);
	return (0);
}

int	conv_color(int *color, char *str)
{
	unsigned int	rgb[3];
	size_t			i;
	char			**tab;

	if (check_color_str(str))
		return (1);
	tab = color_split(str);
	if (tab == 0)
		exit (write_error("Error\nmALLOC_FAILed\n"));
	i = -1;
	while (tab[++i])
		rgb[i] = ft_atoi_color(tab[i]);
	i = 0;
	*color = 0;
	while (i < 3)
		if (ft_rgb(color, rgb, i++))
			return (ft_free(tab[0], tab[1], tab[2], tab));
	ft_free(tab[0], tab[1], tab[2], tab);
	return (0);
}

int	check_color_str(char *str)
{
	size_t	i;
	size_t	com;

	i = 0;
	com = 0;
	while (str[i] && com <= 2)
	{
		if (str[i] == ',')
			com++;
		i++;
	}
	if (com > 2)
		return (1);
	return (0);
}
