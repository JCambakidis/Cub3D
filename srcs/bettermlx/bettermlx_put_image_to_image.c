/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_put_image_to_image.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:46:47 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/09 15:58:56 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bettermlx_put_image_to_image(t_image *dst, t_image *src, int x, int y)
{
	t_color	color;
	int		src_x;
	int		src_y;
	int		dst_x;
	int		dst_y;

	src_y = 0;
	dst_y = y;
	while (src_y < src->height && dst_y < dst->height)
	{
		src_x = 0;
		dst_x = x;
		while (src_x < src->width && dst_x < dst->width)
		{
			color = bettermlx_get_color(src, src_x, src_y);
			if (color.a == 0)
				bettermlx_set_color(dst, dst_x, dst_y, color);
			dst_x++;
			src_x++;
		}
		dst_y++;
		src_y++;
	}
}
