/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:27:16 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/13 11:34:48 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing_state(t_parsing_state *state)
{
	state->r_state = FALSE;
	state->r_state_finish = FALSE;
	state->no_state = FALSE;
	state->no_state_finish = FALSE;
	state->so_state = FALSE;
	state->so_state_finish = FALSE;
	state->we_state = FALSE;
	state->we_state_finish = FALSE;
	state->ea_state = FALSE;
	state->ea_state_finish = FALSE;
	state->s_state = FALSE;
	state->s_state_finish = FALSE;
	state->f_state = FALSE;
	state->f_state_finish = FALSE;
	state->c_state = FALSE;
	state->c_state_finish = FALSE;
}

int	check_params_end(t_parsing_state state)
{
	if (state.r_state_finish && state.no_state_finish && state.so_state_finish \
		&& state.we_state_finish && state.ea_state_finish && \
			state.s_state_finish && state.f_state_finish \
				&& state.c_state_finish)
		return (1);
	return (0);
}

void	data_rnl_conditions(t_game *game, \
	char **splitted, t_parsing_state *state)
{
	if (ft_get_splitted_size(splitted) == (size_t)1)
	{
		error_display("Wrong parameter", splitted[0]);
		ft_destroy_splitted(splitted);
		quit_game(game);
	}
	else if (ft_get_splitted_size(splitted) > (size_t)0)
	{
		if (!is_path_flag(splitted) && ft_strcmp(splitted[0], "R"))
		{
			error_display("Wrong parameters", splitted[0]);
			ft_destroy_splitted(splitted);
			quit_game(game);
		}
		pars_by_flag(game, splitted, state);
	}
}

int	get_game_data_rnl(t_game *game, t_file *map, \
	char **splitted, t_parsing_state *state)
{
	int	i;

	i = 0;
	while (ft_read_next_line(map))
	{
		i++;
		splitted = ft_split(map->readed_line, " ");
		data_rnl_conditions(game, splitted, state);
		ft_destroy_splitted(splitted);
		if (check_params_end(*state))
			return (i);
	}
	return (i);
}

int	get_game_data(t_game *game)
{
	t_file			*map;
	t_parsing_state	state;
	char			**splitted;
	int				i;

	splitted = NULL;
	init_parsing_state(&state);
	map = ft_open_file(game->map.map_path, O_RDONLY);
	i = get_game_data_rnl(game, map, splitted, &state);
	ft_close_file(map);
	if (!check_params_end(state))
	{
		error_display("Wrong parameters", "map");
		ft_destroy_splitted(splitted);
		quit_game(game);
	}
	init_map(game, i);
	return (1);
}
