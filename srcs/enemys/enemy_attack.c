/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:05:55 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enemy_attack_anim_restore(t_enemy *enemy)
{
	if (enemy->sprite.current_animation->animation_index_width == \
		enemy->sprite.current_animation->animation_frames_width - 1)
	{
		enemy->attack.pressed_state = FALSE;
		enemy->attack.in_state = FALSE;
		enemy->attack.out_state = FALSE;
		if (enemy->idle.pressed_state)
			enemy->sprite.current_animation = &enemy->anims[0];
		else
			enemy->sprite.current_animation = &enemy->anims[1];
	}
}

void	enemy_attack(t_game *g, t_enemy *enemy)
{
	if (enemy->attack.pressed_state)
	{
		if (g->delta_time % enemy->attack_time <= enemy->attack_time / 5 && \
			ft_dst_vect_vect(enemy->sprite.location, g->player.location) <= 1 \
				&& enemy->attack.in_state == FALSE)
		{
			enemy->attack.in_state = TRUE;
			enemy->sprite.current_animation = &enemy->anims[2];
			enemy->sprite.current_animation->animation_index_width = 0;
		}
		if (enemy->attack.in_state && enemy->sprite.current_animation->animation_index_width == 5 \
			&& enemy->attack.out_state == FALSE && ft_dst_vect_vect(\
				enemy->sprite.location, g->player.location) <= 0.6)
		{
			if (g->player.guard.in_state)
				play_sound("guard.wav", 1);
			else
				player_loose_life(g, &g->player);
			if (random_in_range(0, 100) < 30 && g->player.guard.pressed_state)
				release_guard(g);
			enemy->attack.out_state = TRUE;
		}
		enemy_attack_anim_restore(enemy);
	}
}
