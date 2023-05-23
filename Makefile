# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 05:07:29 by luozimek          #+#    #+#              #
#    Updated: 2023/05/23 05:53:04 by luozimek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### COLORS ####################
DEF = \033[0m
UP = \033[A
RETURN = \033[K
PURPLE = \033[38;5;225m
YELLOW = \033[38;5;226m
BLUE = \033[38;5;117m

NAME = minitalk
SRCS = server.c client.c extra_func.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./Libft/
LIBFT = $(LIBFT_DIR)/libft.a

#################### COMPILER ####################

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifndef DEBUG
	CFLAGS += -fsanitize=address -g
endif

LIBS = $(LIBFT)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${PURPLE}Compiling $<${RETURN}\n${DEF}"
	@printf "${UP}"

#################### RULES ####################
all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "\n${YELLOW}All files compiled successfully\n${DEF}"
	@printf "${BLUE}${NAME} COMPILED ! ✨\n\n${DEF}"
	@echo "---------------------------------------------"


clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

debug:
	@${MAKE} DEBUG=1

re: fclean all

.PHONY: all clean fclean re debug
