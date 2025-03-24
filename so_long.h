/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:55:08 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/19 19:34:04 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 500
#define HEIGHT 500



typedef struct s_cords
{
	int x;
	int y;
}	t_cords;

typedef struct s_assets
{
	t_cords *exit;
	t_cords *collectible;
	t_cords *player;
}	t_assets;

typedef struct s_map
{
	char	**map;
	int		error;
	int		width;
	int		height;
	int		walls;
	int		exit;
	int		collectible;
	int		player;
}	t_map;

typedef struct s_so_long
{
	int	width;
	int height;
	t_map *map;
	t_assets *ass;
}	t_so_long;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

#endif