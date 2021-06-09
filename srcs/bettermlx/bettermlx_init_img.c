/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:16:48 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 17:33:27 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*bettermlx_init_image(t_game *game, \
	t_window *window, int width, int height)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
	{
		error_display("image malloc error", "image");
		quit_game(game);
	}
	image->width = width;
	image->height = height;
	image->img = mlx_new_image(window->mlx_ptr, width, height);
	if (!image->img)
	{
		error_display("image malloc error", "image->img");
		quit_game(game);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
	if (!image->addr)
	{
		error_display("image malloc error", "image->addr");
		quit_game(game);
	}
	return (image);
}
