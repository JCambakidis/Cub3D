/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:45:27 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:30:25 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_keyboard(t_game *game)
{
	game->key_pressed.down_pressed = FALSE;
	game->key_pressed.up_pressed = FALSE;
	game->key_pressed.left_pressed = FALSE;
	game->key_pressed.right_pressed = FALSE;
	game->key_pressed.w_pressed = FALSE;
	game->key_pressed.s_pressed = FALSE;
	game->key_pressed.a_pressed = FALSE;
	game->key_pressed.d_pressed = FALSE;
	game->key_pressed.fly_up_pressed = FALSE;
	game->key_pressed.fly_down_pressed = FALSE;
	game->key_pressed.minimap = FALSE;
}
