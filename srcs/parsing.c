/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/19 20:13:46 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_parsing(char *av, t_map *map, t_assets *assets)
{
	int		map_fd;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 3)
		return (close(map_fd));
	row_checker(map_fd, &map);
	if (map->height < 3 || map->width < 3)
		ft_error(3); // 3 = map dont have enough space
	map_checker(&map, map_fd, &assets); // largura = 30 e altura = 16 (maximos)
	flood_fill(&map, );
	close(map_fd);
}

void	row_checker(int map_fd, t_map *map)
{
	char	*row;
	int		i;

	i = 0;
	row = get_next_line(map_fd);
	if (!row)
		ft_error(1); // 1 = the map file has nothing
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

void	map_checker(int map_fd, t_map *map, t_assets *assets)
{
	int y;

	y = 0;
	map->map = malloc(map->height * sizeof(char *));
	while (y <= map->height)
	{
		map->map[y] = ft_strdup(get_next_line(map_fd));
		if (ft_strncmp("1", map->map[0], strlen(map->width)))
			ft_error(4);// 4 = map not enclosed by walls
		else if (map->map[y][0] != '1' || map->map[y][map->width] != '1')
			ft_error(4);
		else if (ft_strncmp("1", map->map[map->height], strlen(map->width)))
			ft_error(4);
		check_assets(map->map[y], &map, y, &assets);
		y++;
	}
}

void	check_assets(char *row, t_map *map, int y, t_assets *assets)
{
	int	x;

	x = 0;
	while (x <= map->width)
	{
		if (row[x] == 'p')
		{
			//increment_assets(&map, &assets, x, y);
			assets->player->x = x;
			assets->player->y = y;
			map->player++;
		}
		else if (row[x] == 'e')
		{
			assets->exit->y = y;
			assets->exit->x = x;
			map->exit++;
		}
		else if (row[x] == 'c')
		{
			//se for necessario alocar memoria para o array de coordenadas porque os collectibles serao mais que um
			map->collectible++;
		}
		x++;
	}
	if (map->player > 1)
		ft_error(5);
	else if (map->exit > 1)
		ft_error(6);
	else if (map->collectible < 1)
		ft_error(7);
}
