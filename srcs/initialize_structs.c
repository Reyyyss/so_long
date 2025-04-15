/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:08:32 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:07 by hcarrasq         ###   ########.fr       */
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

t_texture *init_texture(void)
{
	t_texture *tex;

	tex = malloc(sizeof(t_texture));
	tex->tree = init_empty_data();
	tex->inact_mine = init_empty_data();
	tex->act_mine = init_empty_data();
	tex->gold = init_empty_data();
	tex->player = init_empty_data();
	tex->canva = init_empty_data();

	return tex;
}
t_data init_empty_data(void)
{
	t_data data;

	data.img = NULL;
	data.addr = NULL;
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.endian = 0;
	return data;
}

t_data *init_data(void)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	return (data);
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
	so_long->data = init_data();
	so_long->img = init_texture();
	return so_long;
}

t_so_long *init_game(void)
{
	return init_so_long(0, 0);  // Initialize with width and height 0
}