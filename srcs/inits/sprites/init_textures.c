/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:42:21 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 17:25:48 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_textures	init_wall_bis_path(char *no_path, \
	char *so_path, char *we_path, char *ea_path)
{
	t_textures	result;

	result.no_wall.path = no_path;
	result.so_wall.path = so_path;
	result.we_wall.path = we_path;
	result.ea_wall.path = ea_path;
	result.floor_wall.path = NULL;
	result.roof_wall.path = NULL;
	result.roof_wall.texture = NULL;
	result.floor_wall.texture = NULL;
	return (result);
}

void	init_walls_textures(t_game *game, t_textures *textures)
{
	textures->ea_wall.texture = bettermlx_init_xpm_image(\
		game, game->window, textures->ea_wall.path);
	textures->no_wall.texture = bettermlx_init_xpm_image(\
		game, game->window, textures->no_wall.path);
	textures->so_wall.texture = bettermlx_init_xpm_image(\
		game, game->window, textures->so_wall.path);
	textures->we_wall.texture = bettermlx_init_xpm_image(\
		game, game->window, textures->we_wall.path);
	if (textures->floor_wall.path)
		textures->floor_wall.texture = bettermlx_init_xpm_image(\
			game, game->window, textures->floor_wall.path);
	if (textures->roof_wall.path)
	{
		textures->roof_wall.texture = bettermlx_init_xpm_image(\
			game, game->window, textures->roof_wall.path);
	}
}
