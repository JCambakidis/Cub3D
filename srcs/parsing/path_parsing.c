/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:15:45 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 18:02:41 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_path_flag(char **splitted_line)
{
	if (!ft_strcmp(splitted_line[0], "NO") || \
		!ft_strcmp(splitted_line[0], "SO") || \
			!ft_strcmp(splitted_line[0], "EA") || \
				!ft_strcmp(splitted_line[0], "WE") || \
					!ft_strcmp(splitted_line[0], "S") || \
						!ft_strcmp(splitted_line[0], "F") || \
							!ft_strcmp(splitted_line[0], "C"))
		return (1);
	return (0);
}

void	path_flags_check_parsing(char **texture_path, \
	char **splitted_line, char *flag, t_bool *bool_state)
{
	if (!ft_strcmp(splitted_line[0], flag))
	{
		if (*texture_path != NULL)
			ft_fullfree(*texture_path);
		*texture_path = ft_strdup(splitted_line[1], FALSE);
		*bool_state = TRUE;
	}
}

void	path_flags_parsing(t_game *game, \
	char **splitted_line, t_parsing_state *state)
{
	path_flags_check_parsing(&game->textures.no_wall.path, \
		splitted_line, "NO", &state->no_state_finish);
	path_flags_check_parsing(&game->textures.so_wall.path, \
		splitted_line, "SO", &state->so_state_finish);
	path_flags_check_parsing(&game->textures.we_wall.path, \
		splitted_line, "WE", &state->we_state_finish);
	path_flags_check_parsing(&game->textures.ea_wall.path, \
		splitted_line, "EA", &state->ea_state_finish);
	path_flags_check_parsing(&game->map.sprite_idle_texture_path, \
		splitted_line, "S", &state->s_state_finish);
	path_flags_check_parsing(&game->textures.floor_wall.path, \
		splitted_line, "F", &state->f_state_finish);
	path_flags_check_parsing(&game->textures.roof_wall.path, \
		splitted_line, "C", &state->c_state_finish);
}

void	pars_by_flag_splitted_part(t_game *game, \
	char **splitted_line, t_parsing_state *state)
{
	if (ft_get_splitted_size(splitted_line) > (size_t)2)
	{
		error_display("Too many arguments", splitted_line[0]);
		ft_destroy_splitted(splitted_line);
		quit_game(game);
	}
	if (is_path_flag(splitted_line))
	{
		if (!ft_strcmp(".xpm", splitted_line[1] + \
			(ft_strlen(splitted_line[1] + 4))))
		{
			error_parsing_path(game, splitted_line);
			path_flags_parsing(game, splitted_line, state);
		}
		else
			color_flags_parsing(game, splitted_line, state);
	}
}

int	pars_by_flag(t_game *game, char **splitted_line, t_parsing_state *state)
{
	if (ft_get_splitted_size(splitted_line) > (size_t)3)
	{
		error_display("To many arguments", splitted_line[0]);
		ft_destroy_splitted(splitted_line);
		quit_game(game);
	}
	if (!ft_strcmp(splitted_line[0], "R"))
	{
		get_r(game, splitted_line);
		state->r_state_finish = TRUE;
		return (1);
	}
	pars_by_flag_splitted_part(game, splitted_line, state);
	return (1);
}
