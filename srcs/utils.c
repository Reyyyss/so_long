/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:00:01 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/26 15:27:53 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int panic)
{
	ft_printf("Error: %i\n", panic);
	//ft_free(row);
	exit (panic);
}

void	*ft_free(char *str)
{
	return (free(str), NULL);
}

void increment_assets(t_map *map, t_assets *assets, int x, int y)
{
	//se for meter o resto dos assets aqui preciso mandar para aqui uma flag
	//para saber oque incrementar
	assets->player->x = x;
	assets->player->y = y;
	map->player++;
}

/* void	initialize_struct(t_so_long *slong)
{
	slong{0};
} */