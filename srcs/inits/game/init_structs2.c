/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:58:19 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/13 10:58:50 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_player(t_player *player)
{
	player->number_of_animations = 0;
	player->orientationx = -1;
	player->location.vx = -1;
	player->anims = NULL;
	player->img = NULL;
}

void	init_struct_map(t_map *map)
{
	map->map_datas = NULL;
	map->walls = NULL;
	map->sprite_idle_texture_path = NULL;
	map->walls_distance_render_index = NULL;
	map->enemy_counter = 0;
	map->power_up_counter = 0;
	map->power_ups = NULL;
	map->enemys = NULL;
}

void	init_struct_hud(t_hud *hud)
{
	hud->life_bar_empty = NULL;
	hud->life_bar_full = NULL;
	hud->loose_screen = NULL;
	hud->win_screen = NULL;
}
