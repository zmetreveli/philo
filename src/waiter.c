/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:16:50 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/22 01:57:45 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int philosophers_state(t_philos *philo)
{
    pthread_mutex_lock(philo->table->deadtex);
    if (*philo->dead)
        return (pthread_mutex_lock(philo->table->deadtex), 1);
    pthread_mutex_unlock(philo->table->deadtex);
    return (0);
}

int philosopher_dead(t_philos *philo)
{
    pthread_mutex_lock(philo->mealtex);
    if (get_current_time() - philo->last_meal > philo->time_die)
        return (pthread_mutex_unlock(philo->mealtex), 1);
    pthread_mutex_unlock(philo->mealtex);
    return (0);
}

int philo_dead(t_philos *philo)
{
    size_t  i;

    i = 0;
    while (i < philo[0].num_philos)
    {
        if (philosophers_dead(&philo[i]))
        {
            pthread_mutex_lock(philo->table->deadtex);
            if (!*philo->dead)
            {
                pthread_mutex_unlock(philo->table->deadtex);
                thread_printf(philo, "dead");
                pthread_mutex_lock(philo->table->deadtex);
                *philo->dead = 1;
                pthread_mutex_unlock(philo->table->deadtex);
            }
            return (1);
        }
        i++;
    }
    return (0);
}