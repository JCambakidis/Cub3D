/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale_frames_in_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:42:07 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:17 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rescale_frames_in_loop(t_anim *anim, t_image **tab, int i)
{
	int	y;
	int	x;

	y = -1;
	while (++y < tab[i]->height)
	{
		x = -1;
		while (++x < tab[i]->width)
		{
			bettermlx_set_color(tab[i], x, y, bettermlx_get_color(\
				anim->sprite, ft_map(x, create_interval(0, tab[i]->width), \
					create_interval(anim->animation_width * i, \
						anim->animation_width * (i + 1))), ft_map(y, \
							create_interval(0, tab[i]->height), \
								create_interval(0, \
									anim->animation_height))));
		}
	}
}

t_image	**rescale_frames_in_tab(t_game *game, t_anim *anim, t_interval dst_size)
{
	t_image		**tab;
	int			i;

	i = -1;
	tab = ft_calloc(anim->animation_frames + 1, sizeof(t_image *));
	if (!tab)
	{
		error_display("malloc error", "rescale_frames_in_tab()");
		quit_game(game);
	}
	while (++i < anim->animation_frames)
	{
		tab[i] = bettermlx_init_image(game, game->window, \
			dst_size.istart, dst_size.istop);
		rescale_frames_in_loop(anim, tab, i);
	}
	return (tab);
}
