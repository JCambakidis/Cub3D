/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_power_ups.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:37:27 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:42:30 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_loop(t_game *g, t_map *map, int index, t_power_up *new_tab)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i < map->power_up_counter)
	{
		if (i != index)
			new_tab[++j] = map->power_ups[i];
		else
		{
			bettermlx_destroy_image(g->window, \
				map->power_ups[i].sprite.current_animation->sprite);
			ft_fullfree(map->power_ups[i].\
				sprite.current_animation->rescale_frames);
			ft_fullfree(map->power_ups[i].sprite.current_animation);
		}
	}
}

void	delete_power_up(t_game *g, t_map *map, int index)
{
	t_power_up	*new_tab;

	minimap_reset_location_color(g, g->map.power_ups->sprite.location);
	new_tab = ft_calloc(map->enemy_counter - 1, sizeof(t_enemy));
	if (!new_tab)
	{
		error_display("power_up malloc error", "delete_power_up()");
		quit_game(g);
	}
	delete_loop(g, map, index, new_tab);
	ft_fullfree((void *)map->power_ups);
	map->power_up_counter--;
	map->power_ups = new_tab;
}

void	check_power_ups(t_game *game, t_map *map, t_player *player)
{
	int	i;

	i = -1;
	minimap_put_location_color(game, map->power_ups[0].sprite.location, create_color(0, 0, 255, 0));
	if (player->life < 3)
	{
		while (++i < map->power_up_counter)
		{
			if (ft_dst_vect_vect(\
				map->power_ups[i].sprite.location, player->location) < 0.5)
			{
				player->life++;
				play_sound(map->power_ups[i].sound, 2);
				delete_power_up(game, map, i);
			}
		}
	}
}
