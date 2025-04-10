/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:55:08 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/10 18:09:57 by hcarrasq         ###   ########.fr       */
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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cords
{
	int x;
	int y;
}	t_cords;

typedef struct s_assets
{
	int	exit_reachable;
	int	collectibles_found;
	t_cords *player;
}	t_assets;

typedef struct s_map
{
	char		**map;
	int			map_fd;
	int			error;
	size_t		width;
	size_t		height;
	int			walls;
	int			exit;
	int			collectible;
	int			player;
}	t_map;

typedef struct s_texture
{
	t_data tree;
	t_data inact_mine;
	t_data act_mine;
	t_data gold;
	t_data player;
	t_data canva;
}	t_texture;

typedef struct s_so_long
{
	t_map *map;
	t_assets *ass;
	t_texture *img;
	void	*mlx;
	void	*wnd;
}	t_so_long;



void		map_parsing(char *av, t_map *map, t_assets *assets);
void		row_checker(t_map *map);
void		map_checker(t_map *map);
void		check_assets(t_map *map, t_assets *assets, size_t x, size_t y);
void		floodfill(t_map *map, t_assets *assets, int x, int y);
void		ft_error(int panic);
void		*ft_free(char *str);
void		increment_assets(t_map *map, t_assets *assets, int x, int y);
int			ft_strcharcmp(const char s1, const char *s2, size_t n);
void		map_copy(t_map *map);
t_cords		*init_cords(int x, int y);
t_assets	*init_assets(void);
t_map		*init_map(size_t width, size_t height);
t_so_long	*init_so_long(size_t width, size_t height);
t_so_long	*init_game(void);
size_t		ft_linelen(char *str);
int			key_hook(int key_code, t_so_long *slong);
int			close_wnd(t_so_long *slong);
void		save_imgs(t_so_long *slong);
t_data		load_imgs(char *path, t_so_long *slong);

#endif