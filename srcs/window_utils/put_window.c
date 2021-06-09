/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:46:59 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 17:14:21 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_window_pixel_position(t_window window, int x, int y)
{
	return (y * window.real_width + x);
}

void	*ft_put_window(void *param)
{
	t_vector3		tempv;
	t_pthread_param	*t;

	t = param;
	t->params.p_index = -1 + t->game->threads_interval[t->id].istart;
	while (++t->params.p_index < t->game->threads_interval[t->id].istart + \
		t->game->threads_interval[t->id].istop)
	{
		tempv = rotate_vector_x(t->game->window->rcast_vectors[t->params.p_index], \
			t->game->player.orientationz * RADIAN);
		t->params.vector = rotate_vector_z(tempv, \
			t->game->player.orientationx * RADIAN);
		if (rcast_check_collider(t->game, &t->params) == 0)
			bettermlx_pixel_put(t->game, \
				t->game->window->rc_vect_p_index[t->params.p_index], \
					create_color(0, 0, 0, 0), 1);
		rcast_check_collider_sprites(t->game, &t->params);
		rcast_check_collider_sprites_power_up(t->game, &t->params);
	}
	return (0);
}
