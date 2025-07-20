/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:16:43 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/21 00:47:27 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/colors.h"
#include "../includes/structs.h"
#include <pthread.h>

void    start_meal(t_table *table, t_philos *philos, char **av)
{
    size_t i;

    (void)philos;
    (void)av;
    i = 0;
    table->time = get_current_time();
    if (pthread_create(&table->table, NULL, waiter, table->philos) != 0)
        write (2, "TError\n", 7);
    while (i < table->philos->num_philos)
    {
        if (pthread_created(&table->philos[i].thread, NULL, routine, &table->philos[i]) != 0)
            write (2, "TError\n", 7);
            i++;
    }
    i = 0;
    while (i < table->philos->num_philos)
    {
        pthread_join(&table->philos[i].thread, NULL);
        i++;
    }
    pthread_join(table->table, NULL);
}

void    end_meal(t_table *table, t_philos *philos, char **av)
{
    size_t  i;

    i = 0;
    (void)av;
    pthread_mutex_destroy(&table->mutex);
    pthread_mutex_destroy(table->deadtex);
    free(table->deadtex);
    pthread_mutex_destroy(table->eatentex);
    free(table->eatentex);
    while (i < table->philos-num_philos)
    {
        pthread_mutex_destroy(philos[i].mealtex);
        free(philos[i].mealtex);
        pthread_mutex_destroy(philos[i].eatentex);
        free(philos[i].eatentex);
        pthread_mutex_destroy(&table.forks[i]);
        i++;
    }
    free(table->forks);
}