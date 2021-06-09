/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:20:47 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 17:01:06 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_press_hook(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1 && game->player.attack.pressed_state == FALSE \
		&& game->player.guard.pressed_state == FALSE)
	{
		game->key_pressed.attack_pressed = TRUE;
		game->player.attack.pressed_state = TRUE;
		game->player.attack.in_state = TRUE;
		game->player.current_anim = game->player.anims[3];
	}	
	if (button == 2 && game->player.guard.pressed_state == FALSE)
	{
		game->key_pressed.guard_pressed = TRUE;
		game->player.guard.pressed_state = TRUE;
		if (game->player.attack.pressed_state == FALSE)
		{
			game->player.guard.in_state = TRUE;
			game->player.current_anim = game->player.anims[4];
			game->player.speed_constraint = 0.3;
		}
	}
	return (1);
}

int	mouse_release_hook(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->key_pressed.attack_pressed = FALSE;
	if (button == 2)
	{
		game->key_pressed.guard_pressed = FALSE;
		game->player.guard.pressed_state = FALSE;
		game->player.guard.in_state = FALSE;
		game->player.speed_constraint = 1;
		if (game->player.run.pressed_state == TRUE && \
			game->key_pressed.sprint_pressed)
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
	return (1);
}
