/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:43:42 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:36 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_fmin(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_fabs(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

t_wall	create_wall(float a, float b, float c, float d)
{
	t_wall	wall;

	wall.a = a;
	wall.b = b;
	wall.c = c;
	wall.d = d;
	return (wall);
}

void	ft_dot_vector(t_wall *wall, t_vector3 normal, t_vector3 location)
{
	wall->a = -normal.vx;
	wall->b = -normal.vy;
	wall->c = 0;
	wall->d = -(wall->a * location.vx + wall->b * location.vy);
}
