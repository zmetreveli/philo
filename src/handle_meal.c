/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:16:43 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/20 22:02:54 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../includes/structs.h"
# include "colors.h"

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