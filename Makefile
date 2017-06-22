# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/06/22 15:51:08 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mehSh
CC = gcc
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o mehSh_debug
LEAKCHECKFLAGS = -g -o mehSh_leakcheck
OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./libft/
INCDIR = ./include/

SRCF = builtin_cd.c \
		builtin_clear.c \
		builtin_author.c \
		builtin_echo.c \
		builtin_env.c \
		builtin_exit.c \
		builtin_pwd.c \
		builtin_setenv.c \
		builtin_unsetenv.c \
		helpers_env.c \
		helpers_env_b.c \
		helpers_parse.c \
		helpers_setup.c \
		minishell.c \
		minishell_error.c \
		minishell_exec.c \
		minishell_parse_args.c \
		minishell_parse_commands.c \
		minishell_path_search.c \
		minishell_prompt.c \
		minishell_var_expansion.c \
		signal_catcher.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

.PHONY: all, clean, fclean, re

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT)
	@echo "Compiling mehSh"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) -o $@
	@echo "mehSh: SUCCESS!"

$(LIBFT):
	@make -C $(LIBDIR) all

clean:
	@echo "Cleaning mehSh"
	@rm -rf $(OBJDIR)
	@rm -rf minishell_debug
	@rm -rf minishell_debug.dSYM
	@rm -rf minishell_leakcheck
	@rm -rf minishell_leakcheck.dSYM
	@make -C $(LIBDIR) clean

fclean: clean
	@echo "FCleaning mehSh"
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

debug: $(LIBFT)
	@echo "Compiling mehSh with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT)
	@echo "Compiling mehSh for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)
