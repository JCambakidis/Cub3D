/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:09:40 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:33:46 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_wall_on_window(t_game *game, \
	t_vector3 inter_p, t_interval t, int p_index)
{
	if (inter_p.vx < game->map.walls_x_counter && inter_p.vx > 1 && \
		inter_p.vy > 1 && inter_p.vy < game->map.walls_y_counter)
	{
		if (inter_p.vz > 0 && game->player.location.vz < 1)
			bettermlx_pixel_put(game, game->window->rc_vect_p_index[p_index], \
				select_color(game->textures.roof_wall, \
					ft_get_pixel_texture_z, inter_p), \
						1 - t.istart / game->window->render_distance);
		if ((inter_p.vz < 0 && game->player.location.vz > 0))
			bettermlx_pixel_put(game, game->window->rc_vect_p_index[p_index], \
				select_color(game->textures.floor_wall, \
					ft_get_pixel_texture_z, inter_p), \
						1 - t.istart / game->window->render_distance);
	}
	else
		bettermlx_pixel_put(game, game->window->rc_vect_p_index[p_index], \
			create_color(0, 0, 0, 0), 1);
	game->window->rc_vect_len_coll[p_index] = t.istop;
}

int	check_walls(t_game *game, \
	t_check_collider_param *params)
{
	if (params->y_elem && params->elem_index <= game->map.walls_y_counter)
	{
		params->y_elem = FALSE;
		params->elem_index = game->player.location.vx + \
			game->map.walls_y_counter;
		params->hit = 1;
		if (params->vector.vx < 0)
			params->elem_index++;
	}
	else if (params->x_elem && params->elem_index <= \
		game->map.walls_x_counter + game->map.walls_y_counter)
	{
		params->hit = 1;
		return (1);
	}
	return (0);
}

int	check_if_collide(t_game *game, \
	t_check_collider_param *params, t_vector3 inter_p)
{
	t_wall_hit_param	hit_params;

	if (params->t.istart < game->window->render_distance)
	{
		if (game->map.walls[params->elem_index].c == 1)
		{
			put_wall_on_window(game, inter_p, params->t, params->p_index);
			params->hit = 1;
		}
		hit_params.indexs = create_vector(params->elem_index, params->p_index, \
				params->t.istart);
		hit_params.vector = params->vector;
		hit_params.inter_p = inter_p;
		hit_params.game = game;
		if (inter_p.vz > 0 && inter_p.vz < 1 && \
			check_walls_hit(game, hit_params) == 1)
		{
			params->t.istop = params->t.istart;
			game->window->rc_vect_len_coll[params->p_index] = params->t.istop;
			check_walls(game, params);
		}
		return (0);
	}
	game->window->rc_vect_len_coll[params->p_index] = params->t.istop;
	return (0);
}

int	check_intersect_front_wall(t_game *g, \
	t_check_collider_param *params)
{
	t_vector3		inter_p;
	float			tmp;

	tmp = mk_rcast_per_vect(g->map.walls[params->elem_index], params->vector);
	if (tmp)
	{
		params->t.istart = -(g->map.walls[params->elem_index].a * g->player.location.vx + \
			g->map.walls[params->elem_index].b * g->player.location.vy + \
				g->map.walls[params->elem_index].c * g->player.location.vz + \
					g->map.walls[params->elem_index].d) / tmp;
		if (params->t.istart > 0)
		{
			inter_p = mk_vect_coll(g->player.location, \
				params->vector, params->t.istart);
			rectif_impact_point(g, &inter_p, params->elem_index);
			if (params->t.istart < params->t.istop)
			{
				if (check_if_collide(g, params, inter_p))
					return (1);
			}
		}
	}
	return (0);
}

int	rcast_check_collider(t_game *game, t_check_collider_param *params)
{
	params->t.istop = INT_MAX;
	params->elem_index = game->player.location.vy;
	if (params->vector.vy < 0)
		params->elem_index++;
	params->y_elem = TRUE;
	params->x_elem = TRUE;
	params->hit = 0;
	while (params->elem_index <= game->map.walls_counter)
	{
		if (check_intersect_front_wall(game, params))
			break ;
		if (game->player.location.vy > 0 && game->player.location.vy < \
			game->map.walls_y_counter && game->player.location.vx > 0 \
				&& game->player.location.vx < game->map.walls_x_counter)
			select_looking_elements(game, params);
		else
			params->elem_index++;
	}
	return (params->hit);
}
