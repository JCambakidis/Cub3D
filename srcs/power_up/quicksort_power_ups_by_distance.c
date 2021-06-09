/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_power_ups_by_distance.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:03:30 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 14:15:15 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	quick_check_i_j(t_game *game, int i, int j, t_power_up *power_up)
{
	*power_up = game->map.power_ups[i];
	game->map.power_ups[i] = game->map.power_ups[j];
	game->map.power_ups[j] = *power_up;
}

static void	quick_set_j(t_game *game, int pivot, int *j)
{
	while (ft_dst_vect_vect(game->player.location, \
	game->map.power_ups[*j].sprite.location) > ft_dst_vect_vect(\
		game->player.location, game->map.power_ups[pivot].sprite.location))
		*j -= 1;
}

void	quicksort_power_ups_by_distance(t_game *game, \
	int index_start, int index_end)
{
	int			i;
	int			j;
	int			pivot;
	t_power_up	temp;

	if (index_start < index_end)
	{
		pivot = index_start;
		i = index_start;
		j = index_end;
		while (i < j)
		{
			while (ft_dst_vect_vect(game->player.location, \
			game->map.power_ups[i].sprite.location) <= ft_dst_vect_vect(\
				game->player.location, game->map.power_ups[pivot].sprite.location) && \
					i < index_end)
				i++;
			quick_set_j(game, pivot, &j);
			if (i < j)
				quick_check_i_j(game, i, j, &temp);
		}
		quick_check_i_j(game, pivot, j, &temp);
		quicksort_power_ups_by_distance(game, index_start, j - 1);
		quicksort_power_ups_by_distance(game, j + 1, index_end);
	}
}
