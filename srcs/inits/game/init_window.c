/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:46:09 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:26 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_elements(t_game *game)
{
	init_walls_textures(game, &game->textures);
	game->textures_hidden = init_wall_bis_path("./textures/walls/wall_hidden2.xpm", \
		"./textures/walls/wall_hidden2.xpm", "./textures/walls/wall_hidden2.xpm", \
			"./textures/walls/wall_hidden2.xpm");
	init_walls_textures(game, &game->textures_hidden);
	game->textures_bis = init_wall_bis_path("./textures/walls/wall_1.xpm", \
		"./textures/walls/wall_1.xpm", "./textures/walls/wall_1.xpm", \
			"./textures/walls/wall_1.xpm");
	init_walls_textures(game, &game->textures_bis);
	init_keyboard(game);
	init_player_pos(game, 0.5);
	init_sprites(game, 0);
	init_pixels(game);
	init_hud(game);
	map_parsing_checker(game, &game->map);
	init_walls(game);
}

void	init_window(t_game *game)
{
	game->last_time = bettermlx_get_time();
	game->game_end = FALSE;
	game->window->divider = WIN_DIVIDER;
	game->player.fov = FOV;
	game->window->render_distance = RENDER_DISTANCE;
	game->window->title = "Cub3D";
	game->map.wall_dist = 0;
	game->window->mlx_ptr = mlx_init();
	if (!game->window->mlx_ptr)
	{
		error_display("window malloc error", "game->window->mlx_ptr");
		quit_game(game);
	}
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr, \
		game->window->width, game->window->height, game->window->title);
	if (!game->window->win_ptr)
	{
		error_display("window malloc error", "game->window->win_ptr");
		quit_game(game);
	}
	game->img = bettermlx_init_image(game, \
		game->window->win_ptr, game->window->width, game->window->height);
	init_game_elements(game);
	quicksort_enemys_by_distance(game, 0, game->map.enemy_counter - 1);
}
