/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_destroy_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:55:56 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 14:16:11 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*bettermlx_destroy_image(t_window *window, t_image *image)
{
	if (image != NULL)
	{
		mlx_destroy_image(window->mlx_ptr, image->img);
		free(image);
		image = NULL;
	}
	return (NULL);
}
