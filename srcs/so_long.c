/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:07:18 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/10 18:08:25 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_wnd(t_so_long *slong)
{
	ft_printf("Ate a proxima\n");
	mlx_destroy_window(slong->mlx, slong->wnd);
	mlx_destroy_display(slong->mlx);
	free(slong->mlx);
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
	slong->wnd = mlx_new_window(slong->mlx, slong->map->width, slong->map->height, "so_long");
	save_imgs(slong);
	mlx_hook(slong->wnd, 17, 0, close_wnd, slong);
	mlx_hook(slong->wnd, 2, 1L<<0, key_hook, slong);
	mlx_loop(slong->mlx);
}


