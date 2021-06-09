/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_black_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:29:12 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 17:29:20 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_black_screen(t_game *game)
{
	game->bs_value = 255;
	game->hud.loose_screen = bettermlx_init_xpm_image(game, game->window, \
		 "./textures/HUD_Die.xpm");
	game->hud.win_screen = bettermlx_init_xpm_image(game, game->window, \
		 "./textures/HUD_Win.xpm");
}
