/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:54:15 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/21 00:56:21 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void	philos_input_data(t_philos *philos, char **av)
{
	philos->num_philos = ft_atoi(av[1]);
	philos->mealtex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->eatentex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos->mealtex, NULL);
	pthread_mutex_init(philos->eatentex, NULL);
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->last_meal = get_current_time();
	philos->sleep = 0;
	philos->eaten = 0;
	philos->dead = &philos->table->dead_flag;
}

void	init_philos(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos_input_data(&philos[i], av);
		i++;
	}
}

void	prepare_table(t_philos *philos, t_table *table, char **av)
{
	size_t	i;

	table->philos = philos;
	pthread_mutex_init(&table->mutex, NULL);
	table->deadtex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->deadtex, NULL);
	table->eatentex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->eatentex, NULL);
	i = 0;
	table->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < (size_t)ft_atoi(av[1]))
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	table->dead_flag = 0;
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	else
		table->num_of_meals = -1;
}