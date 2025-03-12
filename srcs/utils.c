/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:00:01 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/12 15:28:26 by hcarrasq         ###   ########.fr       */
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