/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:07:18 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/24 16:11:53 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*mlx_win;
	int		len;
	t_so_long	slong;

	//map_init(&slong.map);
	/* mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");
	mlx_pixel_put(mlx, mlx_win, 128, 128, 0xFF0000);
	mlx_loop(mlx); */

	if (ac != 2 || ft_strlen(av[1]) < 5)
		return (write(2, "Error\n", 6));
	len = ft_strlen(av[1]);
	if (ft_strncmp(".ber", av[1] + ft_strlen(av[1]) - 4, 4))
		return (write(2, "Error\n", 6));
	map_parsing(av[1], slong.map, slong.ass);
}

