/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:25:37 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/06 19:37:21 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*init_map(size_t width, size_t height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = width;
	map->height = height;
	map->map = NULL;
	map->map_fd = -1;
	map->error = 0;
	map->walls = 0;
	map->exit = 0;
	map->collectible = 0;
	map->player = 0;
	return (map);
}

t_so_long	*init_so_long(size_t width, size_t height)
{
	t_so_long	*so_long;

	so_long = malloc(sizeof(t_so_long));
	so_long->map = init_map(width, height);
	so_long->ass = init_assets();
	so_long->data = init_data();
	so_long->img = init_texture();
	so_long->moves = 0;
	return (so_long);
}

t_so_long	*init_game(void)
{
	return (init_so_long(0, 0));
}
