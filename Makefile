# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 15:28:00 by chenlee           #+#    #+#              #
#    Updated: 2022/07/18 14:26:52 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

MAIN			= ft_printf.c

MNDT			=	printf_char.c				\
					printf_hex.c				\
					printf_number.c				\
					printf_percent.c			\
					printf_pointer.c			\
					printf_string.c				\
					printf_unsigned.c			\
					utils_1.c					\
					utils_2.c					\
					utils_3.c					\
					ft_print_specifier.c		\
					ft_initiate_reset_flag.c

LIBFT			= libft
LIBFT_OBJS		= ./libft/objects/*.o

OBJS			= $(addprefix $(OBJS_DIR), $(MAIN:.c=.o) $(notdir $(MNDT:.c=.o)))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
OBJS_DIR		= objects/

SRCE_DIR		=	printer	\
				libft

vpath %.c $(SRCE_DIR)

$(OBJS_DIR)%.o: %.c
				@mkdir -p $(OBJS_DIR)
				@echo "Compiling: $<"
				@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)

test:			all main.c
				gcc -L. main.c -lftprintf -o test && ./test

all:			$(NAME)

bonus:			$(NAME)

clean:
				@rm -rf $(OBJS_DIR)
				@echo "Remove: $(OBJS_DIR)"

fclean:			clean
				@rm -rf $(NAME)
				@echo "Remove: $(NAME)"

re:				fclean all
