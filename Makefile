# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 15:07:46 by fboulbes          #+#    #+#              #
#    Updated: 2024/12/25 15:07:47 by fboulbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = -Llib/libft -Llib/ft_printf
LDLIBS = -lft -lftprintf

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIB_DIR = lib

LIBFT_DIR = $(LIB_DIR)/libft
FT_PRINTF_DIR = $(LIB_DIR)/ft_printf

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TARGET = so_long

all: libs $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # Créer les dossiers nécessaires pour les fichiers objets
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)

-include $(OBJ_FILES:.o=.d)

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -MM $(CFLAGS) $< | sed 's|^|$(OBJ_DIR)/|' > $@
