/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:13:19 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 17:30:41 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_walls(t_game *game, int index, int width_len)
{
	int	i;

	game->map.walls = ft_calloc(index + 2, sizeof(t_wall));
	if (!game->map.walls)
	{
		error_display("map malloc error", "game->map.walls");
		quit_game(game);
	}
	game->map.walls_counter = index;
	i = -1;
	index = -1;
	while (game->map.map_datas[++i])
		game->map.walls[++index] = create_wall(0, 1, 0, -i);
	game->map.walls_y_counter = i;
	i = -1;
	while (++i <= width_len)
		game->map.walls[++index] = create_wall(1, 0, 0, -i);
	game->map.walls_x_counter = i;
	game->map.walls[++index] = create_wall(0, 0, 1, 0.01);
	game->map.walls[++index] = create_wall(0, 0, 1, -1.01);
}

void	init_walls(t_game *game)
{
	int		index;
	int		i;
	size_t	j;
	int		width_len;

	index = 0;
	i = -1;
	j = 0;
	while (game->map.map_datas[++i])
	{
		index++;
		if (j < ft_strlen(game->map.map_datas[i]))
		{
			j = ft_strlen(game->map.map_datas[i]);
			width_len = j;
		}
	}
	index += j + 2;
	set_walls(game, index, width_len);
}
