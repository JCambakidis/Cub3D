/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:39:10 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 15:48:59 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_window(t_window *window)
{
	if (window != NULL)
	{
		window->rcast_vectors = NULL;
		window->rc_vect_len_coll = NULL;
		window->rc_vect_p_index = NULL;
		window->win_ptr = NULL;
		window->mlx_ptr = NULL;
		window->nbr_pixels = 0;
		window->show_debug = FALSE;
	}
}

void	init_struct_textures(t_textures *texture)
{
	texture->ea_wall.path = NULL;
	texture->no_wall.path = NULL;
	texture->so_wall.path = NULL;
	texture->we_wall.path = NULL;
	texture->roof_wall.path = NULL;
	texture->floor_wall.path = NULL;
	texture->ea_wall.texture = NULL;
	texture->no_wall.texture = NULL;
	texture->so_wall.texture = NULL;
	texture->we_wall.texture = NULL;
	texture->floor_wall.texture = NULL;
	texture->roof_wall.texture = NULL;
}

void	init_struct_game(t_game *game)
{
	game->window = NULL;
	game->img = NULL;
	game->threads_interval = NULL;
	game->threads = NULL;
	game->debug_offset = 300;
}

void	init_structs(t_game *game)
{
	init_struct_player(&game->player);
	init_struct_textures(&game->textures);
	init_struct_textures(&game->textures_hidden);
	init_struct_textures(&game->textures_bis);
	init_struct_map(&game->map);
	init_struct_hud(&game->hud);
	init_struct_window(game->window);
	init_struct_game(game);
}
