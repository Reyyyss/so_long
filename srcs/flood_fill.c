/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:42:51 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/02 17:28:52 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void floodfill(t_map *map, t_assets *assets, int x, int y)
{
	if (x < 0 || y < 0 || map->map[y][x] == '1' || map->map[y][x] == 'W')
		return;
	if (map->map[y][x] == 'C')
		assets->collectibles_found++;
	if (map->map[y][x] == 'E')
		assets->exit_reachable = 1;
	map->map[y][x] = 'W';
	floodfill(map, assets, x + 1, y);
	floodfill(map, assets, x - 1, y);
	floodfill(map, assets, x, y + 1);
	floodfill(map, assets, x, y - 1);
}
