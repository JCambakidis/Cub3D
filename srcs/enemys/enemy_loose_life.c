/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_loose_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:34:36 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enemy_loose_life(t_map *map, int index)
{
	map->enemys[index].life--;
	map->enemys[index].hit.pressed_state = TRUE;
	if (map->enemys[index].life <= 0)
	{
		play_sound("enemy_die.wav", 1);
		map->enemys[index].sprite.current_animation = \
			&map->enemys[index].anims[5];
	}
	else
	{
		play_sound("enemy_hit.wav", 1);
		map->enemys[index].sprite.current_animation = \
			&map->enemys[index].anims[4];
	}
}

void	free_enemys_to_destroy_loop(t_game *game, \
	t_map *map, int anim_index)
{
	int	index;
	int	f;

	index = 0;
	while (index < map->enemys[anim_index].number_of_animations)
	{
		f = -1;
		bettermlx_destroy_image(game->window, \
			map->enemys[anim_index].anims[index].sprite);
		while (++f < map->enemys[anim_index].anims[index].animation_frames)
			bettermlx_destroy_image(game->window, \
				map->enemys[anim_index].anims[index].rescale_frames[f]);
		ft_fullfree(map->enemys[anim_index].anims[index].rescale_frames);
		index++;
	}
}

void	free_enemys_to_destroy(t_game *game, t_map *map, \
	t_enemy *new_tab, int index)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < map->enemy_counter)
	{
		if (i != index)
			new_tab[++j] = map->enemys[i];
		else
		{
			free_enemys_to_destroy_loop(game, map, i);
			ft_fullfree((void *)map->enemys[i].anims);
		}
	}
}

void	delete_enemy(t_game *game, t_map *map, int index)
{
	t_enemy	*new_tab;

	new_tab = ft_calloc(map->enemy_counter - 1, sizeof(t_enemy));
	if (!new_tab)
	{
		error_display("enemy malloc error", "delete_enemy()");
		quit_game(game);
	}
	free_enemys_to_destroy(game, map, new_tab, index);
	ft_fullfree((void *)map->enemys);
	map->enemy_counter--;
	map->enemys = new_tab;
	if (map->enemy_counter <= 0)
	{
		game->hud.black_screen = game->hud.win_screen;
		game->game_end = TRUE;
		stop_sounds();
		play_sound("win.mp3", 1);
	}
}
