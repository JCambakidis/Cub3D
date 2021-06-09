/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk_anim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:43:08 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 15:56:35 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_states(t_player *player)
{
	if (!player->run.in_state && player->location.vz < 0.45)
	{
		if (random_in_range(0, 10) > 5)
			play_sound("footstep1.mp3", 1);
		else
			play_sound("footstep2.mp3", 1);
		player->run.in_state = TRUE;
	}
	if (player->run.in_state && player->location.vz > 0.55)
	{
		player->run.in_state = FALSE;
		if (player->run_animation_side)
			player->run_animation_side = FALSE;
		else
			player->run_animation_side = TRUE;
	}
}

void	run_in_state(t_game *game, t_player *player)
{
	float	tmp;

	tmp = player->speed_constraint * game->delta_time;
	player->location.vz += 0.0004 * tmp;
	if (player->position_sprite.istop > 0)
		player->position_sprite.istop -= 0.09 * tmp;
	if (player->position_sprite.istart > 0)
		player->position_sprite.istart -= 0.09 * tmp;
	else if (player->position_sprite.istart < 0)
		player->position_sprite.istart += 0.09 * tmp;
}

void	run_out_state(t_game *game, t_player *player)
{
	float	tmp;

	tmp = player->speed_constraint * game->delta_time;
	player->location.vz -= 0.0004 * tmp;
	player->position_sprite.istop += 0.09 * tmp;
	if (player->run_animation_side)
		player->position_sprite.istart += 0.09 * tmp;
	else
		player->position_sprite.istart -= 0.09 * tmp;
}

void	replace_elements(t_player *player)
{
	if (player->location.vz != 0.5)
		player->location.vz = 0.5;
	if (player->position_sprite.istart != 0 || \
		player->position_sprite.istop != 0)
	{
		player->position_sprite.istart = 0;
		player->position_sprite.istop = 0;
	}
	player->run.in_state = TRUE;
}

void	player_walk_anim(t_game *game, t_player *player)
{
	if (player->run.pressed_state && !player->jump.pressed_state \
		&& !player->guard.pressed_state && game->player.debug_mode == 0)
	{
		if (game->delta_time >= 1000 / 60)
		{
			switch_states(player);
			if (player->run.in_state)
				run_in_state(game, player);
			if (!player->run.in_state)
				run_out_state(game, player);
		}
	}
	else if (!player->run.pressed_state && !player->jump.pressed_state \
		&& !player->guard.pressed_state && game->player.debug_mode == 0)
		replace_elements(player);
}
