# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 10:26:26 by luozimek          #+#    #+#              #
#    Updated: 2023/06/13 14:16:23 by luozimek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### COLORS ####################
DEF = \033[0m
UP = \033[A
RETURN = \033[K
PURPLE = \033[38;5;225m
GREEN  = \033[38;5;118m
YELLOW = \033[38;5;226m
BLUE = \033[38;5;117m
_SUCCESS    =   [$(GREEN)SUCCESS$(DEF)]
_INFO       =   [$(YELLOW)INFO$(DEF)]

NAME_C = client
NAME_S = server
NAME_Cbonus = client_bonus
NAME_Sbonus = server_bonus

SRC_C = client.c extra_func.c
SRC_S = server.c extra_func.c
SRC_Cbonus = client_bonus.c extra_func_bonus.c
SRC_Sbonus = server_bonus.c extra_func_bonus.c

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

#################### COMPILER ####################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

################## DEBUGGER ######################
ifeq ($(DEBUG), 1)
    D_FLAG  =   -g
endif

ifeq ($(SANITIZE), 1)
    D_FLAG  =   -fsanitize=leak -g
endif

#################### RULES ####################
all: $(NAME_C) $(NAME_S)

$(NAME): all

$(NAME_S): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC_S) $(LIBFT) -o $(NAME_S)
	@ printf "$(_SUCCESS) server ready.\n"

$(NAME_C): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(NAME_C)
	@ printf "$(_SUCCESS) client ready.\n"

bonus: $(NAME_Cbonus) $(NAME_Sbonus)

$(NAME_Sbonus): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC_Sbonus) $(LIBFT) -o $(NAME_Sbonus)
	@ printf "$(_SUCCESS) server bonus ready.\n"

$(NAME_Cbonus): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC_Cbonus) $(LIBFT) -o $(NAME_Cbonus)
	@ printf "$(_SUCCESS) client bonus ready.\n"
	
$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	@ $(MAKE) -C $(LIBFT_DIR) clean
	@ $(RM) $(NAME_C) $(NAME_S)
	@ printf "$(_INFO) client removed.\n"
	@ printf "$(_INFO) server removed.\n"

fclean:
	@ $(MAKE) -C $(LIBFT_DIR) fclean
	@ $(RM) $(NAME_C) $(NAME_Cbonus) $(NAME_S) $(NAME_Sbonus)
	@ printf "$(_INFO) all client removed.\n"
	@ printf "$(_INFO) all server removed.\n"

re: fclean all

.PHONY: all clean fclean re

