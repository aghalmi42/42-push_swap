# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 02:11:49 by aghalmi           #+#    #+#              #
#    Updated: 2025/12/04 20:28:05 by aghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include

MAND_DIR = mandatory
INC_DIR = include

SRCS = $(MAND_DIR)/main.c \
       $(MAND_DIR)/parsing.c \
       $(MAND_DIR)/push_operation.c \
       $(MAND_DIR)/reverse_rotate_operation.c \
       $(MAND_DIR)/rotate_operation.c \
       $(MAND_DIR)/setup_stack.c \
       $(MAND_DIR)/sort_algo_simple.c \
       $(MAND_DIR)/swap_operation.c \
       $(MAND_DIR)/turkish_algo_index.c \
       $(MAND_DIR)/turkish_algo.c \
       $(MAND_DIR)/turkish_algo_utils.c \
       $(MAND_DIR)/turkish_algo_utils_2.c \
       $(MAND_DIR)/turkish_algo_utils_3.c \
       $(MAND_DIR)/turkish_algo_utils_4.c \
	   $(MAND_DIR)/turkish_algo_utils_5.c \
       $(MAND_DIR)/push_swap_utils.c \
       $(MAND_DIR)/push_swap_utils_2.c

SRCS_BONUS = $(MAND_DIR)/checker_bonus.c \
             $(MAND_DIR)/operation_bonus.c \
             $(MAND_DIR)/operation_bonus_1.c \
             $(MAND_DIR)/operation_bonus_2.c \
             $(MAND_DIR)/get_next_line.c \
             $(MAND_DIR)/get_next_line_utils.c \
             $(MAND_DIR)/parsing.c \
             $(MAND_DIR)/setup_stack.c \
             $(MAND_DIR)/push_swap_utils.c \
             $(MAND_DIR)/push_swap_utils_2.c \
             $(MAND_DIR)/swap_operation.c \
             $(MAND_DIR)/push_operation.c \
             $(MAND_DIR)/rotate_operation.c \
             $(MAND_DIR)/reverse_rotate_operation.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation de push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)push_swap créé avec succès !$(RESET)"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	@echo "$(GREEN)Compilation du checker...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS)
	@echo "$(GREEN)checker créé avec succès !$(RESET)"

%.o: %.c
	@echo "Compilation de $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(RED)Fichiers objets supprimés !$(RESET)"

fclean: clean
	@echo "$(RED)Suppression des exécutables...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@echo "$(RED)Exécutables supprimés !$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
