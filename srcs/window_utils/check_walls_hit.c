/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:00:40 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:42:20 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_to_pixel_put_b(t_game *game, t_wall_hit_param params, \
	t_textures textures)
{
	if (game->map.walls[(int)params.indexs.vx].b == 1)
	{
		if (params.vector.vy >= 0)
			bettermlx_pixel_put(game, \
				game->window->rc_vect_p_index[(int)params.indexs.vy], \
					select_color(textures.ea_wall, \
						ft_get_pixel_texture_x, params.inter_p), 1 - \
							params.indexs.vz / game->window->render_distance);
		else
			bettermlx_pixel_put(game, \
				game->window->rc_vect_p_index[(int)params.indexs.vy], \
					select_color(textures.we_wall, \
						ft_get_pixel_texture_x, params.inter_p), 1 - \
							params.indexs.vz / game->window->render_distance);
		return (1);
	}
	return (0);
}

int	check_to_pixel_put_a(t_game *game, t_wall_hit_param params, \
	t_textures textures)
{
	if (game->map.walls[(int)params.indexs.vx].a == 1)
	{
		if (params.vector.vx >= 0)
			bettermlx_pixel_put(game, \
				game->window->rc_vect_p_index[(int)params.indexs.vy], \
					select_color(textures.no_wall, \
					ft_get_pixel_texture_y, params.inter_p), 1 - \
						params.indexs.vz / game->window->render_distance);
		else
			bettermlx_pixel_put(game, \
				game->window->rc_vect_p_index[(int)params.indexs.vy], \
					select_color(textures.so_wall, \
						ft_get_pixel_texture_y, params.inter_p), 1 - \
							params.indexs.vz / game->window->render_distance);
		return (1);
	}
	return (0);
}

int	check_walls_flags(t_game *game, t_wall_hit_param params)
{
	if (game->map.map_datas[(int)params.inter_p.vy][(int)params.inter_p.vx] \
		== '1')
	{
		if (check_to_pixel_put_b(game, params, game->textures))
			return (1);
		else if (check_to_pixel_put_a(game, params, game->textures))
			return (1);
	}
	if (game->map.map_datas[(int)params.inter_p.vy][(int)params.inter_p.vx] \
		== 'Q')
	{
		if (check_to_pixel_put_b(game, params, game->textures_hidden))
			return (1);
		else if (check_to_pixel_put_a(game, params, game->textures_hidden))
			return (1);
	}
	if (game->map.map_datas[(int)params.inter_p.vy][(int)params.inter_p.vx] \
		== 'A')
	{
		if (check_to_pixel_put_b(game, params, game->textures_bis))
			return (1);
		else if (check_to_pixel_put_a(game, params, game->textures_bis))
			return (1);
	}
	return (0);
}

int	check_walls_hit(t_game *game, t_wall_hit_param params)
{
	if (((int)params.inter_p.vx < 0 || \
		(int)params.inter_p.vx > game->map.walls_x_counter) || \
			((int)params.inter_p.vy < 0 || \
				(int)params.inter_p.vy > game->map.walls_y_counter))
		return (0);
	if (((params.inter_p.vx >= 0 && \
		params.inter_p.vx < game->map.walls_x_counter) && (params.inter_p.vy >= 0 && \
			params.inter_p.vy < game->map.walls_y_counter) && \
				(game->map.map_datas[(int)params.inter_p.vy][(int)params.inter_p.vx] != '0' \
					|| game->map.map_datas[(int)params.inter_p.vy][(int)params.inter_p.vx] \
						!= ' ')))
	{
		if (check_walls_flags(game, params))
			return (1);
	}
	return (0);
}
