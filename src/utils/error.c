#include "../../inc/cub3d.h"

void	ft_error(char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(1, &msg[i], 1);
	exit(EXIT_FAILURE);
}