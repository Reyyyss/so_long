/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:40:23 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/15 14:44:17 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key_code, t_so_long *slong)
{
	if (key_code == 65307)
		close_wnd(slong);
	ft_printf("%d\n", key_code);
	return (0);
}

void	save_imgs(t_so_long *slong)
{
	slong->img->canva.img = mlx_new_image(slong->mlx, slong->map->width, slong->map->height);
	slong->img->act_mine = load_imgs("./textures/Active_Mine.xpm", slong);
	slong->img->floor = load_imgs("./textures/Floor.xpm", slong);
	slong->img->inact_mine = load_imgs("./textures/Inactive_Mine.xpm", slong);
	slong->img->tree = load_imgs("./textures/Player.xpm", slong);
	slong->img->player = load_imgs("./textures/tree.xpm", slong);
	slong->img->gold = load_imgs("./textures/Gold.xpm", slong);
	slong->img->canva.addr = mlx_get_data_addr(slong->img->canva.img,
	 						&slong->img->canva.bits_per_pixel, &slong->img->canva.line_length,
							&slong->img->canva.endian);
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

/* void	handler()
{
	
} */