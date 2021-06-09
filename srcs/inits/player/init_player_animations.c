/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_animations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:57:41 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 18:00:15 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_anim	*init_sprites_img_idle(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
	{
		error_display("player malloc error", "init_sprites_img_idle()");
		quit_game(game);
	}
	game->player.number_of_animations++;
	anim->sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/Player/Player_Idle.xpm");
	anim->animation_frames_width = 1;
	anim->animation_frames_height = 0;
	anim->animation_frames = 1;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 432;
	anim->animation_height = 243;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 3;
	anim->rescale_frames = rescale_frames_in_tab(game, anim, \
		create_interval(game->img->width, game->img->height));
	return (anim);
}

t_anim	*init_sprites_img_run(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
	{
		error_display("player malloc error", "init_sprites_img_idle()");
		quit_game(game);
	}
	game->player.number_of_animations++;
	anim->sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/Player/Player_Idle.xpm");
	anim->animation_frames_width = 1;
	anim->animation_frames_height = 0;
	anim->animation_frames = 1;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 432;
	anim->animation_height = 243;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 3;
	anim->rescale_frames = rescale_frames_in_tab(game, anim, \
		create_interval(game->img->width, game->img->height));
	return (anim);
}

t_anim	*init_sprites_img_jump(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
	{
		error_display("player malloc error", "init_sprites_img_jump()");
		quit_game(game);
	}
	game->player.number_of_animations++;
	anim->sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/Player/Player_Jump.xpm");
	anim->animation_frames_width = 1;
	anim->animation_frames_height = 0;
	anim->animation_frames = 1;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 432;
	anim->animation_height = 243;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 1;
	anim->rescale_frames = rescale_frames_in_tab(game, anim, \
		create_interval(game->img->width, game->img->height));
	return (anim);
}

t_anim	*init_sprites_img_attack(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
	{
		error_display("player malloc error", "init_sprites_img_attack()");
		quit_game(game);
	}
	game->player.number_of_animations++;
	anim->sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/Player/Player_Attack.xpm");
	anim->animation_frames_width = 8;
	anim->animation_frames_height = 0;
	anim->animation_frames = 8;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 432;
	anim->animation_height = 243;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 20;
	anim->rescale_frames = rescale_frames_in_tab(game, anim, \
		create_interval(game->img->width, game->img->height));
	return (anim);
}

t_anim	*init_sprites_img_guard(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
	{
		error_display("player malloc error", "init_sprites_img_guard()");
		quit_game(game);
	}
	game->player.number_of_animations++;
	anim->sprite = bettermlx_init_xpm_image(\
		game, game->window, "./textures/Player/Player_Guard.xpm");
	anim->animation_frames_width = 1;
	anim->animation_frames_height = 0;
	anim->animation_frames = 1;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 432;
	anim->animation_height = 243;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 1;
	anim->rescale_frames = rescale_frames_in_tab(game, anim, \
		create_interval(game->img->width, game->img->height));
	return (anim);
}
