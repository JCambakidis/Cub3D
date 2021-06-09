/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:28:13 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:45 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	tablen(int n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = (size_t)n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		j *= -1;
		i++;
	}
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		j;
	char		*tab;

	i = tablen(n);
	j = (size_t)n;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i--] = '\0';
	if (n == 0)
		tab[0] = '0';
	else if (n < 0)
	{
		tab[0] = '-';
		j *= -1;
	}
	while (j > 0)
	{
		tab[i--] = j % 10 + '0';
		j /= 10;
	}
	return (tab);
}

int	random_in_range(int lower, int upper)
{
	int	num;

	num = (rand() % (upper - lower + 1)) + lower;
	return (num);
}

int	compare_vector_vector(t_vector3 v1, t_vector3 v2)
{
	return ((v1.vx - v2.vx) + (v1.vy - v2.vy));
}
