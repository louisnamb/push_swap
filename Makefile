# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 13:38:36 by lnambaji          #+#    #+#              #
#    Updated: 2023/10/30 16:31:22 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g -fsanitize=address

SOURCES = srcs
OBJECTS = objs
INCLUDES = inc

PUSH_SWAPSRCS = srcs/ft_atoi.c srcs/ft_lstadd_front.c srcs/ft_memcmp.c \
                srcs/ft_strchr.c srcs/ft_strrchr.c srcs/ft_bzero.c \
                srcs/ft_lstclear.c srcs/ft_memcpy.c srcs/ft_strdup.c \
                srcs/ft_strtrim.c srcs/ft_calloc.c srcs/ft_lstdelone.c \
                srcs/ft_memmove.c srcs/ft_striteri.c srcs/ft_substr.c \
                srcs/ft_isalnum.c srcs/ft_lstiter.c srcs/ft_memset.c \
                srcs/ft_strjoin.c srcs/ft_tolower.c srcs/ft_isalpha.c \
                srcs/ft_lstlast.c srcs/ft_printf.c srcs/ft_strlcat.c \
                srcs/ft_toupper.c srcs/ft_isascii.c \
                srcs/ft_putchar_fd.c srcs/ft_strlcpy.c srcs/hexchars.c \
                srcs/ft_isdigit.c srcs/ft_putendl_fd.c srcs/ft_strlen.c \
				srcs/push_swap.c srcs/ft_isprint.c srcs/ft_lstnew.c \
				srcs/ft_putnbr_fd.c srcs/ft_strmapi.c srcs/putchars.c \
				srcs/ft_itoa.c srcs/ft_lstsize.c srcs/ft_putstr_fd.c \
				srcs/ft_strncmp.c srcs/ft_lstadd_back.c srcs/ft_memchr.c \
				srcs/ft_split.c srcs/ft_strnstr.c \

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
	@mkdir -p $(BINDIR)
	@echo "Linking $(BIN) from $(OBJS)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE)

$(OBJECTS)/%.o: $(SOURCES)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaned$(DEFAULT)"
	@rm -f $(OBJS) $(BIN)

fclean: clean

re: fclean all
