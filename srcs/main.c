/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:13:39 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/03 16:17:48 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inits_and_hooks(t_game *game)
{
	game->fps = 0;
	get_game_data(game);
	init_window(game);
	init_threads(game);
	generate_minimap(game);
	game->debug_img = bettermlx_init_xpm_image(\
		game, game->window, "./textures/debug_bg.xpm");
	game->debug_img = rescale_img(game, game->debug_img, \
		game->window->width / 7, game->window->height / 6);
	mlx_hook(game->window->win_ptr, 2, 0, key_press_hook, game);
	mlx_hook(game->window->win_ptr, 3, 0, key_release_hook, game);
	mlx_hook(game->window->win_ptr, 4, 0, mouse_press_hook, game);
	mlx_hook(game->window->win_ptr, 5, 0, mouse_release_hook, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 17, quit_game, game);
	mlx_hook(game->window->win_ptr, 6, 1L << 6, &mouse_move, game);
	mlx_loop_hook(game->window->mlx_ptr, ft_exec, game);
	mlx_loop(game->window->mlx_ptr);
}

t_game	*calloc_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		error_display("game malloc error", "game");
		quit_game(game);
	}
	init_structs(game);
	game->bitmap = FALSE;
	game->window = ft_calloc(1, sizeof(t_window));
	if (!game->window)
	{
		error_display("window malloc error", "game->window");
		quit_game(game);
	}
	init_struct_window(game->window);
	game->threads = ft_calloc(THREADS, sizeof(pthread_t));
	if (!game->threads)
	{
		error_display("threads malloc error", "game->threads");
		quit_game(game);
	}	
	return (game);
}

void	check_map_parameter(t_game *game, char *argv)
{
	t_file	*map;

	game->map.map_path = argv;
	if (ft_strcmp(".cub", game->map.map_path + \
			(ft_strlen(game->map.map_path + 4))))
	{
		error_display("Wrong map", "Use only .cub file");
		quit_game(game);
	}
	map = ft_open_file(game->map.map_path, O_RDONLY);
	if (map == NULL)
	{
		error_display("Map error", "Wrong map path");
		ft_close_file(map);
		quit_game(game);
	}
	if (ft_read_next_line(map) == -1)
	{
		error_display("Wrong parameters", "Invalid file");
		ft_close_file(map);
		quit_game(game);
	}
	ft_close_file(map);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = calloc_game();
	(void)argc;
	(void)argv;
	if (argc == 1)
	{
		error_display("Wrong parameter", "No map path find");
		quit_game(game);
	}
	check_map_parameter(game, argv[1]);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
		{
			error_display("Wrong parameter", \
				"use '--save' to generate screenshoot");
			quit_game(game);
		}
		else
			game->bitmap = TRUE;
	}
	inits_and_hooks(game);
}
