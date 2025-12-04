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





# NAME        = push_swap

# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror
# DEPFLAGS    = -MMD -MP

# SRC_DIR     = mandatory
# OBJ_DIR     = .objs
# INC_DIR     = includes

# INCLUDES    = -I$(INC_DIR)

# #Wildcard Interdit a la norme mettre les sources manuellement
# SRCS        = $(shell find $(SRC_DIR) -name '*.c')
# OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# DEPS        = $(OBJS:.o=.d)

# RED         = \033[0;31m
# GREEN       = \033[0;32m
# YELLOW      = \033[0;33m
# CYAN        = \033[0;36m
# RESET       = \033[0m

# PROGRESS_BAR_WIDTH = 50
# TOTAL_FILES = $(words $(OBJS))
# CURRENT_FILE = 0

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@echo ""
# 	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
# 	@echo "$(GREEN)✓ $(NAME) created$(RESET)"

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
# 	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
# 	@$(eval FILLED=$(shell echo $$(($(CURRENT_FILE)*$(PROGRESS_BAR_WIDTH)/$(TOTAL_FILES)))))
# 	@printf "$(CYAN)[$(RESET)"
# 	@printf "$(GREEN)%*s" $(FILLED) | tr ' ' '='
# 	@printf "%*s" $$(($(PROGRESS_BAR_WIDTH)-$(FILLED))) | tr ' ' '-'
# 	@printf "$(CYAN)]$(RESET) $(YELLOW)%3d%%$(RESET) Compiling: $(notdir $<)   \r" $(PERCENT)
# 	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

# -include $(DEPS)

# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@echo "$(RED)✓ Objects cleaned$(RESET)"

# fclean: clean
# 	@rm -f $(NAME)
# 	@echo "$(RED)✓ Full clean done$(RESET)"

# re: fclean all

# .PHONY: all clean fclean re