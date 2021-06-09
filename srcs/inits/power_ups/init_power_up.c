/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_power_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:11:46 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 18:34:11 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_anim	*init_sprites_img_power_up(t_game *game)
{
	t_anim	*anim;

	anim = ft_calloc(6, sizeof(t_anim));
	if (!anim)
	{
		error_display("power_up anim malloc error", \
			"t_anim	*init_sprites_img_power_up(t_game *game)");
		quit_game(game);
	}
	anim->sprite = bettermlx_init_xpm_image(game, \
		game->window, "./textures/Life.xpm");
	anim->animation_frames_width = 10;
	anim->animation_frames_height = 0;
	anim->animation_frames = 10;
	anim->animation_init_index_height = 0;
	anim->animation_index_width = 0;
	anim->animation_index_height = anim->animation_init_index_height;
	anim->animation_width = 100;
	anim->animation_height = 100;
	anim->animation_last_time = 0;
	anim->animation_refresh_time = 20;
	anim->rescale_frames = NULL;
	return (anim);
}

t_power_up	ft_create_power_up(t_game *game, t_wall plane, t_vector3 location)
{
	t_power_up	power_up;

	power_up.sprite.current_animation = NULL;
	power_up.sprite.current_animation = init_sprites_img_power_up(game);
	power_up.added_life = 1;
	power_up.sprite.location = location;
	power_up.sprite.plane = plane;
	power_up.sound = "breath.mp3";
	return (power_up);
}
