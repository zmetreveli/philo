/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:43:08 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/24 21:45:16 by zmetreve         ###   ########.fr       */
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

void    *routine(void *arg)
{
    t_philos *philo;

    philo = (t_philos*)arg;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    if (ft_one_philo(philo))
        return (arg);
    while (!philosophers_state(philo))
    {
        gluttony(philo);
        rivotril(philo);
        sophos(philo);
    }
    return (arg);
}

void    gluttony(t_philos *philo)
{
    pthread_mutex_t *own_fork;
    pthread_mutex_t *next_fork;

    own_fork = &philo->table->forks[(philo->id - 1) % philo->num_philos];
    next_fork = &philo->table->forks[(philo->id) % philo->num_philos];
    if (philo->id % 2 == 0)
    {
        next_fork = own_fork;
        own_fork = &philo->table->forks[(philo->id) % philo->num_philos];
    }
    pthread_mutex_lock(own_fork);
    thread_printf(philo, "has taken a fork");
    pthread_mutex_lock(next_fork);
    thread_printf(philo, "has taken a fork");
    thread_printf(philo, "is eating");
    pthread_mutex_lock(philo->mealtex);
    philo->last_meal = get_current_time();
    pthread_mutex_lock(philo->table->eatentex);
    philo->eaten++;
    pthread_mutex_unlock(philo->table->eatentex);
    pthread_mutex_unlock(philo->mealtex);
    ft_usleep(philo->time_eat);
    pthread_mutex_unlock(own_fork);
    pthread_mutex_unlock(next_fork);
}

void    rivotril(t_philos *philo)
{
    thread_printf(philo, "is sleeping");
    ft_usleep(philo->time_sleep);
}

void    sophos(t_philos *philo)
{
    thread_printf(philo, "is thinking");
}
