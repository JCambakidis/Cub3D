/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_loose_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:09:44 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:40:32 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_loose_life(t_game *game, t_player *player)
{
	play_sound("playerhurt.wav", 2);
	if (player->life > 0)
		player->life--;
	if (player->life <= 0)
	{
		game->hud.black_screen = game->hud.loose_screen;
		game->game_end = TRUE;
		stop_sounds();
		play_sound("gameover.mp3", 1);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, game->player.hit->img, 0, 0);
}
