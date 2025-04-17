/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:35:31 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/17 16:33:18 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handler(int keycode, t_so_long *slong)
{
	if (keycode == XK_Escape)
		close_wnd(slong);
	printf("%d\n", keycode);
	player_handler(slong, keycode);
	run_game(slong);
	return 0;
}

void	player_handler(t_so_long *slong, int keycode)
{
	if (keycode == XK_w && slong->map->map[slong->ass->player->y - 1][slong->ass->player->x] != '1')
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->y--;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_s && slong->map->map[slong->ass->player->y + 1][slong->ass->player->x] != '1')
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->y++;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_d && slong->map->map[slong->ass->player->y][slong->ass->player->x + 1] != '1')
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->x++;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_a && slong->map->map[slong->ass->player->y][slong->ass->player->x - 1] != '1')
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->x--;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
}

void	collectible_handler(t_so_long *slong)
{
	size_t	y;
	size_t	x;
	int	c;

	y = 0;
	c = 0;
	while (y < slong->map->height)
	{
		x = 0;
		while (x < slong->map->width)
		{
			if (slong->map->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c == 0)
	{
		game_over()
	}
}

void	run_game(t_so_long *slong)
{
	size_t	x;
	size_t	y;

	y = 0;
	printf("%d\n",slong->ass->player->x);
	mlx_clear_window(slong->mlx, slong->wnd);
	mlx_put_image_to_window(slong->mlx, slong->wnd, slong->img->canva.img, 0, 0);
	while (y < slong->map->height)
	{
		x = 0;
		while (x < slong->map->width)
		{
			if (slong->map->map[y][x] == 'P')
				mlx_put_image_to_window(slong->mlx, slong->wnd, slong->img->player.img, slong->ass->player->x * 64, slong->ass->player->y * 64);
			x++;
		}
		y++;
	}
}
