/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:14:48 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:38:32 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dup_datas(t_game *game, int index_end)
{
	t_file	*map;
	int		i;

	i = 0;
	map = ft_open_file(game->map.map_path, O_RDONLY);
	while (ft_read_next_line(map))
	{
		if (index_end != 0)
			index_end--;
		else
		{
			game->map.map_datas[i] = ft_strdup(map->readed_line, FALSE);
			i++;
		}
	}
	game->map.map_datas[i] = ft_strdup(map->readed_line, FALSE);
	game->map.map_datas[i + 1] = NULL;
	ft_close_file(map);
}

int	init_map(t_game *game, int index_param_end)
{
	t_file		*map;
	int			i;
	int			tmp;

	i = 0;
	tmp = index_param_end;
	map = ft_open_file(game->map.map_path, O_RDONLY);
	while (ft_read_next_line(map))
	{
		if (tmp != 0)
			tmp--;
		else
			i++;
	}
	game->map.map_datas = ft_calloc(i + 2, sizeof(char *));
	if (!game->map.map_datas)
	{
		error_display("map malloc error", "game->map.map_datas");
		ft_close_file(map);
		quit_game(game);
	}
	ft_close_file(map);
	dup_datas(game, index_param_end);
	return (1);
}
