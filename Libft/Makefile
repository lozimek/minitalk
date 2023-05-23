# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 18:03:08 by luozimek          #+#    #+#              #
#    Updated: 2023/05/23 04:56:34 by luozimek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
PURPLE = \033[38;5;225m
RETURN = \033[K
UP = \033[A
DEF = \033[0m


LIBFT_PATH = ./libft/
SRCS_LIBFT = ${addprefix ${LIBFT_PATH}, ft_bzero.c \
										ft_isalnum.c \
										ft_isalpha.c \
										ft_isascii.c \
										ft_isdigit.c \
										ft_isprint.c \
										ft_memcpy.c \
										ft_memset.c \
										ft_strlen.c \
										ft_memmove.c \
										ft_strlcpy.c \
										ft_strlcat.c \
										ft_toupper.c \
										ft_tolower.c \
										ft_strchr.c \
										ft_strrchr.c \
										ft_strncmp.c \
										ft_memchr.c \
										ft_memcmp.c \
										ft_strnstr.c \
										ft_atoi.c \
										ft_calloc.c \
										ft_strdup.c \
										ft_substr.c \
										ft_strjoin.c \
										ft_strtrim.c \
										ft_split.c \
										ft_itoa.c \
										ft_strmapi.c \
										ft_striteri.c \
										ft_putchar_fd.c \
										ft_putstr_fd.c \
										ft_putendl_fd.c \
										ft_putnbr_fd.c \
										ft_lstnew.c \
										ft_lstadd_front.c \
										ft_lstsize.c \
										ft_lstlast.c \
										ft_lstadd_back.c \
										ft_lstdelone.c \
										ft_lstclear.c}

FT_PRINTF_PATH = ./ft_printf/
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_PATH), ft_parscheck.c \
												ft_my_fonctions.c \
												ft_printf.c)

OBJS = ${SRCS_LIBFT:.c=.o} ${SRCS_FT_PRINTF:.c=.o} ${SRCS_GNL:.c=.o} 

NAME = libft.a
all: ${NAME}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	@${CC} ${CFLAGS} -c -I ./inc $< -o $@
	@printf "${PURPLE}Compiling $<${RETURN}\n${DEF}"
	@printf "${UP}"

${NAME}: ${OBJS}
	@ar crs ${NAME} ${OBJS}
	@echo "\n---------------------------------------------"

clean:
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean:
	@${MAKE} clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re