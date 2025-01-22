# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 18:20:38 by cpoulain          #+#    #+#              #
#    Updated: 2025/01/22 19:03:59 by cpoulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands

RM		:= /usr/bin/rm -f
ECHO	:= /usr/bin/echo

# Dirs

SRC_DIR := src
OBJ_DIR	:= build
BIN_DIR	:= binaries
INC_DIR	:= include

# Flags

CFLAGS	:= -Wall -Wextra -Werror -g3
LFLAGS	:= -pthread

# Files

include Files.mk

OBJS	= $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(FILES)))

# Other

NAME	:= philo

.PHONY: all bonus clean fclean re norminette

all: $(BIN_DIR)/$(NAME)

bonus: all

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)/$(NAME)

re: fclean all

$(BIN_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $^ -I$(INC_DIR) -o $@ $(CFLAGS) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)

norminette:
	@norminette | grep -Ev '^Notice:|OK!$$'					\
	&& $(ECHO) -e "$(TERM_RED)Norminette KO !$(COL_RESET)"	\
	|| $(ECHO) -e "$(TERM_GREEN)Norminette OK !$(COL_RESET)"
	@killall norminette 2>/dev/null || true
