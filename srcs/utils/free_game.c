/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:56:58 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 15:50:37 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_game *game, t_map map)
{
	int	i;

	i = -1;
	if (map.map_datas != NULL)
	{
		while (map.map_datas[++i])
			ft_fullfree((void *)map.map_datas[i]);
		ft_fullfree((void *)map.map_datas[i]);
		ft_fullfree((void *)map.map_datas);
	}
	ft_fullfree((void *)map.walls);
	ft_fullfree((void *)map.sprite_idle_texture_path);
	ft_fullfree((void *)map.walls_distance_render_index);
	free_power_ups(game, &map);
	free_enemy(game, &map);
}

void	free_hud(t_game *game, t_hud hud)
{
	bettermlx_destroy_image(game->window, hud.life_bar_empty);
	bettermlx_destroy_image(game->window, hud.life_bar_full);
	bettermlx_destroy_image(game->window, hud.loose_screen);
	bettermlx_destroy_image(game->window, hud.win_screen);
}

void	free_window(t_window *window)
{
	if (window != NULL)
	{
		ft_fullfree((void *)window->rcast_vectors);
		ft_fullfree((void *)window->rc_vect_len_coll);
		ft_fullfree((void *)window->rc_vect_p_index);
		if (window->mlx_ptr)
		{
			if (window->win_ptr)
				mlx_destroy_window(window->mlx_ptr, window->win_ptr);
			mlx_destroy_mlx(window->mlx_ptr);
		}
		ft_fullfree(window);
	}
}

void	free_textures(t_game *game, t_textures texture, t_bool free_path)
{
	if (free_path)
	{
		ft_fullfree((void *)texture.ea_wall.path);
		ft_fullfree((void *)texture.no_wall.path);
		ft_fullfree((void *)texture.so_wall.path);
		ft_fullfree((void *)texture.we_wall.path);
		ft_fullfree((void *)texture.floor_wall.path);
		ft_fullfree((void *)texture.roof_wall.path);
	}
	bettermlx_destroy_image(game->window, texture.ea_wall.texture);
	bettermlx_destroy_image(game->window, texture.no_wall.texture);
	bettermlx_destroy_image(game->window, texture.so_wall.texture);
	bettermlx_destroy_image(game->window, texture.we_wall.texture);
	bettermlx_destroy_image(game->window, texture.floor_wall.texture);
	bettermlx_destroy_image(game->window, texture.roof_wall.texture);
}

void	free_game(t_game *game)
{
	free_player(game, game->player);
	free_textures(game, game->textures, TRUE);
	free_textures(game, game->textures_bis, FALSE);
	free_textures(game, game->textures_hidden, FALSE);
	free_map(game, game->map);
	free_hud(game, game->hud);
	bettermlx_destroy_image(game->window, game->img);
	bettermlx_destroy_image(game->window, game->debug_img);
	ft_fullfree((void *)game->threads_interval);
	ft_fullfree((void *)game->threads);
	free_window(game->window);
	ft_fullfree((void *)game);
	stop_sounds();
}
