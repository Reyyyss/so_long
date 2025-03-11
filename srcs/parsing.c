/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:49:53 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/11 17:35:57 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(char *av)
{
	int	map_fd;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 3)
		return (close(map_fd));
	row_checker(map_fd);
}

row_checker(int map_fd)
{
	char	*row;
	int		i;

	i = 0;
	row = get_next_line(map_fd);
	while (i == 0)
	{
		
	}
}