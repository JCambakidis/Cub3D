/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_animations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:13:44 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_anim	init_sprites_img_enemy_idle(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, game->map.sprite_idle_texture_path);
	enemy->number_of_animations++;
	anim.animation_frames_width = 6;
	anim.animation_frames_height = 0;
	anim.animation_frames = 6;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 10;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}

t_anim	init_sprites_img_enemy_run(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/enemy/enemy_Run.xpm");
	enemy->number_of_animations++;
	anim.animation_frames_width = 8;
	anim.animation_frames_height = 0;
	anim.animation_frames = 8;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 10;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}

t_anim	init_sprites_img_enemy_attack(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/enemy/enemy_Attack.xpm");
	enemy->number_of_animations++;
	anim.animation_frames_width = 9;
	anim.animation_frames_height = 0;
	anim.animation_frames = 9;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 10;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}

t_anim	init_sprites_img_enemy_guard(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/enemy/enemy_Guard.xpm");
	enemy->number_of_animations++;
	anim.animation_frames_width = 5;
	anim.animation_frames_height = 0;
	anim.animation_frames = 5;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 10;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}

t_anim	init_sprites_img_enemy_die(t_game *game, t_enemy *enemy)
{
	t_anim	anim;

	anim.sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/enemy/enemy_Die.xpm");
	enemy->number_of_animations++;
	anim.animation_frames_width = 5;
	anim.animation_frames_height = 0;
	anim.animation_frames = 5;
	anim.animation_init_index_height = 0;
	anim.animation_index_width = 0;
	anim.animation_index_height = anim.animation_init_index_height;
	anim.animation_width = 170;
	anim.animation_height = 170;
	anim.animation_last_time = 0;
	anim.animation_refresh_time = 10;
	anim.rescale_frames = rescale_frames_in_tab(game, \
		&anim, create_interval(game->img->width / 2, game->img->height / 2));
	return (anim);
}
