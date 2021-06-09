/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:13:10 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:17:04 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_enemy_images(t_game *game, t_enemy *enemy)
{
	enemy->anims = ft_calloc(6, sizeof(t_anim));
	if (!enemy->anims)
	{
		error_display("enemy malloc error", "game->map.enemys[x].anims");
		quit_game(game);
	}
	enemy->number_of_animations = 0;
	enemy->anims[0] = init_sprites_img_enemy_idle(game, enemy);
	enemy->anims[1] = init_sprites_img_enemy_run(game, enemy);
	enemy->anims[2] = init_sprites_img_enemy_attack(game, enemy);
	enemy->anims[3] = init_sprites_img_enemy_guard(game, enemy);
	enemy->anims[4] = init_sprites_img_enemy_hit(game, enemy);
	enemy->anims[5] = init_sprites_img_enemy_die(game, enemy);
	enemy->sprite.current_animation = &enemy->anims[0];
}

t_enemy	ft_create_enemy(t_game *game, t_wall plane, t_vector3 location)
{
	t_enemy	enemy;

	set_enemy_images(game, &enemy);
	enemy.last_time = bettermlx_get_time();
	enemy.idle.pressed_state = TRUE;
	enemy.run.pressed_state = FALSE;
	enemy.hit.pressed_state = FALSE;
	enemy.guard.pressed_state = FALSE;
	enemy.sprite.plane = plane;
	enemy.sprite.location = location;
	enemy.life = 3;
	enemy.guard_probability = 25;
	enemy.attack_time = 25;
	enemy.speed = 0.0008;
	enemy.init_location = location;
	return (enemy);
}
