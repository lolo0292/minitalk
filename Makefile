# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:44:05 by lleichtn          #+#    #+#              #
#    Updated: 2025/03/28 14:29:23 by lleichtn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAME_SERVER = server
# NAME_CLIENT = client

# SRC_SERVER = server.c utils.c
# SRC_CLIENT = client.c utils.c

# OBJ_SERVER = $(SRC_SERVER:.c=.o)
# OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -I.
# LIBFT_DIR = libft
# PRINTF_DIR = ft_printf
# LIBFT = $(LIBFT_DIR)/libft.a
# PRINTF = $(PRINTF_DIR)/libftprintf.a

# all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

# $(NAME_SERVER): $(OBJ_SERVER)
# 	$(CC) $(CFLAGS) $(OBJ_SERVER) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

# $(NAME_CLIENT): $(OBJ_CLIENT) 
# 	$(CC) $(CFLAGS) $(OBJ_CLIENT) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

# clean:
# 	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(PRINTF_DIR)

# fclean: clean
# 	rm -f $(NAME_SERVER) $(NAME_CLIENT)
# 	make fclean -C $(LIBFT_DIR)
# 	make fclean -C $(PRINTF_DIR)
	
# re: fclean all

# .PHONY: all clean fclean re

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# ==== RÈGLES PRINCIPALES ====

all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

# ==== RÈGLES POUR CONSTRUIRE LES LIBRAIRIES ====

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# ==== CLEAN ====

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
