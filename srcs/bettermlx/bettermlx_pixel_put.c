/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:45:08 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:10 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_datas(float *darkness, t_color *color)
{
	if (*darkness < 0)
		*darkness = 0;
	if (color->a == 255 || color->a < 0)
		return (0);
	return (1);
}

void	bettermlx_pixel_put(t_game *game, t_vector3 pixel_coordinates, \
	t_color color, float darkness)
{
	unsigned char	*destination;
	int				ay;
	int				my;
	int				ax;
	int				mx;

	if (!check_datas(&darkness, &color))
		return ;
	ay = (pixel_coordinates.vy) * game->window->divider;
	my = ay + game->window->divider;
	mx = (pixel_coordinates.vx) * game->window->divider + game->window->divider;
	while (ay < my)
	{
		ax = (pixel_coordinates.vx) * game->window->divider - 1;
		while (++ax < mx)
		{
			destination = (unsigned char *)game->img->addr + ax * \
				game->img->line_length + ay * 4;
			destination[0] = color.r * darkness;
			destination[1] = color.g * darkness;
			destination[2] = color.b * darkness;
			destination[3] = color.a;
		}
		ay++;
	}
}
