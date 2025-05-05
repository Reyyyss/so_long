/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free3000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:18:13 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/01 16:21:15 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_cords(t_cords *cords)
{
	if (cords)
		free(cords);
}

void free_data(t_data *data)
{
	if (data)
		free(data);
}

void free_texture(t_texture *tex)
{
	if (tex)
		free(tex);
}

void free_assets(t_assets *assets) {
	if (assets) {
		if (assets->exit)
			free_cords(assets->exit);
		if (assets->player) 
			free_cords(assets->player);
		free(assets);
	}
	}

void free_so_long(t_so_long *so_long)
{
	if (so_long) 
	{
		if (so_long->ass)
			free_assets(so_long->ass);
		if (so_long->data)
			free_data(so_long->data);
		if (so_long->img)
			free_texture(so_long->img);
		free(so_long);
	}
}
