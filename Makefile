# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:23:57 by oseivane          #+#    #+#              #
#    Updated: 2023/10/09 15:24:08 by oseivane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER_NAME		=	server

CLIENT_NAME		=	client

SRC		=	server.c client.c utils.c

OBJ		=	$(SRC:.c=.o)

CC = gcc

GCC = gcc -Wall -Wextra -Werror

all : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): server.o utils.o
	$(CC) $(CFLAGS) -o $(SERVER_NAME) server.o utils.o

$(CLIENT_NAME): client.o utils.o
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) client.o utils.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re : fclean all

.PHONY : all clean fclean re 