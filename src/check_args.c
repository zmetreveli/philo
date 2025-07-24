/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:56:43 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/24 20:54:45 by zmetreve         ###   ########.fr       */
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

size_t  ft_strlen(char *str)
{
    size_t size;

    size = 0;
    if (!str)
        return (-1);
    while (str[size])
        size++;
    return (size);
}

int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int ft_isnum(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (-1);
    while (str)
    {
        if (str[i] < '0' || str[i++] > '9')
        return (1);
    }
    return (0);
}

int ft_atoi(char *str)
{
    int i;
    int neg;
    int num;

    i = 0;
    num = 0;
    neg = 1;
    while (ft_whitespace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - 48);
        i++;
    }
    return (num * neg);
}

int check_args(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return (printf(RED"Usage:\n"GREEN"./philo"" 5 500 600 800\n" DEFAULT));
    if (ft_atoi(av[1]) <= 0 || ft_isnum(av[1]) > MAX_PHILOS)
        return (printf(RED"Invalid number of arguments\n" DEFAULT));
    if (ft_atoi(av[2]) <= 0 || ft_isnum(av[2]))
        return (printf(RED"Invalid time to die\n" DEFAULT));
    if (ft_atoi(av[3]) <= 0 || ft_isnum(av[3]))
       return (printf(RED"invalid time to eat\n" DEFAULT));
    if (ft_atoi(av[4]) <= 0 || ft_isnum(av[4]))
        return (printf(RED"Invalid time to sleep\n" DEFAULT));
    if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_isnum(av[5])))
        return (printf(RED"Invalid eat times\n" DEFAULT));
    return (0);
}
