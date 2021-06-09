/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_attack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:07 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 19:29:11 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	attack(t_game *game)
{
	float	tmp;

	tmp = ft_dst_vect_vect(\
		game->player.location, game->map.enemys[0].sprite.location);
	play_sound("whoosh.flac", 1);
	if (!game->map.enemys[0].guard.pressed_state)
	{
		if (tmp < 0.5 && tmp > 0)
		{
			enemy_loose_life(&game->map, 0);
			play_sound("impact_sword.wav", 1);
		}
	}
	else if (tmp < 0.5 && tmp > 0)
		play_sound("guard.wav", 1);
	return (1);
}
