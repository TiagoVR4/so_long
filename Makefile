# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagovr4 <tiagovr4@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 15:52:15 by tiagovr4          #+#    #+#              #
#    Updated: 2025/04/29 12:25:55 by tiagovr4         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors for output messages
RED = \033[1;31m
GRN = \033[1;32m
YLW = \033[1;33m
BLU = \033[1;34m
MGN = \033[1;35m
CYN = \033[1;36m
D = \033[0m

NAME = so_long

# libft paths and source files
LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# minilibx paths and source files
MINILIBX_PATH = minilibx-linux
MINILIBX_ARC = $(MINILIBX_PATH)/libmlx.a

# source files
SRCS = src/read_map.c \
	   src/validate_map.c \
	   src/render_map.c \
	   src/init_game.c \
	   src/handle_input.c \
	   src/validate_path.c \
	   so_long.c \
	
# object files
OBJS = $(SRCS:.c=.o)

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_PATH) -I$(MINILIBX_PATH)
LIBS = -L$(MINILIBX_PATH) -lmlx -lX11 -lXext -lm -lbsd

# Main rule - build libft.a after dependencies are met
all: deps $(NAME)

# Check and download dependencies if needed
deps: get_libft get_minilibx
	@echo "[$(GRN)Nothing to be done!$(D)]"

# Download libft if not present
get_libft:
	@if [ -d "$(LIBFT_PATH)" ]; then \
		echo "[$(GRN)libft$(D)] folder found 🖔"; \
	else \
		echo "Getting $(YLW)libft$(D)"; \
		git clone git@github.com:TiagoVR4/libft.git; \
		echo "$(GRN)Done downloading libft$(D)"; \
	fi

# Download minilibx if not present
get_minilibx:
	@if [ -d "$(MINILIBX_PATH)" ]; then \
		echo "[$(GRN)minilibx$(D)] folder found 🖔"; \
	else \
		echo "Getting $(YLW)minilibx$(D)"; \
		git clone https://github.com/42paris/minilibx-linux.git; \
		echo "$(GRN)Done downloading minilibx$(D)"; \
	fi
	
# Create the main library archive
$(NAME): $(OBJS) $(LIBFT_ARC) $(MINILIBX_ARC)
	@echo "[$(CYN)Compiling$(D)] $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(LIBFT_PATH)/ft_printf -lftprintf $(LIBS)
	@echo "[$(GRN)Done!$(D)]"

# Generic rule for compiling .c to .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# compile libft
$(LIBFT_ARC):
	@echo "[$(CYN)Compiling$(D)] libft"
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "[$(GRN)libft compiled successfully$(D)]"

# compile minilibx
$(MINILIBX_ARC):
	@echo "[$(CYN)Compiling$(D)] minilibx"
	@$(MAKE) -C $(MINILIBX_PATH)
	@echo "[$(GRN)minilibx compiled successfully$(D)]"

# Clean up object files and the main executable
clean:
	@echo "[$(CYN)Cleaning$(D)]"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MINILIBX_PATH) clean
	@echo "[$(GRN)Cleaned!$(D)]"

fclean: clean
	@echo "[$(CYN)Cleaning$(D)]"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MINILIBX_PATH) fclean
	@echo "[$(GRN)Cleaned!$(D)]"

# Rebuild everything from scratch
re: fclean all
	@echo "[$(CYN)Rebuilding$(D)]"
	@$(MAKE) all
	@echo "[$(GRN)Rebuild complete!$(D)]"

.PHONY: all clean fclean re