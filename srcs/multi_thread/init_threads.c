/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:57:14 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:25:36 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_threads(t_game *game)
{
	int	i;
	int	index_length;

	i = -1;
	index_length = (game->window->nbr_pixels) / THREADS;
	game->threads_interval = ft_calloc(THREADS, sizeof(t_interval));
	if (!game->threads_interval)
	{
		error_display("threads malloc error", "game->threads_interval");
		quit_game(game);
	}
	while (++i < THREADS)
		game->threads_interval[i] = \
			create_interval(index_length * i, index_length);
	return (1);
}

t_pthread_param	*ft_init_pthread_param(t_game *game, int id)
{
	t_pthread_param	*result;

	result = ft_calloc(1, sizeof(t_pthread_param));
	if (!result)
	{
		error_display("threads malloc error", "ft_init_pthread_param()");
		quit_game(game);
	}
	result->game = game;
	result->id = id;
	return (result);
}
