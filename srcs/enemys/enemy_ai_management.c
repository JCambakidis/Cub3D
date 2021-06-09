/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:10:19 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:13:03 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_enemy_walls_collision(t_game *game, float x, float y)
{
	if (game->map.map_datas[(int)y][(int)x] != '1' && \
		game->map.map_datas[(int)y][(int)x] != 'A')
		return (1);
	return (0);
}

void	enemy_states(t_game *game)
{
	game->map.enemys[0].sound_volume_value = 1 - ft_map(\
		ft_dst_vect_vect(game->map.enemys[0].sprite.location, \
			game->player.location), create_interval(0, \
				game->map.walls_counter), create_interval(0, 1)) * 5;
	if (game->map.enemys[0].idle.pressed_state && \
		game->map.enemys[0].sprite.current_animation->animation_index_width == 4 \
			&& game->map.enemys[0].idle.in_state)
	{
		play_sound("enemy_breathe.mp3", \
			game->map.enemys[0].sound_volume_value);
		game->map.enemys[0].idle.in_state = FALSE;
	}
	if (game->map.enemys[0].idle.pressed_state && \
		game->map.enemys[0].sprite.current_animation->animation_index_width == 5 \
			&& !game->map.enemys[0].idle.in_state)
		game->map.enemys[0].idle.in_state = TRUE;
	if (game->map.enemys[0].life > 0)
	{
		enemy_mouvement(game, &game->map.enemys[0]);
		enemy_attack(game, &game->map.enemys[0]);
		enemy_guard(game, &game->map.enemys[0]);
	}
}

void	enemys_loop(t_game *game)
{
	int	i;

	i = 0;
	while (++i < game->map.enemy_counter)
	{
		game->map.enemys[i].sound_volume_value = 1 - ft_map(\
			ft_dst_vect_vect(game->map.enemys[i].sprite.location, game->player.location), \
				create_interval(0, game->map.walls_counter), \
					create_interval(0, 1)) * 5;
		if (ft_dst_vect_vect(game->map.enemys[i].sprite.location, \
			game->map.enemys[i].init_location) > 0.1)
			enemy_check_reset_location(game, &game->map.enemys[i]);
		if (game->map.enemys[i].idle.pressed_state && \
			game->map.enemys[i].sprite.current_animation->animation_index_width == 4 \
				&& game->map.enemys[i].idle.in_state)
		{
			play_sound("enemy_breathe.mp3", \
				game->map.enemys[i].sound_volume_value);
			game->map.enemys[i].idle.in_state = FALSE;
		}
		if (game->map.enemys[i].idle.pressed_state && \
			game->map.enemys[i].sprite.current_animation->animation_index_width == 5 \
				&& !game->map.enemys[i].idle.in_state)
			game->map.enemys[i].idle.in_state = TRUE;
	}
}

void	enemy_ai_management(t_game *game)
{
	if (game->map.enemy_counter > 0 && game->player.debug_mode == 0)
	{
		minimap_reset_location_color(game, game->map.enemys[0].sprite.location);
		enemy_states(game);
		if (game->map.enemys[0].life > 0 && game->map.enemys[0].hit.pressed_state \
			&& game->map.enemys[0].sprite.current_animation->animation_index_width == \
				game->map.enemys[0].sprite.current_animation->animation_frames_width \
					- 1)
		{
			game->map.enemys[0].hit.pressed_state = FALSE;
			if (game->map.enemys[0].idle.pressed_state)
				game->map.enemys[0].sprite.current_animation = \
					&game->map.enemys[0].anims[0];
			else
				game->map.enemys[0].sprite.current_animation = \
					&game->map.enemys[0].anims[1];
		}
		if (game->map.enemys[0].life <= 0 && \
			animation_end(*game->map.enemys[0].sprite.current_animation))
			delete_enemy(game, &game->map, 0);
		enemys_loop(game);
		minimap_put_location_color(game, game->map.enemys[0].sprite.location, create_color(0, 255, 0, 0));
	}
}
