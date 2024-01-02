/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:14:28 by wamonvor          #+#    #+#             */
/*   Updated: 2023/12/25 12:18:11 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	search(char *str, size_t start)
{
	size_t		end;
	size_t		check_point;
	static int	set;

	set = 2;
	end = start;
	while (str[end] && (!set || str[end] != ','))
	{
		if (str[end] == ',')
			set--;
		if (!ft_isspace(str[end]))
			check_point = ++end;
		else
			end++;
	}
	return (check_point);
}

int	ft_rgb(int *color, unsigned int rgb[3], int i)
{
	if (rgb[i] > 255)
		return (1);
	*color += (rgb[i] << (((i + 2) - (i * 2)) * 8));
	return (0);
}

int	ft_atoi_color(const char *str)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i++] - 48);
		if (nb > 2147483647)
			return (-1);
	}
	if (str[i])
		return (-1);
	return (nb);
}

char	**color_split(char *str)
{
	char	**tab;
	size_t	end;
	size_t	start;
	size_t	i;

	end = 0;
	start = 0;
	i = 0;
	tab = malloc(sizeof(char *) * 4);
	while (i < 3)
	{
		start = end;
		while (str[start] && str[start] == 32)
			start++;
		if (str[start] == ',')
			start++;
		while (str[start] && str[start] == 32)
			start++;
		end = search(str, start);
		tab[i] = ft_substr(str, start, end - start);
		if (!tab[i++] && free_tab(tab, 1))
			return (0);
	}
	tab[i] = 0;
	return (tab);
}
