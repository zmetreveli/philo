/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:43:08 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/21 23:01:26 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *gluttony(char *arg)
{
    t_philos *philo;

    philo = (t_philos*)arg;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    if (ft_one_philo(philo))
        return (arg);
    while (!philosopers_state(philo))
    {
        gluttony(philo);
        rivotril(philo);
        sophos(philo);
    }
    return (arg);
}

