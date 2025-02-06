# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:44:05 by lleichtn          #+#    #+#              #
#    Updated: 2025/02/06 13:52:41 by lleichtn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) 
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re


# LIBFT = libft/libft.a

# CC = cc
# CCFLAGS = cc -Wall -Werror -Wextra

# SERVER = server
# CLIENT = client
# SRCS_SERVER = server.c
# SRCS_CLIENT = client.c

# OBJS_SERVER = $(SRCS_SERVER:.c=.o)
# OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)



# all: $(SERVER) $(CLIENT)

# $(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
# 		${CCFLAGS} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
# 		${CCFLAGS} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

# $(LIBFT):
# 		${MAKE} -C ./libft

# clean:	
# 		$(MAKE) clean -C ./libft
# 		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} 

# fclean:	clean
# 		$(MAKE) fclean -C ./libft
# 		rm -rf $(SERVER) $(CLIENT)

# re:	fclean all
