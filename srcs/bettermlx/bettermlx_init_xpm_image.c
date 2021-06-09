/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_xpm_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:31:23 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 17:34:01 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*bettermlx_init_xpm_image(t_game *game, t_window *window, char *path)
{
	t_image	*image;

	if (path)
	{
		image = ft_calloc(1, sizeof(t_image));
		if (image == NULL)
		{
			error_display("image malloc error", "xpm image");
			quit_game(game);
		}
		image->width = 0;
		image->height = 0;
		image->img = mlx_xpm_file_to_image(window->mlx_ptr, \
		path, &image->width, &image->height);
		if (image->img == NULL)
		{
			free(image);
			error_display("image malloc error", "xpm image->img");
			quit_game(game);
		}
		image->addr = mlx_get_data_addr(image->img, \
			&image->bits_per_pixel, &image->line_length, &image->endian);
		return (image);
	}
	return (NULL);
}
