/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 02:34:55 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/22 02:38:54 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAITER_H
#define WAITER_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../includes/colors.h"
# include "../includes/structs.h"

int philosophers_state(t_philos *philo);
int philosopher_dead(t_philos *philo);
int philo_dead(t_philos *philo);
int check_eaten(t_philos *philo);
void    *waiter(void *arg);

#endif