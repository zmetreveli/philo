/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:07:15 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/25 15:51:12 by zmetreve         ###   ########.fr       */
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

int main(int ac, char **av)
{
    t_table    table;
    t_philos    philos[MAX_PHILOS];

    if (check_args(ac, av))
        return (1);
    prepare_table(philos, &table, av);
    init_philos(&table, philos, av);
    start_meal(&table, philos, av);
    end_meal(&table, philos, av);
    return (0);
}
