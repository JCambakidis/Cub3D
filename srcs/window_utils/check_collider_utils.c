/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:59:53 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/19 17:03:10 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_size_sprite_on_plane(t_sprite sprite, t_vector3 inter_p)
{
	double	d;
	double	d1;

	if (sprite.current_animation->sprite)
	{
		d = sqrt(pow(sprite.location.vx - inter_p.vx, 2) \
			+ pow(sprite.location.vy - inter_p.vy, 2));
		d1 = (double)(sprite.current_animation->animation_width \
			/ sprite.current_animation->animation_height) / 2;
		return (d < d1);
	}
	return (1);
}

void	rectif_impact_point(t_game *game, \
	t_vector3 *inter_p, int wall_index)
{
	float	temp;

	temp = game->map.walls[wall_index].d * -1;
	if (ft_fabs(inter_p->vy - temp) <= 0.0001)
	{
		if (game->player.location.vy < inter_p->vy)
			inter_p->vy = temp;
		else
			inter_p->vy = temp - 1;
	}
	else if (ft_fabs(inter_p->vx - temp) <= 0.0001)
	{
		if (game->player.location.vx < inter_p->vx)
			inter_p->vx = temp;
		else
			inter_p->vx = temp - 1;
	}
}

t_color	select_color(t_sprite_display sprite_display, \
	t_color (*get_pixel_texture)(t_image*, t_vector3), \
		t_vector3 inter_p)
{
	if (sprite_display.path)
		return (get_pixel_texture(sprite_display.texture, inter_p));
	else
		return (sprite_display.color);
}

t_vector3	mk_vect_coll(t_vector3 player_location, \
	t_vector3 pixel_vector, float d)
{
	t_vector3	inter_p;

	inter_p.vx = player_location.vx + pixel_vector.vx * d;
	inter_p.vy = player_location.vy + pixel_vector.vy * d;
	inter_p.vz = player_location.vz + pixel_vector.vz * d;
	return (inter_p);
}

float	mk_rcast_per_vect(t_wall plane, t_vector3 vector)
{
	return (plane.a * vector.vx + plane.b * vector.vy + plane.c * vector.vz);
}
