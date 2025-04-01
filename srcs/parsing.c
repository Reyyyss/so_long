/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/01 17:04:56 by hcarrasq         ###   ########.fr       */
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
	{
		ft_printf("%d\n", map->height);
		ft_printf("%d\n", map->width);
		ft_error(3); // 3 = map dont have enough space
	}
	map->map_fd = open(av, O_RDONLY);
	map_copy(map);
	map_checker(map); // largura = 30 e altura = 16 (maximos)
	check_assets(map, assets);
	floodfill(map, assets, assets->player->x, assets->player->y);
	ft_printf("%i", assets->collectibles_found);
	close(map->map_fd);
}

void	row_checker(t_map *map)
{
	char	*row;

	row = get_next_line(map->map_fd);
	if (!row)
		ft_error(1); // 1 = the map file has nothing
	map->width = ft_strlen(row);
	map->height = 0;
	while (row && row != NULL)
	{
		//ft_printf("row: %s\n", row);
		map->height++;
		free(row);
		row = get_next_line(map->map_fd);
		// ft_printf("height: %d\n", map->height);
		// ft_printf("%d\n", map->width);
		// if (ft_strlen(row) != map->width)
		// {
		// 	free(row);
		// 	close (map->map_fd);
		// 	ft_error(2); // 2 = the map is not retangular
		// }
	}
	free(row);
	close(map->map_fd);
}

void	map_checker(t_map *map)
{
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		// ft_printf("%s", map->map[map->height - 1]);
		// map->map[y] = ft_strdup(get_next_line(map->map_fd));
		if (ft_strcharcmp('1', map->map[0], map->width) == 0)
			ft_error(4);// 4 = map not enclosed by walls
		else if (map->map[y][0] != '1' && map->map[y][map->width] != '1')
			ft_error(10);
		else if (ft_strcharcmp('1', map->map[map->height - 1], map->width) == 0)
			ft_error(11);
		y++;
	}
}

void	check_assets(t_map *map, t_assets *assets)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		if (map->map[y][x] == 'P')
		{
			//increment_assets(&map, &assets, x, y);
			assets->player->x = x;
			assets->player->y = y;
			map->player++;
		}
		else if (map->map[y][x] == 'E')
			map->exit++;
		else if (map->map[y][x] == 'C')
		{
			//se for necessario alocar memoria para o array de coordenadas porque os collectibles serao mais que um
			map->collectible++;
		}
		x++;
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
	if (!map->map)
		return;
	while (y < map->height)
	{
		map->map[y] = row;
		row = get_next_line(map->map_fd);
		y++;
	}
	y = 0;
	while (y < map->height)
	{
		ft_printf("linha %d: %s", y, map->map[y]);
		y++;
	}
	ft_printf("\n");
}
