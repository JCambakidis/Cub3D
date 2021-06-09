/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:49:02 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/13 14:20:53 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_enemy(t_game *game, t_interval xy, int zlocation, int *count)
{
	if (game->map.map_datas[(int)xy.istop][(int)xy.istart] == '2')
	{
		game->map.map_datas[(int)xy.istop][(int)xy.istart] = '0';
		game->map.enemys[*count] = ft_create_enemy(game, create_wall(1, 0, 0, -(int)xy.istop), \
			create_vector((int)xy.istart + 0.5, \
				(int)xy.istop + 0.5, zlocation));
		*count += 1;
	}
}

void	check_object(t_game *game, t_interval xy, int zlocation, int *count)
{
	if (game->map.map_datas[(int)xy.istop][(int)xy.istart] == 'H')
	{
		game->map.map_datas[(int)xy.istop][(int)xy.istart] = '0';
		game->map.power_ups[*count] = ft_create_power_up(\
			game, create_wall(1, 0, 0, -(int)xy.istop), create_vector(\
				(int)xy.istart + 0.5, (int)xy.istop + 0.5, zlocation));
		*count += 1;
	}
}

void	create_sprites(t_game *game, int zlocation)
{
	int	x;
	int	y;
	int	count;
	int	obj_count;

	y = -1;
	count = 0;
	obj_count = 0;
	while (game->map.map_datas[++y])
	{
		x = -1;
		while (game->map.map_datas[y][++x])
		{
			check_enemy(game, create_interval(x, y), zlocation, &count);
			check_object(game, create_interval(x, y), zlocation, &obj_count);
		}
	}
}

void	calloc_sprites(t_game *game, int enemy_count, int object_count)
{
	game->map.enemy_counter = enemy_count;
	game->map.enemys = ft_calloc(enemy_count + 1, sizeof(t_enemy));
	if (!game->map.enemys)
	{
		error_display("enemy malloc error", "game->map.enemys");
		quit_game(game);
	}
	game->map.power_up_counter = object_count;
	game->map.power_ups = ft_calloc(object_count + 1, sizeof(t_power_up));
	if (!game->map.power_ups)
	{
		error_display("power up malloc error", "game->map.power_ups");
		quit_game(game);
	}
}

void	init_sprites(t_game *game, float zlocation)
{
	int	x;
	int	y;
	int	count;
	int	objects_count;

	y = -1;
	count = 0;
	(void)zlocation;
	objects_count = 0;
	while (game->map.map_datas[++y])
	{
		x = -1;
		while (game->map.map_datas[y][++x])
		{
			if (game->map.map_datas[y][x] == '2')
				count++;
			if (game->map.map_datas[y][x] == 'H')
				objects_count++;
		}
	}
	calloc_sprites(game, count, objects_count);
	create_sprites(game, zlocation);
}
