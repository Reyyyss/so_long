/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:55:08 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/17 16:23:12 by hcarrasq         ###   ########.fr       */
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
# include <X11/keysym.h>

# define TRANSPARENT 0xFF000000

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
	t_cords	*exit;
	t_cords *player;
}	t_assets;

typedef struct s_map
{
	char		**map;
	char		**map_copied;
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
	t_data floor;
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
	t_data *data;
	void	*mlx;
	void	*wnd;
}	t_so_long;



void		map_parsing(char *av, t_map *map, t_assets *assets);
void		row_checker(t_map *map);
void		map_checker(t_map *map);
void		check_assets(t_map *map, t_assets *assets, size_t x, size_t y);
void		floodfill(char **map_copied, t_assets *assets, int x, int y);
void		ft_error(int panic);
void		*ft_free(char *str);
void		increment_assets(t_map *map, t_assets *assets, int x, int y);
int			ft_strcharcmp(const char s1, const char *s2, size_t n);
void		map_copy(t_map *map);
t_cords		*init_cords(int x, int y);
t_assets	*init_assets(void);
t_map		*init_map(size_t width, size_t height);
t_so_long	*init_so_long(size_t width, size_t height);
t_texture 	*init_texture(void);
t_data 		init_empty_data(void);
t_so_long	*init_game(void);
t_data		*init_data(void);
size_t		ft_linelen(char *str);
int			key_hook(int key_code, t_so_long *slong);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			my_mlx_pixel_get(t_data *data, int x, int y);
int			close_wnd(t_so_long *slong);
void		save_imgs(t_so_long *slong);
t_data		load_imgs(char *path, t_so_long *slong);
void		map_drawer(t_map *map, t_texture *img);
void		draw(t_data src, t_data dst, int x, int y);
void		free_everything(t_so_long *slong);
int			handler(int keycode, t_so_long *slong);
void		player_handler(t_so_long *slong, int keycode);
void		run_game(t_so_long *slong);
void		print_map(t_map *map);

#endif