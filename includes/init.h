/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:58:33 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/21 01:05:52 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
#define INIT_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../includes/colors.h"
# include "../includes/structs.h"

void	philos_input_data(t_philos *philos, char **av);
void	init_philos(t_table *table, t_philos *philos, char **av);
void	prepare_table(t_philos *philos, t_table *table, char **av);

#endif