/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider_objects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:59:08 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 14:25:56 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	collision_value(t_game *game, t_sprite sprite, float tmp)
{
	return (-(sprite.plane.a * game->player.location.vx + \
					sprite.plane.b * game->player.location.vy + \
							sprite.plane.c * game->player.location.vz + \
									sprite.plane.d) / tmp);
}

int	check_if_pixel_can_put(t_game *game, \
	t_check_collider_param *params, t_sprite sprite)
{
	t_vector3	inter_p;

	if (params->t.istart > 0 && params->t.istart <= \
		game->window->rc_vect_len_coll[params->p_index])
	{
		inter_p = mk_vect_coll(game->player.location, \
			params->vector, params->t.istart);
		if (inter_p.vz <= 1 && inter_p.vz >= 0 && \
			check_size_sprite_on_plane(sprite, inter_p) && \
				ft_get_pixel_texture_sprite(game->player, \
					&sprite, inter_p).a == 0)
		{
			game->window->rc_vect_len_coll[params->p_index] = params->t.istart;
			bettermlx_pixel_put(game, game->window->rc_vect_p_index[params->p_index], \
				ft_get_pixel_texture_sprite(game->player, \
					&sprite, inter_p), 1 - \
						params->t.istart / game->window->render_distance);
			return (1);
		}				
	}
	return (0);
}

void	rcast_check_collider_sprites_power_up(\
	t_game *g, t_check_collider_param *params)
{
	int						sprt_i;
	float					tmp;

	sprt_i = 0;
	while (sprt_i < g->map.power_up_counter)
	{
		if (ft_dst_vect_vect(g->player.location, \
			g->map.power_ups[sprt_i].sprite.location) > \
				g->window->render_distance)
			return ;
		ft_dot_vector(&g->map.power_ups[sprt_i].sprite.plane, \
			g->player.normal, g->map.power_ups[sprt_i].sprite.location);
		tmp = mk_rcast_per_vect(g->map.power_ups[sprt_i].sprite.plane, \
			params->vector);
		if (tmp)
		{
			params->t.istart = collision_value(g, \
				g->map.power_ups[sprt_i].sprite, tmp);
			if (check_if_pixel_can_put(g, params, \
				g->map.power_ups[sprt_i].sprite))
				return ;
		}
		sprt_i++;
	}
}
