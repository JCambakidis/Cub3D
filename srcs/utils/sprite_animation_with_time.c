/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation_with_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:55:19 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:29 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_animation_with_time(t_anim *anim)
{
	long long	current_time;

	current_time = bettermlx_get_time();
	if (current_time - anim->animation_last_time >= \
		1000 / anim->animation_refresh_time)
	{
		anim->animation_index_width++;
		if (anim->animation_index_width >= anim->animation_frames_width)
		{
			anim->animation_index_height++;
			if (anim->animation_index_width * anim->animation_index_height \
				>= anim->animation_frames)
			{
				anim->animation_index_width = 0;
				anim->animation_index_height = \
					anim->animation_init_index_height;
			}
			anim->animation_index_width = 0;
		}
		anim->animation_last_time = current_time;
	}
}
