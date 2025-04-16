/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:40:23 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/16 12:39:13 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	save_imgs(t_so_long *slong)
{
	slong->img->canva.img = mlx_new_image(slong->mlx, slong->map->width * 64, slong->map->height * 64);
	slong->img->act_mine = load_imgs("./textures/Active_Mine.xpm", slong);
	slong->img->floor = load_imgs("./textures/Floor.xpm", slong);
	slong->img->inact_mine = load_imgs("./textures/Inactive_Mine.xpm", slong);
	slong->img->tree = load_imgs("./textures/tree.xpm", slong);
	slong->img->player = load_imgs("./textures/Player.xpm", slong);
	slong->img->gold = load_imgs("./textures/Gold.xpm", slong);
	slong->img->canva.addr = mlx_get_data_addr(slong->img->canva.img,
	 						&slong->img->canva.bits_per_pixel, &slong->img->canva.line_length,
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
	if (slong->ass)
	{
		if (slong->ass->player)
			free(slong->ass->player);
		free(slong->ass);
	}
	if (slong->data)
		free(slong->data);
	if (slong->img)
		free(slong->img);
	free(slong);
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
