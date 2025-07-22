/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_meal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:38:02 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/22 02:38:05 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MEAL_H
#define HANDLE_MEAL_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../includes/colors.h"
# include "../includes/structs.h"

void    start_meal(t_table *table, t_philos *philos, char **av);
void    end_meal(t_table *table, t_philos *philos, char **av);

#endif