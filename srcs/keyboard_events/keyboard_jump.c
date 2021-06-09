/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_jump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:04:10 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:39:46 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	jump_out_state(t_game *game, t_player *player)
{
	if (player->jump.out_state)
	{
		player->location = add_vector_vector(player->location, \
			rotate_vector_z(create_vector(0, 0, -JUMP_SPEED - 0.002 * game->delta_time), \
				player->orientationx * RADIAN));
		if (player->location.vz <= 0.5)
		{
			player->location.vz = 0.5;
			player->jump.pressed_state = FALSE;
			player->jump.out_state = FALSE;
			if (game->player.run.pressed_state && \
				game->key_pressed.sprint_pressed)
			{
				game->player.speed_constraint = 1.5;
				game->player.current_anim = player->anims[1];
				game->player.current_anim->animation_refresh_time = 7;
			}
			else if (player->run.pressed_state)
				player->current_anim = player->anims[1];
			else
				player->current_anim = player->anims[0];
		}
	}
}

void	jump_in_state(t_game *game, t_player *player)
{
	if (player->jump.in_state)
	{
		player->location = add_vector_vector(player->location, \
			rotate_vector_z(create_vector(0, 0, JUMP_SPEED * game->delta_time), \
				player->orientationx * RADIAN));
		if (player->location.vz >= 0.96)
		{
			player->jump.in_state = FALSE;
			player->jump.out_state = TRUE;
		}
	}
}

void	jump(t_game *game, t_player *player)
{
	if (player->jump.pressed_state && !player->guard.pressed_state)
	{
		if (game->delta_time >= 1000 / 60)
		{
			jump_in_state(game, player);
			jump_out_state(game, player);
		}
	}
}
