# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:34:43 by mballet           #+#    #+#              #
#    Updated: 2021/08/12 15:47:33 by mballet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXE				= libft.a

SRCS_FILES		= ft_atoi.c\
				  ft_bzero.c\
				  ft_memcpy.c\
				  ft_memccpy.c\
				  ft_memmove.c\
				  ft_memchr.c\
				  ft_memcmp.c\
				  ft_memset.c\
				  ft_strlen.c\
				  ft_isalpha.c\
				  ft_isdigit.c\
				  ft_isalnum.c\
				  ft_isascii.c\
				  is_strnum.c\
				  ft_isprint.c\
				  ft_toupper.c\
				  ft_tolower.c\
				  ft_strchr.c\
				  ft_strrchr.c\
				  ft_strncmp.c\
				  ft_strlcpy.c\
				  ft_strlcat.c\
				  ft_strnstr.c\
				  ft_calloc.c\
				  ft_strdup.c\
				  ft_substr.c\
				  ft_strjoin.c\
				  ft_strtrim.c\
				  ft_putchar_fd.c\
				  ft_putstr_fd.c\
				  ft_putendl_fd.c\
				  ft_putnbr_fd.c\
				  ft_itoa.c\
				  ft_split.c\
				  ft_strmapi.c\
				  ft_putnbr_base.c\
				  ft_realloc.c\
				  ft_lstnew.c\
				  ft_lstadd_front.c\
				  ft_lstsize.c\
				  ft_lstlast.c\
				  ft_lstadd_back.c\
				  ft_lstdelone.c\
				  ft_lstclear.c\
				  ft_lstiter.c\
				  ft_lstmap.c\
				  printlst.c\
				  lst_cpy.c\

OBJS_DIR		= .objs

SRCS_DIR		= srcs/libft

OBJS			= $(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))

SRCS			= $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

PATH_OBJS		= list

HEADERS			= include/libft.h

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra -Iinclude/

SANFLAGS		= -g3 -fsanitize=address

RM				= rm -f

green			= \033[32m

yellow			= \033[33m

normal			= \033[0m

all				: $(EXE)

$(EXE)			: $(OBJS)
					ar rcs $@ $^
					@echo "$(yellow)Libft $(normal)is $(green)ready$(normal)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
					mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))
					$(CC) $(CFLAGS) -o $@ -c $<

clean			:
					$(RM) $(OBJS)

fclean			: clean
					$(RM) $(EXE)

re				: fclean all

.PHONY			: clean fclean all re
