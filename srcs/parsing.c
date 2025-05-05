/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/05 17:35:19 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_parsing(char *av, t_map *map, t_assets *assets, t_so_long *slong)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd < 3)
	{
		close(map->map_fd);
		ft_error(1, slong);
	}
	row_checker(map, slong);
	if (map->height < 3 || map->width < 3)
		ft_error(3, slong); // 3 = map dont have enough space
	map->map_fd = open(av, O_RDONLY);
	map_copy(map);
	map_checker(map, slong); // largura = 30 e altura = 16 (maximos)
	check_assets(assets, 0, 0, slong);
	floodfill(map->map_copied, assets, assets->player->x, assets->player->y);
	if (assets->exit_reachable != 1 || assets->collectibles_found != map->collectible)
		ft_error(9, slong);
	close(map->map_fd);
}

void	row_checker(t_map *map, t_so_long *slong)
{
	char	*row;

	row = get_next_line(map->map_fd);
	if (!row)
		ft_error(1, slong); // 1 = the map file has nothing
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
			ft_error(2, slong); // 2 = the map is not retangular
		}
	}
	free(row);
	close(map->map_fd);
}

void	map_checker(t_map *map, t_so_long *slong)
{
	size_t	y;

	y = 0;
	if (map->height > 16 || map->width > 30)
		ft_error(1, slong);
	while (y < map->height)
	{
		if (ft_strcharcmp('1', map->map[0], map->width) != 0)
			ft_error(4, slong);// 4 = map not enclosed by walls
		else if (map->map[y][0] != '1' && map->map[y][map->width] != '1')
			ft_error(1, slong);
		else if (ft_strcharcmp('1', map->map[map->height - 1], map->width) != 0)
			ft_error(1, slong);
		y++;
	}
}

void	check_assets(t_assets *assets, size_t x, size_t y, t_so_long *slong)
{
	y = -1;
	while (++y < slong->map->height)
	{
		x = -1;
		while (++x < slong->map->width)
		{
			if (slong->map->map[y][x] == 'P')
				increment_assets(slong->map, assets, x, y);
			else if (slong->map->map[y][x] == 'E')
				increment_assets(slong->map, assets, x, y);
			else if (slong->map->map[y][x] == 'C')
				slong->map->collectible++;
			else if (slong->map->map[y][x] == '1' || slong->map->map[y][x] == '0')
				continue;
			else
				ft_error(2, slong);
		}
	}
	if (slong->map->player > 1 || slong->map->player < 1)
		ft_error(5, slong);
	else if (slong->map->exit > 1 || slong->map->exit < 1)
		ft_error(6, slong);
	else if (slong->map->collectible < 1)
		ft_error(7, slong);
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
		free(row);
		row = get_next_line(map->map_fd);
		y++;
	}
	free(row);
	close(map->map_fd);
}
