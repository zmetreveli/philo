# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 18:59:50 by zmetreve          #+#    #+#              #
#    Updated: 2025/07/24 21:31:52 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS =	src/check_args.c \
		  src/get_time.c \
		  src/handle_meal.c \
		  src/init.c \
		  src/routine.c \
		  src/utils.c \
		  src/waiter.c \
		  src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c includes/check_args.h includes/colors.h includes/get_time.h includes/init.h includes/philo.h includes/routine.h includes/structs.h includes/utils.h includes/waiter.h Makefile
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
