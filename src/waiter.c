/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:16:50 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/26 18:00:36 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../includes/colors.h"
# include "../includes/structs.h"
#include "../includes/check_args.h"
#include "../includes/get_time.h"
#include "../includes/handle_meal.h"
#include "../includes/init.h"
#include "../includes/philo.h"
#include "../includes/routine.h"
#include "../includes/utils.h"
#include "../includes/waiter.h"

int	philosophers_state(t_philos *philo)
{
	pthread_mutex_lock(philo->table->deadtex);
	if (*philo->dead)
	{
		pthread_mutex_unlock(philo->table->deadtex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->deadtex);
	return (0);
}

int	philosopher_dead(t_philos *philo)
{
	size_t	now;

	pthread_mutex_lock(philo->mealtex);
	now = get_current_time();
	if (now - philo->last_meal > philo->time_die)
	{
		pthread_mutex_unlock(philo->mealtex);
		return (1);
	}
	pthread_mutex_unlock(philo->mealtex);
	return (0);
}

int	philo_dead(t_philos *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].num_philos)
	{
		if (philosopher_dead(&philo[i]))
		{
			pthread_mutex_lock(philo->table->deadtex);
			if (!*philo->dead)
			{
				thread_printf(&philo[i], "died");
				*philo->dead = 1;
			}
			pthread_mutex_unlock(philo->table->deadtex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_eaten(t_philos *philo)
{
	size_t	i;
	int		total;
	size_t	num;

	i = 0;
	total = 0;
	num = philo[0].num_philos;
	while (i < num)
	{
		pthread_mutex_lock(philo->table->eatentex);
		if (philo[i].eaten >= philo->table->num_of_meals
			&& philo->table->num_of_meals != -1)
			total++;
		pthread_mutex_unlock(philo->table->eatentex);
		i++;
	}
	if (total == (int)num)
	{
		pthread_mutex_lock(philo->table->deadtex);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->table->deadtex);
		return (1);
	}
	return (0);
}

void	*waiter(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
	{
		if (philo_dead(philos) || check_eaten(philos))
			break ;
		usleep(1000); // evitar 100% CPU
	}
	return (arg);
}