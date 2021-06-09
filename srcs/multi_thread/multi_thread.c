/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:59:15 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 15:02:32 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_multi_thread(t_game *game)
{
	int				i;
	t_pthread_param	**tab_tmp;

	tab_tmp = ft_calloc(THREADS, sizeof(t_pthread_param));
	if (!tab_tmp)
	{
		error_display("threads malloc error", "ft_multi_thread()");
		quit_game(game);
	}
	i = -1;
	while (++i < THREADS)
	{
		tab_tmp[i] = ft_init_pthread_param(game, i);
		pthread_create(&(game->threads[i]), NULL, &ft_put_window, tab_tmp[i]);
	}
	i = -1;
	while (++i < THREADS)
	{
		if (game->threads[i])
			pthread_join(game->threads[i], NULL);
		ft_fullfree((void *)tab_tmp[i]);
	}
	ft_fullfree((void *)tab_tmp);
	sprite_animation_with_time(game->player.current_anim);
	return (0);
}
