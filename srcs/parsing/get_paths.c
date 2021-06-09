/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:16:11 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/07 17:45:23 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_path_init(char *str)
{
	int		i;
	int		j;
	t_bool	read;
	t_bool	readed;

	i = -1;
	j = 0;
	read = FALSE;
	readed = FALSE;
	while (str[++i])
	{
		if (is_space(str[i]) && read)
			readed = TRUE;
		if (!is_space(str[i]) && readed)
			return (-1);
		else if (!is_space(str[i]))
		{
			j++;
			if (!read)
				read = TRUE;
		}
	}
	return (j);
}

char 	*get_path(char *str)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = get_path_init(str);
	if (j == -1)
		return (0);
	path = ft_calloc(j + 1, sizeof(char));
	if (!path)
		return (0);
	while (str[i++])
	{
		if (!is_space(str[i]))
			path[j++] = str[i];
	}
	path[j] = 0;
	return (path);
}

int	set_path(char *str, char **dst)
{
	char	*result;

	result = get_path(str);
	if (!result[0])
		return (0);
	ft_putstr_nl(str);
	*dst = ft_strdup(result, FALSE);
	ft_fullfree((void *)result);
	return (1);
}
