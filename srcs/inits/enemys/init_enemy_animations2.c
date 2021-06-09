/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_animations2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:54:28 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_anim	init_sprites_img_enemy_hit(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/enemy/enemy_Hit.xpm");
	enemy->number_of_animations++;
	anim.animation_frames_width = 4;
	anim.animation_frames_height = 0;
	anim.animation_frames = 4;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 2;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}
