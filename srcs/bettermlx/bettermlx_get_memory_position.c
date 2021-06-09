/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_memory_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:41:25 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 14:16:19 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned char	*bettermlx_get_memory_position(t_image *image, int x, int y)
{
	unsigned char	*position;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (NULL);
	position = (unsigned char *)image->addr + y * image->line_length + x * 4;
	return (position);
}
