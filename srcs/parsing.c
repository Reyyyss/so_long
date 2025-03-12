/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/12 16:05:11 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_parsing(char *av, t_map *map)
{
	int		map_fd;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 3)
		return (close(map_fd));
	row_checker(map_fd, &map);
	if (map->height < 3 || map->width < 3)
		ft_error(3);
	map_checker(&map); // largura = 30 e altura = 17
	close(map_fd);
}

void	row_checker(int map_fd, t_map *map)
{
	char	*row;
	int		i;

	i = 0;
	row = get_next_line(map_fd);
	if (!row)
		ft_error(1);
	map->width = ft_strlen(row);
	map->height = 1;
	free(row);
	while (row = get_next_line(map_fd))
	{
		if (ft_strlen(row) != map->width)
		{
			free(row);
			ft_error(2);
		}
		map->height++;
		free(row);
	}
}

void	map_checker(t_map *map)
{
	
}