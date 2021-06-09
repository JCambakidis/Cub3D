/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:03:16 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:34:53 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_minimap(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->minimap.minimap = bettermlx_init_image(game, game->window, \
		game->map.walls_x_counter, game->map.walls_y_counter);
	game->minimap.minimap_save = bettermlx_init_image(game, game->window, \
		game->map.walls_x_counter, game->map.walls_y_counter);
	game->minimap.background = bettermlx_init_xpm_image(game, game->window, \
	"./textures/minimap_bg.xpm");
	while (++i < game->map.walls_y_counter)
	{
		j = -1;
		while (++j < game->map.walls_x_counter)
		{
			bettermlx_set_color(game->minimap.minimap, j, i, \
				create_color(255, 0, 0, 0));
			bettermlx_set_color(game->minimap.minimap_save, j, i, \
				create_color(255, 0, 0, 0));
		}
	}
	i = -1;
	while (game->map.map_datas[++i])
	{
		j = -1;
		while (game->map.map_datas[i][++j])
		{
			if (game->map.map_datas[i][j] == '1' || \
				game->map.map_datas[i][j] == 'A' || \
					game->map.map_datas[i][j] == 'Q')
			{
				bettermlx_set_color(game->minimap.minimap, j, i, \
					create_color(0, 255, 255, 255));
				bettermlx_set_color(game->minimap.minimap_save, j, i, \
					create_color(0, 255, 255, 255));
			}
		}
	}
	game->minimap.width = game->window->width / 5;
	game->minimap.height = game->window->height / 5;
	game->minimap.minimap = rescale_img(game, game->minimap.minimap, \
		game->minimap.width, game->minimap.height);
	game->minimap.minimap_save = rescale_img(game, game->minimap.minimap_save, \
		game->minimap.width, game->minimap.height);
	game->minimap.background = rescale_img(game, game->minimap.background, \
		game->minimap.width + 50, game->minimap.height + 50);
	i = -1;
	while (++i < game->map.enemy_counter)
		minimap_put_location_color(game, game->map.enemys[i].sprite.location, \
			create_color(0, 255, 0, 0));
	i = -1;
	while (++i < game->map.power_up_counter)
		minimap_put_location_color(game, game->map.power_ups[i].sprite.location, \
			create_color(0, 0, 255, 0));
}
