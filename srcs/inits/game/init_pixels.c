/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:14:05 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:10 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector3	create_rcast_vector(t_game *game, int i, int j)
{
	t_vector3	vect;
	float		norm;

	vect = create_vector(2 * tan(game->player.fov * RADIAN * 0.5) / \
		(game->window->real_width) * (i - game->window->real_width / 2), \
			-1, 2 * -tan(game->player.fov * RADIAN * 0.5) / (game->window->real_height) * \
				(j - game->window->real_height / 2));
	norm = distance3(vect.vx, vect.vy, vect.vz);
	vect.vx /= norm;
	vect.vy /= norm;
	vect.vz /= norm;
	return (vect);
}

void	add_pixels_values(t_game *game)
{
	int		i;
	int		j;
	int		index;

	j = -1;
	index = 0;
	while (++j < game->window->real_height)
	{
		i = -1;
		while (++i < game->window->real_width)
		{
			if (bettermlx_get_color(game->player.hud, \
				i * game->window->divider, j * game->window->divider).a != 0)
			{
				game->window->rcast_vectors[index] = \
					create_rcast_vector(game, i, j);
				game->window->rc_vect_p_index[index++] = \
					create_vector(j, i, 0);
				game->window->nbr_pixels++;
			}
		}
	}
}

int	init_pixels(t_game *game)
{
	game->window->nbr_pixels = 0;
	game->window->real_width = game->window->width / game->window->divider;
	game->window->real_height = game->window->height / game->window->divider;
	game->window->rcast_vectors = ft_calloc(game->window->real_width * \
		game->window->real_height + 1, sizeof(t_vector3));
	game->window->rc_vect_p_index = ft_calloc(game->window->real_width * \
		game->window->real_height + 1, sizeof(t_vector3));
	game->window->rc_vect_len_coll = ft_calloc(\
		game->window->real_width * game->window->real_height + 1, \
			sizeof(float));
	if (!game->window->rcast_vectors || \
		!game->window->rc_vect_p_index || \
			!game->window->rc_vect_len_coll)
	{
		error_display("window malloc error", "init_pixels()");
		quit_game(game);
	}
	add_pixels_values(game);
	return (1);
}
