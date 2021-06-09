/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:21:25 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 14:04:11 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_images(t_game *game)
{
	game->player.anims[0] = init_sprites_img_idle(game);
	game->player.anims[1] = init_sprites_img_run(game);
	game->player.anims[2] = init_sprites_img_jump(game);
	game->player.anims[3] = init_sprites_img_attack(game);
	game->player.anims[4] = init_sprites_img_guard(game);
	game->player.position_sprite = create_interval(0, 0);
	game->player.hit = bettermlx_init_xpm_image(\
		game, game->window, "./textures/HUD_Hit.xpm");
	game->player.hit = rescale_img(game, game->player.hit, \
		game->window->width, game->window->height);
	game->player.hud = bettermlx_init_xpm_image(game, \
		game->window, "./textures/HUD_Screen.xpm");
	game->player.hud = rescale_img(game, game->player.hud, \
		game->window->width, game->window->height);
}

void	set_player_parameters(t_game *game, float zlocation)
{
	game->player.number_of_animations = 0;
	set_player_images(game);
	game->player.current_anim = game->player.anims[0];
	game->player.img = bettermlx_init_image(game, \
		game->window, game->window->width / 1.5, game->window->height / 1.5);
	if (!game->player.img)
	{
		error_display("player malloc error", "game->player.img");
		quit_game(game);
	}
	game->player.location.vz = zlocation;
	game->player.init_location = game->player.location;
	game->player.normal = create_vector(0, -1, 0);
	game->player.orientationz = 0;
	game->player.pixel_index = 0;
	game->player.key_pressed = FALSE;
	game->player.idle.pressed_state = TRUE;
	game->player.life = 3;
	game->player.last_time = 0;
	game->player.debug_mode = DEBUG;
	game->player.run_animation_side = FALSE;
	game->player.speed_constraint = 1;
	game->player.speed = MOVEMENT_SPEED;
}
