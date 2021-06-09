/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:19:34 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 12:01:34 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_r(t_game *game, char **splitted_line)
{
	if (ft_get_splitted_size(splitted_line) != (size_t)3)
	{
		error_display("Window size", "Wrong arguments");
		ft_destroy_splitted(splitted_line);
		quit_game(game);
	}
	if (ft_strlen(splitted_line[1]) > 5)
		game->window->width = 3200;
	else
		game->window->width = ft_atoi(splitted_line[1]);
	if (ft_strlen(splitted_line[2]) > 5)
		game->window->height = 1800;
	else
		game->window->height = ft_atoi(splitted_line[2]);
	if (game->window->width <= 200)
		game->window->width = 200;
	if (game->window->height <= 200)
		game->window->height = 200;
	if (game->window->width > 3200)
		game->window->width = 3200;
	if (game->window->height > 1800)
		game->window->height = 1800;
}
