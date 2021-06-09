/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks_press2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:49:36 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 15:24:58 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reload_pixels(t_game *game)
{
	ft_fullfree(game->window->rcast_vectors);
	ft_fullfree(game->window->rc_vect_p_index);
	ft_fullfree(game->window->rc_vect_len_coll);
	ft_fullfree(game->threads_interval);
	init_pixels(game);
	init_threads(game);
}

void	key_press_hook_debug3(int key, t_game *game)
{
	if (key == 43)
	{
		if (game->window->show_debug)
		{
			game->debug_offset = 200;
			game->window->show_debug = FALSE;
			game->player.location.vz = 0.5;
			if (game->map.map_datas[(int)game->player.location.vy][(int)game->player.location.vx] \
					== '1')
				game->player.location = game->player.init_location;
			game->player.debug_mode = 0;
			game->player.speed = 0.001;
			game->window->render_distance = RENDER_DISTANCE;
			game->player.fov = FOV;
			game->window->divider = WIN_DIVIDER;
			reload_pixels(game);
		}
		else
			game->window->show_debug = TRUE;
	}
}

void	key_press_hook_debug2(int key, t_game *game)
{
	if (key == 78 && game->window->render_distance > 0 \
		&& game->window->show_debug)
		game->window->render_distance--;
	if (key == 69 && game->window->show_debug)
		game->window->render_distance++;
	if (key == 119)
	{
		if (game->player.debug_mode == 0 && game->window->show_debug)
		{
			game->player.debug_mode = 1;
			game->player.speed = 0.003;
		}
		else
		{
			game->player.location.vz = 0.5;
			if (game->map.map_datas[(int)game->player.location.vy][(int)game->player.location.vx] \
					== '1')
				game->player.location = game->player.init_location;
			game->player.debug_mode = 0;
			game->player.speed = 0.001;
		}
	}
	key_press_hook_debug3(key, game);
}

void	key_press_hook_debug(int key, t_game *game)
{
	if (key == 75 && game->player.fov > 1 && game->window->show_debug)
	{
		game->player.fov--;
		reload_pixels(game);
	}
	if (key == 67 && game->player.fov < 360 && game->window->show_debug)
	{
		game->player.fov++;
		reload_pixels(game);
	}
	if (key == 116 && game->window->show_debug)
	{
		game->window->divider++;
		reload_pixels(game);
	}
	if (key == 121 && game->window->divider > 1 && game->window->show_debug)
	{
		game->window->divider--;
		reload_pixels(game);
	}
	key_press_hook_debug2(key, game);
}
