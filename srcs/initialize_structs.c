/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:08:32 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/06 17:26:37 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_cords	*init_cords(int x, int y)
{
	t_cords	*cords;

	cords = malloc(sizeof(t_cords));
	cords->x = x;
	cords->y = y;
	return (cords);
}

t_texture	*init_texture(void)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	tex->tree = init_empty_data();
	tex->inact_mine = init_empty_data();
	tex->act_mine = init_empty_data();
	tex->gold = init_empty_data();
	tex->player = init_empty_data();
	tex->canva = init_empty_data();
	return (tex);
}

t_data	init_empty_data(void)
{
	t_data	data;

	data.img = NULL;
	data.addr = NULL;
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.endian = 0;
	return (data);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	return (data);
}

t_assets	*init_assets(void)
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	assets->exit_reachable = 0;
	assets->collectibles_found = 0;
	assets->exit = init_cords(0, 0);
	assets->player = init_cords(0, 0);
	return (assets);
}
