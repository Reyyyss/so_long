/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:55:08 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/26 15:41:04 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <aio.h>
# include <stddef.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

#define WIDTH 500
#define HEIGHT 500


typedef struct s_cords
{
	int x;
	int y;
}	t_cords;

typedef struct s_assets
{
	int	exit_reachable;
	int	collectibles_found;
	t_cords *exit;
	t_cords *collectible;
	t_cords *player;
}	t_assets;

typedef struct s_map
{
	char		**map;
	int			error;
	size_t		width;
	size_t		height;
	int			walls;
	int			exit;
	int			collectible;
	int			player;
}	t_map;

typedef struct s_so_long
{
	size_t	width;
	size_t	height;
	t_map *map;
	t_assets *ass;
}	t_so_long;


void	map_parsing(char *av, t_map *map, t_assets *assets);
void	row_checker(int map_fd, t_map *map);
void	map_checker(int map_fd, t_map *map, t_assets *assets);
void	check_assets(char *row, t_map *map, int y, t_assets *assets);
void	floodfill(t_map *map, t_assets *assets, int x, int y);
void	ft_error(int panic);
void	*ft_free(char *str);
void	increment_assets(t_map *map, t_assets *assets, int x, int y);

#endif