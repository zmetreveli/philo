/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:07:15 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:41 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
    t_table    table;
    t_philos    philos[MAX_PHILOS];

    if (check_args(ac, **av))
        return (1);
    prepar_table(philos, &table, **av);
    prepar_philos(&table, philos, **av);
    start_meal(&table, philos, **av);
    end_meal(&table, philos, **av);
    return (0);
}
