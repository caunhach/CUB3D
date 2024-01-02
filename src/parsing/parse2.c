/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wamonvor <wamonvor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:33:41 by caunhach          #+#    #+#             */
/*   Updated: 2024/01/02 14:03:18 by wamonvor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**split1(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_to_create_tab(tab, s, c));
}

int	readmap_file(int fd, char ***tab)
{
	char	*s1;
	char	*str;

	s1 = malloc(10240);
	str = 0;
	if (read_file(&s1, fd))
		exit (write_error("error on process read file\n"));
	while (s1 && *s1)
	{
		str = ft_free_join(str, s1, 1);
		if (!str || read_file(&s1, fd))
		{
			return (write_error("Error\nRead failed2\n"));
		}
	}
	*tab = split1(str, '\n');
	if (!*tab && ft_free(s1, 0, 0, 0))
		return (write_error("Error\nMap empty\n"));
	free(s1);
	free(str);
	return (0);
}

int	find_nosoweea(char *str, size_t i)
{
	if (!ft_strncmp("NO ", &str[i], 3))
		return (1);
	else if (!ft_strncmp("SO ", &str[i], 3))
		return (2);
	else if (!ft_strncmp("WE ", &str[i], 3))
		return (3);
	else if (!ft_strncmp("EA ", &str[i], 3))
		return (4);
	else if (!ft_strncmp("F ", &str[i], 2))
		return (5);
	else if (!ft_strncmp("C ", &str[i], 2))
		return (6);
	else if (alm(str[i]))
		return (7);
	else
		return (0);
}

int	map_face(t_file *file, char *str, size_t i)
{
	int		face;

	i = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\n'))
		i++;
	if (!str[i])
		return (0);
	face = find_nosoweea(str, i);
	if (face == 0)
		exit (write_error("parameter in map not correct\n"));
	else if (face == 7)
		return (2);
	while (str[i] && str[i] != 32)
		i++;
	while (str[i] && str[i] == 32)
		i++;
	if (set_vlauenosoweea(file, str, i, face))
		return (1);
	while (str[i])
		i++;
	return (0);
}

int	set_vlauenosoweea(t_file *file, char *str, size_t start, int face)
{
	size_t	end;

	end = start;
	while (str[end] && str[end] != 0)
		end++;
	if (face == 1 && ++file->countpara && file->no[0] == '0')
		file->no = ft_substr(str, start, end - start);
	else if (face == 2 && ++file->countpara && file->so[0] == '0')
		file->so = ft_substr(str, start, end - start);
	else if (face == 3 && ++file->countpara && file->we[0] == '0')
		file->we = ft_substr(str, start, end - start);
	else if (face == 4 && ++file->countpara && file->ea[0] == '0')
		file->ea = ft_substr(str, start, end - start);
	else if (face == 5 && ++file->countpara && file->f[0] == 'x')
		file->f = ft_substr(str, start, end - start);
	else if (face == 6 && ++file->countpara && file->c[0] == 'x')
		file->c = ft_substr(str, start, end - start);
	if ((face == 1 && !file->no) || (face == 2 && !file->so)
		|| (face == 3 && !file->we) || (face == 4 && !file->ea)
		|| (face == 5 && !file->f) || (face == 6 && !file->c))
		exit (write_error("file can not set\n"));
	return (0);
}
