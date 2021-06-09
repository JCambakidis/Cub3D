/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouvement2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:51:40 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 17:15:38 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_attack_checker(t_game *game)
{
	game->player.attack.pressed_state = FALSE;
	game->key_pressed.attack_pressed = FALSE;
	if (game->player.guard.pressed_state)
	{
		game->player.current_anim = game->player.anims[4];
		game->player.speed_constraint = 0.3;
		game->player.guard.in_state = TRUE;
	}
	if (game->player.run.pressed_state && \
	game->key_pressed.sprint_pressed)
	{
		game->player.speed_constraint = 1.5;
		game->player.current_anim = game->player.anims[1];
		game->player.current_anim->animation_refresh_time = 7;
	}
	else if (game->player.run.pressed_state)
		game->player.current_anim = game->player.anims[1];
	else
		game->player.current_anim = game->player.anims[0];
}

void	player_attack(t_game *game)
{
	if (game->player.attack.pressed_state && \
		game->player.guard.in_state == FALSE)
	{
		if (game->player.current_anim->animation_index_width == 2 \
			&& game->player.attack.in_state)
		{
			attack(game);
			game->player.attack.in_state = FALSE;
		}
		if (game->player.current_anim->animation_index_width == \
		game->player.anims[3]->animation_frames_width - 1)
			player_attack_checker(game);
	}
}

t_vector3	displacement_value_y(t_game *game, t_vector3 *fpl, int direction)
{
	return (add_vector_vector(*fpl, rotate_vector_z(\
				create_vector(0, (game->player.speed * direction) * game->delta_time * \
					game->player.speed_constraint, 0), \
						game->player.orientationx * RADIAN)));
}

t_vector3	displacement_value_x(t_game *game, t_vector3 *fpl, int direction)
{
	return (add_vector_vector(*fpl, rotate_vector_z(\
				create_vector((game->player.speed * direction) * game->delta_time * \
					game->player.speed_constraint, 0, 0), \
						game->player.orientationx * RADIAN)));
}

void	player_displacement(t_game *game, t_vector3 *fpl)
{
	if (game->key_pressed.s_pressed || game->key_pressed.w_pressed \
		|| game->key_pressed.a_pressed || game->key_pressed.d_pressed)
	{
		if (game->key_pressed.w_pressed)
			*fpl = displacement_value_y(game, fpl, -1);
		if (game->key_pressed.s_pressed)
			*fpl = displacement_value_y(game, fpl, 1);
		if (game->key_pressed.a_pressed)
			*fpl = displacement_value_x(game, fpl, -1);
		if (game->key_pressed.d_pressed)
			*fpl = displacement_value_x(game, fpl, 1);
		quicksort_enemys_by_distance(game, 0, game->map.enemy_counter - 1);
		quicksort_power_ups_by_distance(game, 0, \
			game->map.power_up_counter - 1);
	}
}
