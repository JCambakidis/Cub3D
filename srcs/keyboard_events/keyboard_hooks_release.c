/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks_release.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:22:12 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:29:58 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_release(t_game *game)
{
	if (!game->key_pressed.d_pressed && !game->key_pressed.a_pressed \
		&& !game->key_pressed.w_pressed && !game->key_pressed.s_pressed)
	{
		if (game->player.jump.pressed_state == FALSE && \
			game->player.attack.pressed_state == FALSE && \
				game->player.guard.pressed_state == FALSE)
			game->player.current_anim = game->player.anims[0];
		game->player.idle.pressed_state = TRUE;
		game->player.run.pressed_state = FALSE;
		game->player.run.in_state = FALSE;
		game->player.run.out_state = FALSE;
	}
}

void	action_key_release(int key, t_game *game)
{
	if (key == 261)
		game->key_pressed.attack_pressed = FALSE;
	if (key == 258)
		release_guard(game);
}

void	special_mouvement_key_release(int key, t_game *game)
{
	if (key == 49)
		game->key_pressed.fly_up_pressed = FALSE;
	if (key == 257)
	{
		game->key_pressed.fly_down_pressed = FALSE;
		game->key_pressed.sprint_pressed = FALSE;
		if (!game->player.guard.pressed_state)
		{
			game->player.speed_constraint = 1;
			if (game->key_pressed.w_pressed || game->key_pressed.s_pressed \
				|| game->key_pressed.a_pressed || game->key_pressed.d_pressed)
				game->player.current_anim->animation_refresh_time = 3;
		}
	}
	if (key == 48)
		game->key_pressed.minimap = FALSE;
}

void	mouvement_key_release(int key, t_game *game)
{
	if (key == 13)
	{
		game->key_pressed.w_pressed = FALSE;
		run_release(game);
	}
	if (key == 1)
	{
		game->key_pressed.s_pressed = FALSE;
		run_release(game);
	}
	if (key == 0)
	{
		game->key_pressed.a_pressed = FALSE;
		run_release(game);
	}
	if (key == 2)
	{
		game->key_pressed.d_pressed = FALSE;
		run_release(game);
	}
}

int	key_release_hook(int key, t_game *game)
{
	if (key == 123)
		game->key_pressed.down_pressed = FALSE;
	if (key == 124)
		game->key_pressed.up_pressed = FALSE;
	if (key == 125)
		game->key_pressed.left_pressed = FALSE;
	if (key == 126)
		game->key_pressed.right_pressed = FALSE;
	mouvement_key_release(key, game);
	special_mouvement_key_release(key, game);
	action_key_release(key, game);
	return (0);
}
