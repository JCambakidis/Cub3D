/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:38:37 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:40:51 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bdata(t_game *game, int fd)
{
	unsigned char	buffer[4];
	t_color			color;
	int				x;
	int				y;

	y = game->window->height;
	while (y > 0)
	{
		x = 0;
		while (x < game->window->width)
		{
			color = bettermlx_get_color(game->img, x, y);
			if (color.a == 0)
			{
				buffer[0] = (unsigned char)(color.b);
				buffer[1] = (unsigned char)(color.g);
				buffer[2] = (unsigned char)(color.r);
				buffer[3] = (unsigned char)(color.a);
				write(fd, buffer, 4);
			}
			x++;
		}
		y--;
	}
}

void	ft_binfo(t_game *game, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = game->window->width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = game->window->height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_game *game, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = game->window->width * game->window->height * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int	create_bitmap(t_game *game)
{
	int		fd;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bettermlx_put_image_to_image(game->img, game->player.hud, 0, 0);
	bettermlx_put_image_to_image(game->img, \
		game->player.current_anim->\
			rescale_frames[game->player.current_anim->\
				animation_index_width], 0, 0);
	put_life_hud_for_bitmap(game);
	ft_bfile(game, fd);
	ft_binfo(game, fd);
	ft_bdata(game, fd);
	close(fd);
	quit_game(game);
	return (1);
}
