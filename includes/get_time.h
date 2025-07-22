/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:14:19 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/22 02:37:57 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIME_H
#define GET_TIME_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../includes/colors.h"
# include "../includes/structs.h"

int ft_usleep(size_t milliseconds);
size_t  get_current_time(void);

#endif