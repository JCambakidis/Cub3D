/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_debugs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:10:37 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 17:17:11 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_fps(t_game *game)
{
	char	result[8];

	result[0] = 'F';
	result[1] = 'P';
	result[2] = 'S';
	result[3] = ':';
	result[4] = ' ';
	result[5] = game->fps / 10 + 48;
	result[6] = game->fps % 10 + 48;
	result[7] = '\0';
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, \
		game->window->width - 100, 30, color_to_int(create_color(0, 0, 255, 255)), \
			result);
}

void	show_fov(t_game *game)
{
	char	result[6];
	char	*tmp;

	result[0] = 'F';
	result[1] = 'O';
	result[2] = 'V';
	result[3] = ':';
	result[4] = ' ';
	result[5] = 0;
	tmp = ft_append_strs(result, ft_itoa(game->player.fov), FALSE, TRUE);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, \
		game->window->width - 100, 40, color_to_int(create_color(0, 255, 125, 125)), \
			tmp);
	ft_fullfree(tmp);
}

void	show_render_distance(t_game *game)
{
	char	result[6];
	char	*tmp;

	result[0] = 'R';
	result[1] = ' ';
	result[2] = 'D';
	result[3] = ':';
	result[4] = ' ';
	result[5] = 0;
	tmp = ft_append_strs(result, \
		ft_itoa(game->window->render_distance), FALSE, TRUE);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, \
		game->window->width - 100, 50, color_to_int(create_color(0, 0, 255, 125)), \
			tmp);
	ft_fullfree(tmp);
}

void	show_divider(t_game *game)
{
	char	result[6];
	char	*tmp;

	result[0] = 'D';
	result[1] = 'I';
	result[2] = 'V';
	result[3] = ':';
	result[4] = ' ';
	result[5] = 0;
	tmp = ft_append_strs(result, ft_itoa(game->window->divider), FALSE, TRUE);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, \
		game->window->width - 100, 60, color_to_int(create_color(0, 0, 125, 255)), \
			tmp);
	ft_fullfree(tmp);
}

void	show_debug(t_game *game)
{
	char	result[8];
	char	*tmp;

	result[0] = 'D';
	result[1] = 'E';
	result[2] = 'B';
	result[3] = 'U';
	result[4] = 'G';
	result[5] = ':';
	result[6] = ' ';
	result[7] = 0;
	tmp = ft_append_strs(result, ft_itoa(game->player.debug_mode), FALSE, TRUE);
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 50, 30, color_to_int(create_color(0, 255, 0, 125)), \
			tmp);
	ft_fullfree(tmp);
}
