/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks_release2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:44:01 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 14:26:16 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	release_guard(t_game *game)
{
	game->key_pressed.guard_pressed = FALSE;
	game->player.guard.pressed_state = FALSE;
	game->player.guard.in_state = FALSE;
	game->player.speed_constraint = 1;
	if (game->player.run.pressed_state == TRUE \
		&& game->key_pressed.sprint_pressed)
	{
		game->player.speed_constraint = 1.5;
		game->player.current_anim = game->player.anims[1];
		game->player.current_anim->animation_refresh_time = 7;
	}
	else if (game->player.run.pressed_state == TRUE)
		game->player.current_anim = game->player.anims[1];
	else
		game->player.current_anim = game->player.anims[0];
}
