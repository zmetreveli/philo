/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:07:31 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/19 15:25:26 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_time.h"

int ft_usleep(size_t milliseconds)
{
    size_t  start;

    start = get_current_time();
    while (get_current_time() - start < milliseconds)
    {
        usleep(100);
    }
    return (0);
}

size_t  get_current_time(void)
{
    struct  timeval time;

    if (gettimeofday(&time, NULL) == -1)
        write (2, "gettimeofday() error\n" 22);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
