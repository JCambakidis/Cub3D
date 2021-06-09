/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:50:01 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/16 16:34:36 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_y_elems(t_game *game, t_check_collider_param *params)
{
	if (params->elem_index >= 0 && params->vector.vy < 0)
		params->elem_index--;
	else if (params->elem_index <= game->map.walls_y_counter && \
		params->vector.vy > 0)
		params->elem_index++;
	if ((params->elem_index == -1 || params->elem_index == game->map.walls_y_counter + 1 \
		|| params->elem_index < game->player.location.vy - \
			game->window->render_distance - 1 || \
				params->elem_index > game->player.location.vy + \
				game->window->render_distance + 1))
	{
		params->elem_index = game->player.location.vx + \
			game->map.walls_y_counter;
		params->y_elem = FALSE;
	}
}

void	select_x_elems(t_game *game, t_check_collider_param *params)
{
	if (params->elem_index >= game->map.walls_y_counter && \
		params->vector.vx < 0)
		params->elem_index--;
	else if (params->elem_index <= game->map.walls_x_counter + \
		game->map.walls_y_counter && params->vector.vx > 0)
		params->elem_index++;
	if (params->elem_index == game->map.walls_y_counter - 1 || \
		params->elem_index == game->map.walls_x_counter + game->map.walls_y_counter || \
			params->elem_index - game->map.walls_y_counter < \
				game->player.location.vx - game->window->render_distance - 1 || \
					params->elem_index - game->map.walls_y_counter > \
						game->player.location.vx + \
							game->window->render_distance + 1)
	{
		params->elem_index = game->map.walls_x_counter + \
			game->map.walls_y_counter;
		params->x_elem = FALSE;
	}
}

void	select_looking_elements(t_game *game, t_check_collider_param *params)
{
	if (params->y_elem)
		select_y_elems(game, params);
	else if (params->elem_index >= game->map.walls_y_counter && params->elem_index <= \
		game->map.walls_y_counter + game->map.walls_x_counter && params->x_elem)
		select_x_elems(game, params);
	else
		params->elem_index++;
}
