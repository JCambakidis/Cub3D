/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:16:36 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:36:49 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_minimap(t_game *game)
{
	if (game->key_pressed.minimap && game->minimap.offset \
		< game->minimap.minimap->width)
		game->minimap.offset += 0.7 * game->delta_time;
	else if (!game->key_pressed.minimap && game->minimap.offset > 0)
		game->minimap.offset -= 0.7 * game->delta_time;
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, \
		game->minimap.background->img, game->window->width - \
			game->minimap.offset - 25, game->window->height / 2 - \
				game->minimap.minimap->height / 2 - 25);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, \
		game->minimap.minimap->img, game->window->width - \
			game->minimap.offset, game->window->height / 2 - \
				game->minimap.minimap->height / 2);
}
