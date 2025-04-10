/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:08:32 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/10 18:53:44 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_cords *init_cords(int x, int y)
{
	t_cords *cords = malloc(sizeof(t_cords));
	cords->x = x;
	cords->y = y;
	return cords;
}

t_data *init_data(void)
{
	data.img = NULL;
	data.addr = NULL;
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.endian = 0;
}

t_assets *init_assets(void)
{
	t_assets *assets = malloc(sizeof(t_assets));
	assets->exit_reachable = 0;
	assets->collectibles_found = 0;
	assets->player = init_cords(0, 0);
	return assets;
}

t_map *init_map(size_t width, size_t height)
{
	t_map *map = malloc(sizeof(t_map));
	map->width = width;
	map->height = height;
	map->map = NULL;  // Initialize later when data is available
	map->map_fd = -1;
	map->error = 0;
	map->walls = 0;
	map->exit = 0;
	map->collectible = 0;
	map->player = 0;
	return map;
}

t_so_long *init_so_long(size_t width, size_t height)
{
	t_so_long *so_long = malloc(sizeof(t_so_long));
	so_long->map = init_map(width, height);
	so_long->ass = init_assets();
	so_long.
	return so_long;
}

t_so_long *init_game(void)
{
	return init_so_long(0, 0);  // Initialize with width and height 0
}