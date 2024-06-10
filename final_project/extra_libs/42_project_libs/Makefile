# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:22:08 by mmoser            #+#    #+#              #
#    Updated: 2024/06/06 19:58:48 by ayermeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g 
RM			:= rm -rf

SRC_DIR		:= src
BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
LIBFT_DIR	:= libft
PF_DIR		:= ft_printf
GNL_DIR		:= get_next_line
# ---------------------------------------------------------------------------- #
LIBFT_SRCS	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			   ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstiter.c \
			   ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstsize.c
PF_SRCS		:= ft_printf.c ft_putfr_len.c
GNL_SRCS	:= get_next_line.c get_next_line_utils.c
# ---------------------------------------------------------------------------- #
LIBFT_SRCS	:= $(LIBFT_SRCS:%=$(SRC_DIR)/$(LIBFT_DIR)/%)
PF_SRCS		:= $(PF_SRCS:%=$(SRC_DIR)/$(PF_DIR)/%)
GNL_SRCS	:= $(GNL_SRCS:%=$(SRC_DIR)/$(GNL_DIR)/%)
# ---------------------------------------------------------------------------- #
LIBFT_OBJS	:= $(LIBFT_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
PF_OBJS		:= $(PF_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
GNL_OBJS	:= $(GNL_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PF_OBJS) $(GNL_OBJS)
	@printf "\n"
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
