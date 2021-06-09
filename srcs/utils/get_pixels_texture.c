/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:06:33 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 16:18:09 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	ft_get_pixel_texture_y(t_image *texture, t_vector3 r_result)
{
	int		x;
	int		y;
	char	*destination;

	x = ((r_result.vy - (int)r_result.vy) * texture->width);
	y = texture->height - (r_result.vz - (int)r_result.vz) * texture->height;
	destination = texture->addr + y * texture->line_length + x * 4;
	return (generate_color_by_parsing(\
		(unsigned char *)destination));
}

t_color	ft_get_pixel_texture_x(t_image *texture, t_vector3 r_result)
{
	int		x;
	int		y;
	char	*destination;

	x = ((r_result.vx - (int)r_result.vx) * texture->width);
	y = texture->height - (r_result.vz - (int)r_result.vz) * texture->height;
	destination = texture->addr + y * texture->line_length + x * 4;
	return (generate_color_by_parsing(\
		(unsigned char *)destination));
}

t_color	ft_get_pixel_texture_z(t_image *texture, t_vector3 r_result)
{
	int		x;
	int		y;
	char	*destination;

	x = ((r_result.vx - (int)r_result.vx) * texture->width);
	y = texture->height - (r_result.vy - (int)r_result.vy) * texture->height;
	destination = texture->addr + y * texture->line_length + x * 4;
	return (generate_color_by_parsing(\
		(unsigned char *)destination));
}

t_color	ft_get_pixel_texture_sprite(t_player player, \
	t_sprite *sprite, t_vector3 r_result)
{
	int				x;
	int				y;
	float			temp;
	unsigned char	*destination;

	if (!sprite)
		return (create_color(0, 0, 0, 0));
	sprite_animation_with_time(sprite->current_animation);
	temp = sqrt(pow(r_result.vx - sprite->location.vx, 2) + \
		pow(r_result.vy - sprite->location.vy, 2));
	x = ft_make_x_sprite(player, sprite->location, r_result.vx - \
		sprite->location.vx, r_result.vy - sprite->location.vy) * \
		sprite->current_animation->animation_width + \
			(sprite->current_animation->animation_width * \
				sprite->current_animation->animation_index_width);
	y = sprite->current_animation->animation_height - r_result.vz * \
		sprite->current_animation->animation_height + \
		(sprite->current_animation->animation_height * \
			sprite->current_animation->animation_index_height);
	destination = (unsigned char *)sprite->current_animation->sprite->addr + y * \
		sprite->current_animation->sprite->line_length + x * 4;
	return (generate_color_by_parsing(\
		(unsigned char *)destination));
}
