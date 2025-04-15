/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:35:56 by henrique-re       #+#    #+#             */
/*   Updated: 2025/04/13 17:46:44 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw(t_data *map, t_data *img, int x, int y)
{
	int	x_pixel
	int	y_pixel

	y = 0;
	while (y_pixel < 64)
	{
		x_pixel = 0
		while (x_pixel < 64)
		{
			my_mlx_pixel_put(img, x_pixel, y_pixel, my_mlx_pixel_get(map, x_pixel, y_pixel));
			x_pixel++;
		}
		y_pixel++;
	}
}