/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_location_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:25:55 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 15:56:30 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_put_location_color(t_game *game, \
	t_vector3 location, t_color color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = ft_map(location.vx, create_interval(0, \
		game->map.walls_x_counter), \
			create_interval(0, game->minimap.width)) - 0.6;
	y = ft_map(location.vy, create_interval(0, \
		game->map.walls_y_counter), \
			create_interval(0, game->minimap.height)) - 0.6;
	i = -1;
	while (++i < game->minimap.width / game->map.walls_x_counter - 2)
	{
		j = -1;
		while (++j < game->minimap.height / game->map.walls_y_counter - 2)
			bettermlx_set_color(game->minimap.minimap, x + i, y + j, color);
	}
}

void	minimap_reset_location_color(t_game *game, t_vector3 location)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = ft_map(location.vx, create_interval(0, \
		game->map.walls_x_counter), create_interval(0, \
			game->minimap.width)) - 0.6;
	y = ft_map(location.vy, create_interval(0, \
		game->map.walls_y_counter), create_interval(0, \
			game->minimap.height)) - 0.6;
	i = -1;
	while (++i < game->minimap.width / game->map.walls_x_counter - 2)
	{
		j = -1;
		while (++j < game->minimap.height / game->map.walls_y_counter - 2)
			bettermlx_set_color(game->minimap.minimap, x + i, y + j, \
				bettermlx_get_color(game->minimap.minimap_save, x + i, y + j));
	}
}
