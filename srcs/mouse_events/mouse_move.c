/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:53:09 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 15:26:13 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	mlx_mouse_hide(game->window->mlx_ptr, game->window->win_ptr);
	game->player.mouse.diff_pos_x = x - game->player.mouse.pos_x;
	game->player.mouse.diff_pos_y = y - game->player.mouse.pos_y;
	mlx_mouse_move(game->window->win_ptr,
		game->window->width / 2, game->window->height / 2);
	mlx_mouse_get_pos(game->window->win_ptr, \
		&game->player.mouse.pos_x, &game->player.mouse.pos_y);
	if (game->player.mouse.diff_pos_x > 0)
		game->player.orientationx += ROTATION_SPEED * ft_map(\
			game->player.mouse.diff_pos_x, create_interval(0, 100), \
				create_interval(0, M_SENSIBILITY)) * game->delta_time;
	else if (game->player.mouse.diff_pos_x < 0)
		game->player.orientationx -= ROTATION_SPEED * -ft_map(\
			game->player.mouse.diff_pos_x, create_interval(0, 100), \
				create_interval(0, M_SENSIBILITY)) * game->delta_time;
	if (game->player.mouse.diff_pos_y > 0 && game->player.orientationz < 45)
		game->player.orientationz += ROTATION_SPEED * ft_map(\
			game->player.mouse.diff_pos_y, create_interval(0, 100), \
				create_interval(0, M_SENSIBILITY)) * game->delta_time;
	else if (game->player.mouse.diff_pos_y < 0 \
		&& game->player.orientationz > -45)
		game->player.orientationz -= ROTATION_SPEED * -ft_map(\
			game->player.mouse.diff_pos_y, create_interval(0, 100), \
				create_interval(0, M_SENSIBILITY)) * game->delta_time;
	return (0);
}
