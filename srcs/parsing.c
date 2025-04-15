/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/15 18:56:08 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_parsing(char *av, t_map *map, t_assets *assets)
{
	//ft_printf("%s", av);
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd < 3)
	{
		close(map->map_fd);
		return;
	}
	row_checker(map);
	if (map->height < 3 || map->width < 3)
		ft_error(3); // 3 = map dont have enough space
	map->map_fd = open(av, O_RDONLY);
	map_copy(map);
	map_checker(map); // largura = 30 e altura = 16 (maximos)
	check_assets(map, assets, 0, 0);
	printf("%s\n", map->map[1]);
	floodfill(map->map_copied, assets, assets->player->x, assets->player->y);
	printf("%s\n", map->map[1]);
	if (assets->exit_reachable != 1 || assets->collectibles_found != map->collectible)
		ft_error(9);
	close(map->map_fd);
}

void	row_checker(t_map *map)
{
	char	*row;

	row = get_next_line(map->map_fd);
	if (!row)
		ft_error(1); // 1 = the map file has nothing
	map->width = ft_linelen(row);
	map->height = 0;
	while (row && row != NULL)
	{
		map->height++;
		free(row);
		row = get_next_line(map->map_fd);
		if (ft_linelen(row) != map->width && ft_linelen(row) > 0)
		{
			free(row);
			close (map->map_fd);
			ft_error(2); // 2 = the map is not retangular
		}
	}
	free(row);
	close(map->map_fd);
}

void	map_checker(t_map *map)
{
	size_t	y;

	y = 0;
	if (map->height > 16 || map->width > 30)
		ft_error(15);
	while (y < map->height)
	{
		if (ft_strcharcmp('1', map->map[0], map->width) != 0)
			ft_error(4);// 4 = map not enclosed by walls
		else if (map->map[y][0] != '1' && map->map[y][map->width] != '1')
			ft_error(10);
		else if (ft_strcharcmp('1', map->map[map->height - 1], map->width) != 0)
			ft_error(11);
		y++;
	}
}

void	check_assets(t_map *map, t_assets *assets, size_t x, size_t y)
{
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'P')
				increment_assets(map, assets, x, y);
			else if (map->map[y][x] == 'E')
				map->exit++;
			else if (map->map[y][x] == 'C')
				map->collectible++;
			else if (map->map[y][x] == '1' || map->map[y][x] == '0')
				continue;
			else
				ft_error(20);
		}
	}
	if (map->player > 1 || map->player < 1)
		ft_error(5);
	else if (map->exit > 1 || map->exit < 1)
		ft_error(6);
	else if (map->collectible < 1)
		ft_error(7);
}

void	map_copy(t_map *map)
{
	size_t	y;
	char	*row;

	y = 0;
	row = get_next_line(map->map_fd);
	map->map = malloc(map->height * sizeof(char *));
	map->map_copied = malloc(map->height * sizeof(char *));
	if (!map->map)
		return;
	while (y < map->height)
	{
		map->map[y] = ft_strdup(row);
		map->map_copied[y] = ft_strdup(row);
		row = get_next_line(map->map_fd);
		y++;
	}
	y = 0;
	while (y < map->height)
		y++;
	ft_printf("\n");
}
