/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks_press.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:49:36 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:29:42 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_press(t_game *game)
{
	if (game->player.jump.pressed_state == FALSE && \
		game->player.attack.pressed_state == FALSE && \
			game->player.guard.pressed_state == FALSE)
		game->player.current_anim = game->player.anims[1];
	game->player.idle.pressed_state = FALSE;
	game->player.run.pressed_state = TRUE;
}

void	action_key_press(int key, t_game *game)
{
	if (key == 261 && game->player.attack.pressed_state == FALSE \
		&& game->player.guard.pressed_state == FALSE)
	{
		game->key_pressed.attack_pressed = TRUE;
		game->player.attack.pressed_state = TRUE;
		game->player.attack.in_state = TRUE;
		game->player.current_anim = game->player.anims[3];
	}
	if (key == 258 && game->player.guard.pressed_state == FALSE \
		&& game->player.jump.pressed_state == FALSE)
	{
		game->key_pressed.guard_pressed = TRUE;
		game->player.guard.pressed_state = TRUE;
		game->key_pressed.attack_pressed = FALSE;
		game->player.attack.pressed_state = FALSE;
		game->player.attack.in_state = FALSE;
		if (game->player.attack.pressed_state == FALSE)
		{
			game->player.guard.in_state = TRUE;
			game->player.current_anim = game->player.anims[4];
			game->player.speed_constraint = 0.3;
		}
	}
}

void	special_mouvement_key_press(int key, t_game *game)
{
	if (key == 49)
	{
		if (!game->player.jump.in_state && \
			!game->player.jump.out_state && !game->player.debug_mode)
			play_sound("jump.wav", 2);
		game->key_pressed.fly_up_pressed = TRUE;
	}
	if (key == 257)
		game->key_pressed.fly_down_pressed = TRUE;
	if (key == 257 && game->key_pressed.w_pressed == TRUE)
	{
		if (!game->player.guard.pressed_state)
		{
			game->player.speed_constraint = 1.5;
			game->player.current_anim->animation_refresh_time = 7;
		}
		game->key_pressed.sprint_pressed = TRUE;
	}
	if (key == 48)
		game->key_pressed.minimap = TRUE;
}

void	mouvement_key_press(int key, t_game *game)
{
	if (key == 13)
	{
		run_press(game);
		game->key_pressed.w_pressed = TRUE;
	}
	if (key == 1)
	{
		run_press(game);
		game->key_pressed.s_pressed = TRUE;
	}
	if (key == 0)
	{
		run_press(game);
		game->key_pressed.a_pressed = TRUE;
	}
	if (key == 2)
	{
		run_press(game);
		game->key_pressed.d_pressed = TRUE;
	}
}

int	key_press_hook(int key, t_game *game)
{
	if (key == 123)
		game->key_pressed.down_pressed = TRUE;
	if (key == 124)
		game->key_pressed.up_pressed = TRUE;
	if (key == 125)
		game->key_pressed.left_pressed = TRUE;
	if (key == 126)
		game->key_pressed.right_pressed = TRUE;
	if (key == 35)
		create_bitmap(game);
	if (key == 53)
	{
		free_game(game);
		exit(0);
	}
	mouvement_key_press(key, game);
	special_mouvement_key_press(key, game);
	action_key_press(key, game);
	key_press_hook_debug(key, game);
	return (0);
}
