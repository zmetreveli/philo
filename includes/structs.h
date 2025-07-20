/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:50:51 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/20 21:13:23 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <pthread.h>
#include <sys/time.h>

#define MAX_PHILOS 200

typedef struct  s_philos
{
    int id;
    pthread_t   thread;
    size_t  num_philos;
    pthread_mutex_t *mealtex;
    pthread_mutex_t *eatentex;
    size_t  time_die;
    size_t  time_eat;
    size_t  time_sleep;
    size_t  last_meal;
    int sleep;
    int eaten;
    int *dead;
    struct s_table *table;
}   t_philos;

typedef struct s_table
{
    pthread_t    table;
    t_philos    *philos;
    pthread_mutex_t mutex;
    pthread_mutex_t *deadtex;
    pthread_mutex_t *eatentex;
    pthread_mutex_t *forks;
    int num_of_meals;
    unsigned long time;
    int dead_flag;
}   t_table;

#endif
