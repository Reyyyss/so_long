/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:40:23 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/04/08 11:38:11 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key_code, t_so_long *slong)
{
	if (key_code == 65307)
		close_wnd(slong);
	ft_printf("%d\n", key_code);
	return (0);
}

