/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:39:45 by jcambaki          #+#    #+#             */
/*   Updated: 2021/04/21 19:05:27 by jcambaki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_float_to_str(float val, int precision)
{
	char	*part_one;
	char	*part_two;
	int		i;

	i = -1;
	part_one = ft_append_strs(ft_itoa((int)val), ".", TRUE, FALSE);
	val -= (int)val;
	val *= 10;
	part_two = NULL;
	while (++i < precision)
	{
		part_two = ft_append_strs(part_two, ft_itoa((int)val), TRUE, TRUE);
		val -= (int)val;
		val *= 10;
	}
	return (ft_append_strs(part_one, part_two, TRUE, TRUE));
}

void	stop_sounds(void)
{
	if (SYSCALL)
		system("killall afplay");
}

void	*system_call(void *param)
{
	char					*str_tmp;
	char					*append_tmp;
	t_pthread_param_sounds	*tmp;

	tmp = param;
	str_tmp = ft_float_to_str(tmp->volume, 2);
	append_tmp = ft_append_strs(\
		"afplay ./srcs/sounds/", tmp->path, FALSE, FALSE);
	append_tmp = ft_append_strs(append_tmp, " -v ", TRUE, FALSE);
	append_tmp = ft_append_strs(append_tmp, str_tmp, TRUE, TRUE);
	append_tmp = ft_append_strs(append_tmp, " &", TRUE, FALSE);
	if (SYSCALL)
		system(append_tmp);
	ft_fullfree(append_tmp);
	pthread_exit(tmp->thread);
	return (0);
}

void	play_sound(char *sound_path, float volume)
{
	t_pthread_param_sounds	sys;

	sys.path = sound_path;
	sys.volume = volume;
	pthread_create(&sys.thread, NULL, &system_call, &sys);
	pthread_join(sys.thread, NULL);
}

void	playmusic(t_game *game)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (t.tv_sec - game->music_time > SOUND_TIME)
	{
		game->music_time = t.tv_sec;
		play_sound("ambient.wav", 0.7);
	}
}
