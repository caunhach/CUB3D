#include "../../inc/cub3d.h"

t_map	*map_parse()
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->mat_map = ft_calloc(10, sizeof(char *));
	map->mat_map[0] = ft_strdup("1111111111111111111111111");
	map->mat_map[1] = ft_strdup("1000000000000000000100001");
	map->mat_map[2] = ft_strdup("1001000000000000000000001");
	map->mat_map[3] = ft_strdup("1001000000000000001000001");
	map->mat_map[4] = ft_strdup("1001000000000000001000001");
	map->mat_map[5] = ft_strdup("1001000000100000001000001");
	map->mat_map[6] = ft_strdup("1001000000000000001000001");
	map->mat_map[7] = ft_strdup("1001000000001000001000001");
	map->mat_map[8] = ft_strdup("1111111111111111111111111");
	map->mat_map[9] = NULL;
	map->w_map = 25;
	map->h_map = 9;
	return (map);
}