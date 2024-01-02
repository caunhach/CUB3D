/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2023/12/25 16:48:46 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*setadd(void *simag, int *pbb, int *ll, int *end)
{
	return (mlx_get_data_addr(simag, pbb, ll, end));
}

void	imageswall(t_cub3d *c, t_file *file)
{
	int	y;
	int	x;

	x = 64;
	y = 64;
	c->ea->img = mlx_xpm_file_to_image(c->mlx, file->ea, &x, &y);
	c->ea->img = setadd(c->ea->img, &c->ea->bpp, &c->ea->ll, &c->ea->endian);
	c->so->img = mlx_xpm_file_to_image(c->mlx, file->so, &x, &y);
	c->so->img = setadd(c->so->img, &c->so->bpp, &c->so->ll, &c->so->endian);
	c->no->img = mlx_xpm_file_to_image(c->mlx, file->no, &x, &y);
	c->no->img = setadd(c->no->img, &c->no->bpp, &c->no->ll, &c->no->endian);
	c->we->img = mlx_xpm_file_to_image(c->mlx, file->we, &x, &y);
	c->we->img = setadd(c->we->img, &c->we->bpp, &c->we->ll, &c->we->endian);
}

static void	creat2(const char *s, char c, int *i, int *trig)
{
	if (s[*i] == c)
		(*i)++;
	else if (s[*i] && s[*i] != c)
	{
		while (s[*i] && s[*i] != c)
			(*i)++;
		*trig = 0;
	}
}

char	**ft_to_create_tab(char **tab, const char *s, char c)
{
	int		count;
	int		i;
	int		start;
	int		trig;

	init(&count, &i, &start, &trig);
	while (s[i])
	{
		if (s[i] == c && trig == 0 && ++trig)
			start = ++i;
		else if (s[i] && (trig || s[i] != c))
		{
			creat2(s, c, &i, &trig);
			tab[count] = ft_substr(s, start, i - start);
			if (!tab[count++])
			{
				free_tab(tab, 0);
				return (0);
			}
			start = i;
		}
	}
	tab[count] = NULL;
	return (tab);
}

int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;
	int	trigger;

	i = 0;
	trigger = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && trigger == 0)
			trigger = 1;
		else if (str[i] == c && trigger == 1)
			count++;
		else if (str[i] != c && trigger == 1)
		{
			count++;
			trigger = 0;
		}
		i++;
	}
	return (count);
}
