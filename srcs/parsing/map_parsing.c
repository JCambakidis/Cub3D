/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:56:18 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 19:30:51 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parsing_error(t_game *game)
{
	error_display("Map parsing", "Invalid map !");
	quit_game(game);
}

int	check_walls_flag(char c)
{
	return (c == 'A' || c == '1' || c == '0' || c == 'Q');
}

void	check_zero(t_game *game, t_map *map, int x, int y)
{
	if (y == 0 || x == 0 || y == map->walls_y_counter - 1 \
		|| x == map->walls_x_counter - 1)
		map_parsing_error(game);
	if (map->map_datas[y - 1][x] && \
		!check_walls_flag(map->map_datas[y - 1][x]))
		map_parsing_error(game);
	if (map->map_datas[y + 1][x] && \
		!check_walls_flag(map->map_datas[y + 1][x]))
		map_parsing_error(game);
	if (map->map_datas[y][x - 1] && \
		!check_walls_flag(map->map_datas[y][x - 1]))
		map_parsing_error(game);
	if (map->map_datas[y][x + 1] && \
		!check_walls_flag(map->map_datas[y][x + 1]))
		map_parsing_error(game);
	if ((ft_strlen(map->map_datas[y - 1]) < \
		ft_strlen(map->map_datas[y]) && !check_walls_flag(\
			map->map_datas[y - 1][x])) || \
				(ft_strlen(map->map_datas[y + 1]) < \
					ft_strlen(map->map_datas[y]) && \
						!check_walls_flag(\
							map->map_datas[y + 1][x])))
		map_parsing_error(game);
}

void	map_parsing_checker(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map_datas[++y])
	{
		x = -1;
		while (map->map_datas[y][++x])
		{
			if (map->map_datas[y][x] == '0')
				check_zero(game, map, x, y);
		}
	}
}
