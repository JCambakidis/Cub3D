/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider_enemy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:58:21 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 14:25:43 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rcast_check_collider_sprites(t_game *g, t_check_collider_param *params)
{
	int						sprt_i;
	float					tmp;

	sprt_i = 0;
	while (sprt_i < g->map.enemy_counter)
	{
		if (ft_dst_vect_vect(g->player.location, \
			g->map.enemys[sprt_i].sprite.location) > \
				g->window->render_distance)
			return ;
		ft_dot_vector(&g->map.enemys[sprt_i].sprite.plane, \
			g->player.normal, g->map.enemys[sprt_i].sprite.location);
		tmp = mk_rcast_per_vect(g->map.enemys[sprt_i].sprite.plane, \
			params->vector);
		if (tmp)
		{
			params->t.istart = collision_value(g, \
				g->map.enemys[sprt_i].sprite, tmp);
			if (check_if_pixel_can_put(g, params, \
				g->map.enemys[sprt_i].sprite))
				return ;
		}
		sprt_i++;
	}
}
