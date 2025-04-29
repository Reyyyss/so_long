/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:07:18 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/29 02:06:03 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_wnd(t_so_long *slong)
{
	ft_printf("Ate a proxima\n");
	mlx_destroy_window(slong->mlx, slong->wnd);
	mlx_destroy_display(slong->mlx);
	free_everything(slong);
	exit (0);
}
int	main(int ac, char **av)
{
	t_so_long	*slong;


	if (ac != 2 )//|| ft_strlen(av[1]) < 5)
		return (write(2, "Error1\n", 6));
	if (ft_strncmp(".ber", av[1] + ft_strlen(av[1]) - 4, 4))
		return (write(2, "Error2\n", 6));
	slong = init_game();
	map_parsing(av[1], slong->map, slong->ass);

	slong->mlx = mlx_init();
	save_imgs(slong);
	map_drawer(slong->map, slong->img);
	slong->wnd = mlx_new_window(slong->mlx, slong->map->width * 64, slong->map->height * 64, "so_long");
	mlx_key_hook(slong->wnd, handler, slong);
	mlx_put_image_to_window(slong->mlx, slong->wnd, slong->img->canva.img, 0, 0);
	mlx_hook(slong->wnd, 17, 0, close_wnd, slong);
	mlx_loop(slong->mlx);
}


