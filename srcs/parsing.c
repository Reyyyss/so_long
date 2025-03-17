/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/17 18:00:12 by hcarrasq         ###   ########.fr       */
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
		ft_error(3); // 3 = map dont have enough space
	map_checker(&map, map_fd); // largura = 30 e altura = 16 (maximos)
	close(map_fd);
}

void	row_checker(int map_fd, t_map *map)
{
	char	*row;
	int		i;

	i = 0;
	row = get_next_line(map_fd);
	if (!row)
		ft_error(1); // 1 = the map file dont have nothing
	map->width = ft_strlen(row);
	map->height = 1;
	free(row);
	while (row = get_next_line(map_fd))
	{
		if (ft_strlen(row) != map->width)
		{
			free(row);
			ft_error(2); // 2 = the map is not retangular
		}
		map->height++;
		free(row);
	}
}

void	map_checker(int map_fd, t_map *map)
{
	int i;

	i = 0;
	map->map = malloc(map->height * sizeof(char *));
	while (i <= map->height)
	{
		map->map[i] = ft_strdup(get_next_line(map_fd));
		if (ft_strncmp("1", map->map[0], strlen(map->width)))
			ft_error(4);// 4 = map not enclosed by walls
		else if (map->map[i][0] != '1' || map->map[i][map->width] != '1')
			ft_error(4);
		else if (ft_strncmp("1", map->map[map->height], strlen(map->width)))
			ft_error(4);
		check_assets(map->map[i], &map);
		i++;
	}
}

void	check_assets(char *row, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->width)
	{
		if (row[i] == 'p')
			map->player++;
		else if (row[i] == 'e')
			map->exit++;
		else if (row[i] == 'c')
			map->collectible++;
		i++;
	}
	if ()
}
