/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_texture_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:59:04 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 16:16:29 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_make_x_sprite_utils(float *ac, float ab)
{
	if (ab >= 0)
		*ac = 0.5 - *ac;
	else
		*ac += 0.5;
}

float	ft_make_x_sprite(t_player player, \
	t_vector3 location, float ab, float bc)
{
	float	ac;

	if (ab > 0.5 || ab < -0.5 || bc > 0.5 || bc < -0.5)
		return (0);
	ac = sqrt(bc * bc + ab * ab);
	if (player.location.vy < location.vy)
		ft_make_x_sprite_utils(&ac, ab);
	else if (!ab)
	{
		if (bc < 0)
			ac = 0.5 - ac;
		else
			ac += 0.5;
	}
	else
		ft_make_x_sprite_utils(&ac, ab);
	return (ac);
}

t_color	generate_color_by_parsing(unsigned char *destination)
{
	t_color	result_color;

	result_color.r = destination[0];
	result_color.g = destination[1];
	result_color.b = destination[2];
	result_color.a = destination[3];
	return (result_color);
}
