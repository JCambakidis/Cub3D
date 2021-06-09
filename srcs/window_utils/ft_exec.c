/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:48:38 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:25:15 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_images_to_window(t_game *game)
{
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, game->img->img, 0, 0);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, \
		game->player.current_anim->rescale_frames[\
			game->player.current_anim->animation_index_width]->img, \
				game->player.position_sprite.istart, \
					game->player.position_sprite.istop);
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, game->player.hud->img, 0, 0);
	minimap_put_location_color(game, game->player.location, \
		create_color(0, 0, 0, 255));
	show_minimap(game);
}

void	show_debug_text(t_game *game)
{
	int	tmp;

	tmp = game->window->height / 2;
	if (game->debug_offset > 0)
		game->debug_offset -= 0.5 * game->delta_time;
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, \
		game->debug_img->img, 0 - ft_map(game->debug_offset, \
			create_interval(0, 300), create_interval(0, \
				game->debug_img->width)), tmp - game->debug_img->height / 2);
	mlx_string_put(game->window->mlx_ptr, \
		game->window->win_ptr, game->debug_img->width / 7 - \
		game->debug_offset, tmp - 25, color_to_int(create_color(0, 0, 255, 255)), \
			"Page up down: window divider");
	mlx_string_put(game->window->mlx_ptr, \
		game->window->win_ptr, game->debug_img->width / 7 - \
		game->debug_offset, tmp - 10, color_to_int(create_color(0, 0, 255, 255)), \
			"+ -: render distance");
	mlx_string_put(game->window->mlx_ptr, \
		game->window->win_ptr, game->debug_img->width / 7 - \
		game->debug_offset, tmp + 10, color_to_int(create_color(0, 0, 255, 255)), \
			"end: debug mode");
	mlx_string_put(game->window->mlx_ptr, \
		game->window->win_ptr, game->debug_img->width / 7 - \
		game->debug_offset, tmp + 25, color_to_int(create_color(0, 0, 255, 255)), \
			"/ *: fov");
}

void	exec_check_end(t_game *game)
{
	if (!game->game_end)
	{
		if (game->window->show_debug)
		{
			show_fps(game);
			show_fov(game);
			show_render_distance(game);
			show_divider(game);
			show_debug(game);
			show_debug_text(game);
		}
		put_hud(game);
	}
	if (game->game_end)
	{
		game->bs_value -= 3;
		show_game_over_screen(game);
	}
}

int	ft_exec(t_game *game)
{
	long long	current_time;

	current_time = bettermlx_get_time();
	game->fps = 1000 / (current_time - game->last_time);
	if (current_time - game->last_time >= 1000 / 60 && !game->game_end)
	{
		game->delta_time = current_time - game->last_time;
		ft_multi_thread(game);
		if (!game->game_end)
			keyboard_player_mouvement(game);
		enemy_ai_management(game);
		game->last_time = current_time;
		if (game->bitmap)
			create_bitmap(game);
		put_images_to_window(game);
	}
	playmusic(game);
	check_power_ups(game, &game->map, &game->player);
	exec_check_end(game);
	return (0);
}
