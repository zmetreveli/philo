# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 18:59:50 by zmetreve          #+#    #+#              #
#    Updated: 2025/07/24 21:09:26 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS =	check_args.c \
		  get_time.c \
		  hendle_meal.c \
		  init.c \
		  routine.c \
		  utils.c \
		  waiter.c \
		  main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME)

%.o: %.c Makefile check_args.h colors.h get_time.h init.h philo.h routine.h structs.h utils.h waiter.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
