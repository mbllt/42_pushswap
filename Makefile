NAME			= push_swap

SRCS_FILES		= operations/swap.c \
				  operations/swap_ab.c \
				  operations/push.c \
				  operations/rotate.c \
				  operations/rotate_ab.c \
				  operations/rev_rotate.c \
				  operations/rev_rotate_ab.c \
				  utils/check_double.c\
				  utils/init_global.c\
				  utils/free_global.c\
				  pushswap.c \

OBJS_DIR		= .objs

SRCS_DIR		= srcs

OBJS			= $(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))

SRCS			= $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

PATH_OBJS		= operations utils

INCLUDE			= include/pushswap.h libft/include/libft.h

CC				= gcc

CFLAGS			= -g -Wall -Werror -Wextra -Iinclude/ 

SANFLAGS		= -g3 -fsanitize=address

LIBFT_FILES		= libft

EXE_LIBFT		= libft/libft.a

RM				= /bin/rm -rf

green			= \033[32m

yellow			= \033[33m

normal			= \033[0m

all				: $(NAME)

$(NAME)			:  $(EXE_LIBFT) $(OBJS)
					$(CC) -o $(NAME) $^ $(EXE_LIBFT)
					@echo "$(yellow)Pushswap is $(green)ready$(normal)"

$(EXE_LIBFT)	:
					$(MAKE) -C$(LIBFT_FILES) -s

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c $(INCLUDE) | $(OBJS_DIR)
					$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR)		:
					mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))

clean			:
					$(RM) $(OBJS)

cleanlibft		:
					make -C libft clean
				
fclean			: clean cleanlibft
					$(RM) $(EXE_LIBFT)
					$(RM) $(NAME)
					$(RM) $(OBJS_DIR)

re				: fclean all

.PHONY			: all clean fclean re