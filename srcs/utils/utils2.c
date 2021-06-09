/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:27:35 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:40 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_dst_vect_vect(t_vector3 v1, t_vector3 v2)
{
	return (sqrt((v2.vx - v1.vx) * (v2.vx - v1.vx) + \
		(v2.vy - v1.vy) * (v2.vy - v1.vy)));
}

int	animation_end(t_anim anim)
{
	return (anim.animation_frames_width - 1 == anim.animation_index_width);
}

t_image	*rescale_img(t_game *game, t_image *src_img, \
	int dst_width, int dst_height)
{
	t_image		*tmp;
	int			y;
	int			x;

	tmp = bettermlx_init_image(game, game->window, dst_width, dst_height);
	y = 0;
	while (y < tmp->height)
	{
		x = 0;
		while (x < tmp->width)
		{
			bettermlx_set_color(tmp, x, y, bettermlx_get_color(\
				src_img, ft_map(x, create_interval(0, tmp->width), \
					create_interval(0, src_img->width)), \
						ft_map(y, create_interval(0, tmp->height), \
							create_interval(0, src_img->height))));
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->window->mlx_ptr, src_img->img);
	free(src_img);
	return (tmp);
}

void	ft_fullfree(void *param)
{
	free(param);
	param = NULL;
}
