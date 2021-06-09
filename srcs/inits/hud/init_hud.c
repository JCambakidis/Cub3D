/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:45:46 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 17:00:31 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hud(t_game *game)
{
	init_black_screen(game);
	game->hud.life_bar_empty = bettermlx_init_xpm_image(\
		game, game->window, "./textures/LifeBar_empty.xpm");
	game->hud.life_bar_empty = rescale_img(game, game->hud.life_bar_empty, \
		game->window->width / 15, game->window->height / 25);
	game->hud.life_bar_full = bettermlx_init_xpm_image(\
		game, game->window, "./textures/LifeBar_full.xpm");
	game->hud.life_bar_full = rescale_img(game, game->hud.life_bar_full, \
		game->window->width / 15, game->window->height / 25);
}
