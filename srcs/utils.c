/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:00:01 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/19 17:11:48 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int panic)
{
	ft_printf("Error\n");
	//ft_free(row);
	exit (panic);
}

static void	*ft_free(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	return (free(str), NULL);
}

increment_assets(t_map *map, t_assets *assets, int x, int y)
{
	//se for meter o resto dos assets aqui preciso mandar para aqui uma flag
	//para saber oque incrementar
	assets->player->x = x;
	assets->player->y = y;
	map->player++;
}