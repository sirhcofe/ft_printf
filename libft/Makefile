# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:51:32 by chenlee           #+#    #+#              #
#    Updated: 2022/05/12 16:51:32 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	ft_atoi.c		\
						ft_bzero.c		\
						ft_calloc.c		\
						ft_isdigit.c	\
						ft_itoa.c		\
						ft_memcpy.c		\
						ft_memmove.c	\
						ft_putstr_fd.c	\
						ft_strchr.c		\
						ft_strdup.c		\
						ft_strjoin.c	\
						ft_strlcpy.c	\
						ft_strlen.c		\
						ft_substr.c

NAME					= libft.a

OBJS_DIR				= objects/

OBJS					= $(SRCS:.c=.o)
OBJECTS_PREFIXED		= $(addprefix $(OBJS_DIR), $(OBJS))

CC						= gcc
CFLAGS					= -Wall -Wextra -Werror

$(OBJS_DIR)%.o:		%.c 
					@mkdir -p objects
					@echo "Compiling: $<"
					@gcc $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJECTS_PREFIXED)
					@echo "libft"
					@ar rc $(NAME) $(OBJECTS_PREFIXED)

all:				$(NAME)

clean:
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@rm -f $(NAME)

re:					fclean all