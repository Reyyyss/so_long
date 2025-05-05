/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:40:23 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/01 16:25:32 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	save_imgs(t_so_long *slong)
{
	slong->img->canva.img = mlx_new_image(slong->mlx, slong->map->width * 64,
							 slong->map->height * 64);
	slong->img->act_mine = load_imgs("./textures/Active_Mine.xpm", slong);
	slong->img->floor = load_imgs("./textures/Floor.xpm", slong);
	slong->img->inact_mine = load_imgs("./textures/Inactive_Mine.xpm", slong);
	slong->img->tree = load_imgs("./textures/tree.xpm", slong);
	slong->img->player = load_imgs("./textures/Player.xpm", slong);
	slong->img->gold = load_imgs("./textures/Gold.xpm", slong);
	slong->img->canva.addr = mlx_get_data_addr(slong->img->canva.img,
	 						&slong->img->canva.bits_per_pixel,
							 &slong->img->canva.line_length,
							&slong->img->canva.endian);
}

void	free_everything(t_so_long *slong)
{
	size_t	i;

	i = -1;
	if (slong->map)
	{
		if (slong->map->map)
		{
			while (++i < slong->map->height)
			{
				free(slong->map->map[i]);
				free(slong->map->map_copied[i]);
			}
			free(slong->map->map);
			free(slong->map->map_copied);
		}
		free(slong->map);
	}
	free_so_long(slong);
}

t_data	load_imgs(char *path, t_so_long *slong)
{
	t_data	img;
	int	height;
	int	width;

	width = 0;
	height = 0;
	img.img = mlx_xpm_file_to_image(slong->mlx, path, &width, &height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
					&img.endian);
	return (img);
}

void	game_over(t_so_long *slong)
{
	size_t	x;
	size_t	y;

	y = 0;
	mlx_put_image_to_window(slong->mlx, slong->wnd, slong->img->act_mine.img, 
	slong->ass->exit->x * 64, slong->ass->exit->y * 64);
	while (y < slong->map->height)
	{
		x = 0;
		while (x < slong->map->width)
		{
			if (slong->ass->player->x == slong->ass->exit->x 
			&& slong->ass->player->y == slong->ass->exit->y)
				close_wnd(slong);
			x++;
		}
		y++;
	}
}

void	movement_handle(t_so_long *slong, int keycode)
{
	if (keycode == XK_w)
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->y--;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_s)
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->y++;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_d)
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->x++;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
	if (keycode == XK_a)
	{
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = '0';
		slong->ass->player->x--;
		slong->map->map[slong->ass->player->y][slong->ass->player->x] = 'P';
	}
}
