# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebbaill <sebbaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 02:03:59 by sebbaill          #+#    #+#              #
#    Updated: 2021/08/18 20:35:43 by sebbaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR := ./srcs
OBJ_DIR := ./objs

SRCS_PRINTF =ft_printf.c		\
			ft_read_format.c	\
			ft_parse.c			\
			ft_conversion.c 	\
			ft_width.c			\
			ft_precision.c		\
			ft_flags.c			\
			ft_char.c			\
			ft_int.c			\
			ft_uns_int.c 		\
			ft_hexa.c			\
			ft_string.c			\
			ft_options.c		\
			ft_parse_conv.c		\
			ft_pointer.c		\
			ft_printf_tools.c	\
			ft_printf_tools2.c	\
			ft_printf_tools3.c	\

OBJ_PRINTF := $(addprefix $(OBJ_DIR)/,$(SRCS_PRINTF:.c=.o))

#########################################
#										#
#				COLORS					#
#										#
#########################################

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
GREEN_RED = \033[32;41;5m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
TURQ = \033[36m
GREY = \033[37m

UP = \033[A
CUT = \033[K

CURRENT_FILE = 0
NUMBER_OF_FILE = 18
PERCENTAGE = 0

all: $(NAME)

#SOURCEO = $(SOURCEC:%.c=%.o)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	$(eval PERCENTAGE=$(shell echo $(CURRENT_FILE)*100/$(NUMBER_OF_FILE) | bc))
	@echo "${BLUE}compiling $@ [$(PERCENTAGE)%]...${END}"
	@$(CC) $(CFLAGS) -o $@ -c $< -I. -include includes/libftprintf.h
	@printf "$(UP)$(CUT)"

$(NAME): $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo "${GREEN_RED}$(NAME) compiled.${END}"

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ_DIR)
	@echo "${YELLOW}Binary files of ft_printf deleted.${END}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${RED}$(NAME) deleted.${END}"

re: fclean all
