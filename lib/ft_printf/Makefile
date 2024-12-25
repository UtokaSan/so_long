# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 15:29:22 by fboulbes          #+#    #+#              #
#    Updated: 2024/12/25 15:40:51 by fboulbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../include -I../libft/include
AR = ar rc

NAME = libftprintf.a

SRCS_DIR = src
LIBFT_DIR = ../libft

SRCS = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(SRCS_DIR)/*/*.c) $(wildcard $(SRCS_DIR)/*/*/*.c)
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME) # Copier libft.a pour inclure ses fonctions
	$(AR) $(NAME) $(OBJS) # Ajouter les objets spécifiques à ft_printf
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
