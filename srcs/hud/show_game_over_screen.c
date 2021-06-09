/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_game_over_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:31 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 18:34:23 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_image_to_window(t_game *game, t_image *tmp)
{
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, tmp->img, 0, 0);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, \
		game->window->width / 2 - 50, game->window->height - \
			game->window->height / 3, color_to_int(\
				create_color(0, 255, 0, 0)), "Press Escape to Quit !");
	bettermlx_destroy_image(game->window, tmp);
}

void	show_game_over_screen(t_game *game)
{
	t_image		*tmp;
	t_color		color_tmp;
	int			y;
	int			x;

	tmp = bettermlx_init_image(game, game->window, \
		game->window->width, game->window->height);
	y = 0;
	while (y < tmp->height)
	{
		x = 0;
		while (x < tmp->width)
		{
			color_tmp = bettermlx_get_color(game->hud.black_screen, ft_map(x, \
				create_interval(0, tmp->width), create_interval(0, \
					game->hud.black_screen->width)), ft_map(y, \
						create_interval(0, tmp->height), create_interval(0, \
							game->hud.black_screen->height)));
			bettermlx_set_color(tmp, x, y, create_color(game->bs_value, \
				color_tmp.r, color_tmp.g, color_tmp.b));
			x++;
		}
		y++;
	}
	put_image_to_window(game, tmp);
}
