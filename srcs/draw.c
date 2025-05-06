/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:35:56 by henrique-re       #+#    #+#             */
/*   Updated: 2025/05/06 12:12:33 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw(t_data src, t_data dst, int x, int y)
{
	int				x_pixel;
	int				y_pixel;
	unsigned int	color;

	y_pixel = 0;
	while (y_pixel < 64)
	{
		x_pixel = 0;
		while (x_pixel < 64)
		{
			color = my_mlx_pixel_get(&src, x_pixel, y_pixel);
			if (color != TRANSPARENT)
				my_mlx_pixel_put(&dst, x_pixel + x, y_pixel + y, color);
			x_pixel++;
		}
		y_pixel++;
	}
}

void	map_drawer(t_map *map, t_texture *img)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				draw(img->tree, img->canva, x * 64, y * 64);
			else if (map->map[y][x] == '0' || map->map[y][x] == 'P'
				|| map->map[y][x] == 'C')
				draw(img->floor, img->canva, x * 64, y * 64);
			else if (map->map[y][x] == 'E')
				draw(img->inact_mine, img->canva, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
