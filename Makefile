# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 13:38:36 by lnambaji          #+#    #+#              #
#    Updated: 2023/11/23 13:08:45 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g -fsanitize=address

SOURCES = srcs
OBJECTS = objs
INCLUDES = inc

PUSH_SWAPSRCS = srcs/ft_atoi.c srcs/ft_printf.c \
				srcs/ft_substr.c \
				srcs/ft_putchar_fd.c \
				srcs/ft_putendl_fd.c \
				srcs/ft_itoa.c srcs/ft_putnbr_fd.c \
				srcs/hexchars.c \
				srcs/ft_lstadd_back.c \
				srcs/push_swap.c \
				srcs/ft_split.c \
				srcs/putchars.c \
				srcs/sort.c srcs/operations.c srcs/utils.c srcs/utils2.c

OBJS = $(PUSH_SWAPSRCS:.c=.o)

EXECUTABLE = push_swap
BINDIR = bin
BIN = $(BINDIR)/$(EXECUTABLE)

RED = \033[0;31m
DEFAULT = \033[0m
GREEN = \033[0;32m
CYAN = \033[0;36m

all: $(BIN)
	@echo "$(GREEN)Successfully built push_swap!$(DEFAULT)"

$(BIN): $(OBJS)
	@ mkdir -p $(BINDIR)
	@ echo "Linking $(BIN) from $(OBJS)"
	@ $(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

$(OBJECTS)/%.o: $(SOURCES)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaned$(DEFAULT)"
	@rm -f $(OBJS) $(BIN)

fclean: clean

re: fclean all
