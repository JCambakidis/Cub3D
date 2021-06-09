/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:10:53 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 19:19:50 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_orientation_and_position(t_game *game, int x, int y)
{
	if (game->player.location.vx != -1)
	{
		error_display("player location error", "Too much location");
		quit_game(game);
	}
	game->player.location.vx = x + 0.5;
	game->player.location.vy = y + 0.5;
	if (game->map.map_datas[y][x] == 'N')
		game->player.orientationx = 360;
	if (game->map.map_datas[y][x] == 'S')
		game->player.orientationx = 180;
	if (game->map.map_datas[y][x] == 'E')
		game->player.orientationx = 270;
	if (game->map.map_datas[y][x] == 'W')
		game->player.orientationx = 90;
	game->map.map_datas[y][x] = '0';
}

void	calloc_player_anims(t_game *game)
{
	game->player.anims = ft_calloc(5, sizeof(t_anim *));
	if (!game->player.anims)
	{
		error_display("player malloc error", "game->player.anims");
		quit_game(game);
	}
}

int	is_position_flag(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	init_player_pos(t_game *game, float zlocation)
{
	int	x;
	int	y;

	y = -1;
	calloc_player_anims(game);
	while (game->map.map_datas[++y])
	{
		x = -1;
		while (game->map.map_datas[y][++x])
		{
			if (is_position_flag(game->map.map_datas[y][x]))
				init_player_orientation_and_position(game, x, y);
		}
	}
	if (game->player.orientationx == -1)
	{
		error_display("location error", "player position in map not found !");
		quit_game(game);
	}
	game->player.player_plane = create_wall(1, 0, 0, -y);
	set_player_parameters(game, zlocation);
	return (1);
}
