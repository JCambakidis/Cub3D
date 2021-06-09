/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:55:25 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:01 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_player(t_game *game, t_player player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < player.number_of_animations)
	{
		j = -1;
		if (player.anims[i] != NULL)
		{
			bettermlx_destroy_image(game->window, player.anims[i]->sprite);
			while (++j < player.anims[i]->animation_frames)
				bettermlx_destroy_image(game->window, \
					player.anims[i]->rescale_frames[j]);
			ft_fullfree(player.anims[i]->rescale_frames);
			ft_fullfree(player.anims[i]);
		}
	}
	ft_fullfree(player.anims);
	bettermlx_destroy_image(game->window, player.hud);
	bettermlx_destroy_image(game->window, player.hit);
	bettermlx_destroy_image(game->window, player.img);
}

void	free_enemy(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	while (++i < map->enemy_counter)
	{
		j = -1;
		while (++j < map->enemys[i].number_of_animations)
		{
			bettermlx_destroy_image(game->window, \
				map->enemys[i].anims[j].sprite);
			e = -1;
			while (++e < map->enemys[i].anims[j].animation_frames)
				bettermlx_destroy_image(game->window, \
					map->enemys[i].anims[j].rescale_frames[e]);
			ft_fullfree(map->enemys[i].anims[j].rescale_frames);
		}
		ft_fullfree((void *)map->enemys[i].anims);
	}
	ft_fullfree((void *)map->enemys);
}

void	free_power_ups(t_game *game, t_map *map)
{
	int	i;

	i = -1;
	if (map->power_ups != NULL)
	{
		while (++i < map->power_up_counter)
		{
			if (map->power_ups[i].sprite.current_animation != NULL)
			{
				bettermlx_destroy_image(game->window, \
					map->power_ups[i].sprite.current_animation->sprite);
				ft_fullfree(\
					map->power_ups[i].sprite.current_animation->rescale_frames);
				ft_fullfree(map->power_ups[i].sprite.current_animation);
			}
		}
		ft_fullfree((void *)map->power_ups);
	}
}
