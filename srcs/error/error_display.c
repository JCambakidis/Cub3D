/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:54:27 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/12 18:57:01 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_game(t_game *game)
{
	free_game(game);
	exit(0);
}

void	error_display(char *error_type, char *error_location)
{
	printf("Error\n(%s) %s\n", error_type, error_location);
}

void	error_parsing_path(t_game *game, char **splitted_line)
{
	t_file		*texture;

	texture = ft_open_file(splitted_line[1], O_RDONLY);
	if (!texture)
	{
		error_display("Path error", splitted_line[0]);
		ft_destroy_splitted(splitted_line);
		quit_game(game);
	}
	else
		ft_close_file(texture);
}

int	ft_str_to_int(char *str)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	while (str[++i])
	{
		result += str[i] - 48;
		result *= 10;
	}
	result /= 10;
	return (result);
}

t_color	error_parsing_color(t_game *game, char **splitted_line)
{
	t_color	color;
	char	**splitted_color;

	splitted_color = ft_split(splitted_line[1], ",");
	if (ft_get_splitted_size(splitted_color) > 3 \
		|| ft_get_splitted_size(splitted_color) < 3)
	{
		ft_destroy_splitted(splitted_color);
		splitted_color = ft_split(splitted_line[1], ".");
	}
	if (ft_get_splitted_size(splitted_color) > 3 \
		|| ft_get_splitted_size(splitted_color) < 3)
	{
		error_display("Color error", splitted_line[0]);
		ft_destroy_splitted(splitted_color);
		quit_game(game);
	}
	color.a = 0;
	color.r = (unsigned char)ft_str_to_int(splitted_color[0]);
	color.g = (unsigned char)ft_str_to_int(splitted_color[1]);
	color.b = (unsigned char)ft_str_to_int(splitted_color[2]);
	ft_destroy_splitted(splitted_color);
	return (color);
}
