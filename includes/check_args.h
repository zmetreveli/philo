/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:28:28 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/19 14:34:26 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS
# define CHECK_ARGS

size_t  ft_strlen(char *str);
int	ft_whitespace(char c);
int ft_isnum(char *str);
int ft_atoi(char *str);
int check_args(int ac, char **av);

#endif