/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:29:14 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/22 00:57:10 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/structs.h"

int ft_one_philo(t_philos *philo)
{
    ft_usleep(1);
    if (philo->num_philos == 1)
    {
        thread_printf(philo, "has taken a fork");
        ft_usleep(philo->time_die);
        thread_printf(philo, "died");
        pthread_mutex_lock(philo->table->deadtex);
        *philo->dead = 1;
        pthread_mutex_unlock(philo->table->deadtex);
        return (0);
    }
    return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_philos(t_philos *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].num_philos)
	{
		printf("philo: %zi\n", i + 1);
		printf(YELLOW"philo->num_philos:"GREEN"[% 8zi]\n", philo[i].num_philos);
		printf(YELLOW"philo->time-die:"GREEN"  [% 8zi]\n", philo[i].time_die);
		printf(YELLOW"philo->time-eat:"GREEN"  [% 8zi]\n", philo[i].time_eat);
		printf(YELLOW"philo->time-sleep:"GREEN"[% 8zi]\n", philo[i].time_sleep);
		printf(YELLOW"philo->sleep:"GREEN"[% 8i]\n", philo[i].sleep);
		printf(YELLOW"philo->eat:"GREEN"[% 8i]\n", philo[i].eaten);
		printf(YELLOW"philo->dead:"GREEN"[% 8i]\n", *philo[i].dead);
		printf("\n"DEFAULT);
		i++;
	}
	printf("\n");
}

void	thread_printf(t_philos *philo, char	*msg)
{
	pthread_mutex_lock(&philo->table->mutex);
	pthread_mutex_lock(philo->table->deadtex);
	if (!*philo->dead)
	{
		printf(WHITE"%4zi "DEFAULT, get_current_time() - philo->table->time);
		if (ft_strcmp(msg, "has taken a fork") == 0)
			printf(BOLD"%i "GREEN"%s %8s\n"DEFAULT, philo->id, msg, "🍽️");
		else if (ft_strcmp(msg, "is eating") == 0)
			printf(BOLD"%i "BLUE"%12s %9s\n"DEFAULT, philo->id, msg, "🥘");
		else if (ft_strcmp(msg, "is sleeping") == 0)
			printf(BOLD"%i "GRAY"%13s %8s\n"DEFAULT, philo->id, msg, "💤");
		else if (ft_strcmp(msg, "is thinking") == 0)
			printf(BOLD"%i "MAGENTA"%13s %8s\n"DEFAULT, philo->id, msg, "🤔");
		else if (ft_strcmp(msg, "died") == 0)
			printf(RED"%i %9s %14s\n"DEFAULT, philo->id, msg, "☠️");
	}
	pthread_mutex_unlock(philo->table->deadtex);
	pthread_mutex_unlock(&philo->table->mutex);
}
