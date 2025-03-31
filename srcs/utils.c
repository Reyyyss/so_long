/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:00:01 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/31 16:04:26 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int panic)
{
	// ft_free(row);
	ft_printf("Error: %i\n", panic);
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

int	ft_strcharcmp(const char s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1 == s2[i] && i < n - 1 && (s1 != '\0' || s2[i] != '\0'))
		i++;
	return ((unsigned char)s1 - (unsigned char)s2[i]);
}

/* void	initialize_struct(t_so_long *slong)
{
	slong{0};
} */