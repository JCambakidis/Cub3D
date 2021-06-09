/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_guard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:08:20 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enemy_guard_anim_restore(t_game *game, t_enemy *enemy)
{
	t_sprite	*sprite;

	sprite = &enemy->sprite;
	if (enemy->guard.pressed_state && !game->player.attack.pressed_state && \
		sprite->current_animation->animation_frames_width - 1 == \
			sprite->current_animation->animation_index_width)
	{
		enemy->guard.pressed_state = FALSE;
		enemy->guard.in_state = FALSE;
		enemy->guard_probability = 10;
		enemy->guard.out_state = FALSE;
		if (enemy->idle.pressed_state)
			sprite->current_animation = &enemy->anims[0];
		else
			sprite->current_animation = &enemy->anims[1];
	}
}

void	enemy_guard(t_game *game, t_enemy *enemy)
{
	if (ft_dst_vect_vect(enemy->sprite.location, game->player.location) < 1 \
		&& game->player.attack.pressed_state && !enemy->hit.pressed_state)
	{
		if (random_in_range(0, 100) <= enemy->guard_probability)
		{
			enemy->guard.pressed_state = TRUE;
			enemy->attack.pressed_state = FALSE;
			enemy->attack.in_state = FALSE;
			enemy->attack.out_state = FALSE;
			enemy->guard_probability = 1;
			enemy->sprite.current_animation = &enemy->anims[3];
		}
	}
	enemy_guard_anim_restore(game, enemy);
}
