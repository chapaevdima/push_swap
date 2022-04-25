# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:58:27 by anatasha          #+#    #+#              #
#    Updated: 2022/03/09 21:27:08 by anatasha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

B_NAME		=	checker

SRCS		=	push_swap.c push_swap_utils_1.c\
				push_swap_utils_2.c sort_1.c\
				push_swap_utils_print_1.c\
				push_swap_utils_print_2.c\
				sort_2.c sort_3.c sort_4.c

B_SRCS		=	checker_bonus.c push_swap_utils_1.c\
				push_swap_utils_2.c sort_1.c\
				push_swap_utils_print_1.c\
				push_swap_utils_print_2.c\
				sort_2.c sort_3.c sort_4.c\
				get_next_line_bonus.c get_next_line_utils_bonus.c

HEADER		=	push_swap.h

B_HEAD		=	push_swap_bonus.h

OBJ			=	$(patsubst %.c, %.o, $(SRCS))
B_OBJ		=	$(patsubst %.c, %.o, $(B_SRCS))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

all			:	$(NAME)

%.o			:	%.c $(HEADER) $(B_HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJ) $(HEADER)
			$(CC) $(OBJ) -o $(NAME)

clean		:
			@rm -f $(OBJ) $(B_OBJ)

fclean		:	clean
			@$(RM) $(NAME) $(B_NAME)

re			:	fclean all

bonus		:	$(B_NAME)

$(B_NAME)	:	$(B_OBJ) $(B_HEAD)
			$(CC) $(B_OBJ) -o $(B_NAME)