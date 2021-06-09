/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouvement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:48:31 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 15:58:31 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotation(t_game *game)
{
	if (game->key_pressed.down_pressed || game->key_pressed.up_pressed || \
		game->key_pressed.left_pressed || game->key_pressed.right_pressed)
	{
		if (game->key_pressed.down_pressed)
			game->player.orientationx -= ROTATION_SPEED * game->delta_time;
		if (game->key_pressed.up_pressed)
			game->player.orientationx += ROTATION_SPEED * game->delta_time;
		if (game->key_pressed.left_pressed && game->player.orientationz < 45)
			game->player.orientationz += ROTATION_SPEED * game->delta_time;
		if (game->key_pressed.right_pressed && game->player.orientationz > -45)
			game->player.orientationz -= ROTATION_SPEED * game->delta_time;
	}
}

void	player_special_displacement(t_game *game, t_vector3 *fpl)
{
	if (game->key_pressed.fly_up_pressed && game->player.debug_mode == 1)
		*fpl = add_vector_vector(*fpl, \
			rotate_vector_z(create_vector(0, 0, game->player.speed \
				* game->delta_time), game->player.orientationx * RADIAN));
	if (game->key_pressed.fly_down_pressed && game->player.debug_mode == 1)
		*fpl = add_vector_vector(*fpl, \
			rotate_vector_z(create_vector(0, 0, -game->player.speed \
				* game->delta_time), game->player.orientationx * RADIAN));
	if (game->key_pressed.fly_up_pressed && game->player.debug_mode == 0 \
		&& game->player.jump.pressed_state == FALSE)
	{
		game->player.current_anim = game->player.anims[2];
		game->player.jump.pressed_state = TRUE;
		game->player.jump.in_state = TRUE;
	}
}

int	check_walls_collision(t_game *game, float x, float y)
{
	if (game->map.map_datas[(int)y][(int)x] != '1' && \
		game->map.map_datas[(int)y][(int)x] != 'A' && \
			ft_dst_vect_vect(create_vector(x, y, game->player.location.vz), \
				game->map.enemys[0].sprite.location) > 0.2)
		return (1);
	return (0);
}

int	keyboard_player_mouvement(t_game *game)
{
	t_vector3	fpl;

	fpl = game->player.location;
	player_special_displacement(game, &fpl);
	player_rotation(game);
	player_displacement(game, &fpl);
	player_attack(game);
	minimap_reset_location_color(game, game->player.location);
	if (game->player.debug_mode == 1 || \
		check_walls_collision(game, fpl.vx, fpl.vy))
		game->player.location = fpl;
	else if (game->player.debug_mode == 1 || \
		check_walls_collision(game, game->player.location.vx, fpl.vy))
		game->player.location = \
			create_vector(game->player.location.vx, fpl.vy, fpl.vz);
	else if (game->player.debug_mode == 1 || \
		check_walls_collision(game, fpl.vx, game->player.location.vy))
		game->player.location = \
			create_vector(fpl.vx, game->player.location.vy, fpl.vz);
	jump(game, &game->player);
	player_walk_anim(game, &game->player);
	game->player.normal = rotate_vector_x(\
		create_vector(0, -1, 0), game->player.orientationz * RADIAN);
	game->player.normal = rotate_vector_z(\
		game->player.normal, game->player.orientationx * RADIAN);
	return (0);
}
