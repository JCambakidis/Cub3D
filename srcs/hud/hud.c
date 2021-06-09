/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:57:08 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/13 11:56:39 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_hud(t_game *g)
{
	int	tmp;

	tmp = g->window->width / 2 - g->hud.life_bar_full->width / 2;
	if (g->player.life > 0)
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_full->img, tmp - g->hud.life_bar_full->width, 20);
	else
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_empty->img, tmp - g->hud.life_bar_full->width, 20);
	if (g->player.life > 1)
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_full->img, tmp, 20);
	else
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_empty->img, tmp, 20);
	if (g->player.life > 2)
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_full->img, tmp + g->hud.life_bar_full->width, 20);
	else
		mlx_put_image_to_window(g->window->mlx_ptr, g->window->win_ptr, \
			g->hud.life_bar_empty->img, tmp + g->hud.life_bar_full->width, 20);
}

void	put_life_hud_for_bitmap(t_game *g)
{
	int	tmp;

	tmp = g->window->width / 2 - g->hud.life_bar_full->width / 2;
	if (g->player.life > 0)
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_full, tmp - g->hud.life_bar_full->width, 20);
	else
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_empty, tmp - g->hud.life_bar_full->width, 20);
	if (g->player.life > 1)
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_full, tmp, 20);
	else
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_empty, tmp, 20);
	if (g->player.life > 2)
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_full, tmp + g->hud.life_bar_full->width, 20);
	else
		bettermlx_put_image_to_image(g->img, \
			g->hud.life_bar_empty, tmp + g->hud.life_bar_full->width, 20);
}
