/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:42:51 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/06 13:25:31 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	floodfill(char **map_copied, t_assets *assets, int x, int y)
{
	if (x < 0 || y < 0 || map_copied[y][x] == '1' || map_copied[y][x] == 'W')
		return ;
	if (map_copied[y][x] == 'C')
		assets->collectibles_found++;
	if (map_copied[y][x] == 'E')
		assets->exit_reachable = 1;
	map_copied[y][x] = 'W';
	floodfill(map_copied, assets, x + 1, y);
	floodfill(map_copied, assets, x - 1, y);
	floodfill(map_copied, assets, x, y + 1);
	floodfill(map_copied, assets, x, y - 1);
}
