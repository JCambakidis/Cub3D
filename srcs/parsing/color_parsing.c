/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:13:51 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 19:09:21 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	color_flags_parsing_checker(t_sprite_display *sprite, \
	t_color color, char *flag, char *splitted_line)
{
	if (!ft_strcmp(splitted_line, flag))
	{
		sprite->color = color;
		sprite->path = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	s_color_flag_parsing(t_game *game, char **splitted_line)
{
	if (!ft_strcmp(splitted_line[0], "S"))
	{
		error_display("Color on sprite", splitted_line[1]);
		ft_destroy_splitted(splitted_line);
		quit_game(game);
	}
}

void	color_flags_parsing(t_game *game, \
	char **splitted_line, t_parsing_state *state)
{
	t_color	color;

	color = error_parsing_color(game, splitted_line);
	if (!state->no_state_finish)
		state->no_state_finish = color_flags_parsing_checker(\
			&game->textures.no_wall, color, "NO", splitted_line[0]);
	if (!state->so_state_finish)
		state->so_state_finish = color_flags_parsing_checker(\
			&game->textures.so_wall, color, "SO", splitted_line[0]);
	if (!state->ea_state_finish)
		state->ea_state_finish = color_flags_parsing_checker(\
			&game->textures.ea_wall, color, "EA", splitted_line[0]);
	if (!state->we_state_finish)
		state->we_state_finish = color_flags_parsing_checker(\
			&game->textures.we_wall, color, "WE", splitted_line[0]);
	if (!state->f_state_finish)
		state->f_state_finish = color_flags_parsing_checker(\
			&game->textures.floor_wall, color, "F", splitted_line[0]);
	if (!state->c_state_finish)
		state->c_state_finish = color_flags_parsing_checker(\
			&game->textures.roof_wall, color, "C", splitted_line[0]);
	s_color_flag_parsing(game, splitted_line);
}
