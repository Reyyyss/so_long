/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:42:51 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/19 17:11:58 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void floodfill(t_map *map, t_assets *assets, int x, int y) 
{
    if (x < 0 || y < 0 || map->map[y][x] == '1' || map->map[y][x] == 'W')
        return;
    map->map[y][x] == 'W';
    //preciso de meter uma cena na struct de collectible found e exit reachable
    //e se a nao conseguir chegar a saida dar erro
    //se as collectible founds for diferente das collectibles existentes dar erro
    floodfill(x + 1, y);
    floodfill(x - 1, y);
    floodfill(x, y + 1);
    floodfill(x, y - 1);
}