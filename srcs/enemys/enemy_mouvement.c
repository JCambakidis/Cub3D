/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:25:24 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/21 18:46:18 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enemy_check_reset_location(t_game *game, t_enemy *enemy)
{
	t_vector3	fpl;
	t_vector3	temp;

	fpl = enemy->sprite.location;
	if (game->delta_time >= 1000 / 60)
	{
		temp = create_vector(fpl.vx - enemy->init_location.vx, \
			fpl.vy - enemy->init_location.vy, fpl.vz - enemy->init_location.vz);
		if (temp.vx < 0)
			temp.vx = sqrt(temp.vx * temp.vx);
		else
			temp.vx = -sqrt(temp.vx * temp.vx);
		if (temp.vy < 0)
			temp.vy = sqrt(temp.vy * temp.vy);
		else
			temp.vy = -sqrt(temp.vy * temp.vy);
		fpl = add_vector_vector(fpl, mult_vector_vector(\
			temp, create_vector(0.02, 0.02, 0)));
		enemy->sprite.location = fpl;
	}
}

void	check_mouvement_states(t_game *g, t_enemy *e, t_vector3 dst)
{
	if (ft_dst_vect_vect(e->sprite.location, dst) > 0.6)
	{
		e->run.pressed_state = TRUE;
		e->idle.pressed_state = FALSE;
		e->attack.pressed_state = FALSE;
		if (!e->hit.pressed_state)
			e->sprite.current_animation = &e->anims[1];
	}
	else if (ft_dst_vect_vect(e->sprite.location, g->player.location) < 0.6)
	{
		e->run.pressed_state = FALSE;
		e->idle.pressed_state = TRUE;
		e->attack.pressed_state = TRUE;
		if (!e->hit.pressed_state)
			e->sprite.current_animation = &e->anims[0];
	}
	else if (e->run.pressed_state && \
		ft_dst_vect_vect(e->sprite.location, dst) < 0.6)
	{
		e->run.pressed_state = FALSE;
		e->attack.pressed_state = FALSE;
		e->idle.pressed_state = TRUE;
		if (!e->hit.pressed_state)
			e->sprite.current_animation = &e->anims[0];
	}
}

void	move_enemy(t_game *game, t_enemy *enemy, t_vector3 temp)
{
	t_vector3	fpl;
	t_sprite	*sprite;

	sprite = &enemy->sprite;
	fpl = add_vector_vector(sprite->location, mult_vector_vector(\
		temp, create_vector(enemy->speed * game->delta_time, \
			enemy->speed * game->delta_time, 0)));
	if (check_enemy_walls_collision(game, fpl.vx, fpl.vy))
		sprite->location = fpl;
	else if (check_enemy_walls_collision(game, sprite->location.vx, fpl.vy))
		sprite->location = create_vector(sprite->location.vx, fpl.vy, fpl.vz);
	else if (check_enemy_walls_collision(game, fpl.vx, sprite->location.vy))
		sprite->location = create_vector(fpl.vx, sprite->location.vy, fpl.vz);
	if ((sprite->current_animation->animation_index_width == 3 && \
		enemy->run.in_state) || (sprite->current_animation->animation_index_width == 6 \
			&& enemy->run.in_state))
	{
		play_sound("enemy_footstep.mp3", enemy->sound_volume_value + 0.5);
		enemy->run.in_state = FALSE;
	}
	if ((sprite->current_animation->animation_index_width == 4 && \
		!enemy->run.in_state) || (sprite->current_animation->animation_index_width == 7 \
			&& !enemy->run.in_state))
		enemy->run.in_state = TRUE;
}

void	check_distance_with_player(t_game *game, \
	t_enemy *enemy, t_vector3 *dst)
{
	if (ft_dst_vect_vect(enemy->sprite.location, game->player.location) < 2.8 \
		&& ft_dst_vect_vect(game->player.location, enemy->init_location) \
			< 3)
	{
		*dst = game->player.location;
		enemy->speed = 0.0008;
	}
	else
	{
		*dst = enemy->init_location;
		enemy->speed = 0.0005;
	}
}

void	enemy_mouvement(t_game *game, t_enemy *e)
{
	t_vector3	dst;
	t_vector3	temp;

	check_distance_with_player(game, e, &dst);
	temp = create_vector(e->sprite.location.vx - dst.vx, \
		e->sprite.location.vy - dst.vy, e->sprite.location.vz - dst.vz);
	if (temp.vx < 0)
		temp.vx = sqrt(temp.vx * temp.vx);
	else
		temp.vx = -sqrt(temp.vx * temp.vx);
	if (temp.vy < 0)
		temp.vy = sqrt(temp.vy * temp.vy);
	else
		temp.vy = -sqrt(temp.vy * temp.vy);
	if (!e->attack.pressed_state && !e->guard.pressed_state)
	{
		if (game->delta_time >= 1000 / 60 && e->run.pressed_state)
			move_enemy(game, e, temp);
		check_mouvement_states(game, e, dst);
	}
}
