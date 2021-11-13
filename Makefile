NAME			:= push_swap

SRCS_DIR		:=	srcs
SRCS_FILES		:=	operations/swap.c \
					operations/swap_ab.c \
					operations/push.c \
					operations/rotate.c \
					operations/rotate_ab.c \
					operations/rev_rotate.c \
					operations/rev_rotate_ab.c \
					utils/check_double.c \
					utils/init_global.c \
					utils/free_global.c \
					utils/clear.c \
					utils/find_big_small.c \
					utils/is_sorted.c \
					utils/add_ope.c \
					utils/check_ope.c \
					utils/print_ope.c \
					pushswap.c \
					sorting.c \
					find_median.c \
					seperate.c \
					sort_six.c \
					sort_a.c \
					sort_b.c \
					sort_a_six.c \
					sort_b_six.c
SRCS			:=	$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

OBJS_DIR		:=	.objs
OBJS			:=	$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))
PATH_OBJS		:=	operations utils


INCLUDES		:=	include/pushswap.h libft/include/libft.h

CC				:=	gcc
CFLAGS			:=	-g -Wall -Werror -Wextra -Iinclude/ 
SANFLAGS		:=	-g3 -fsanitize=address

LIBFT_DIR		:=	libft
LIBS			:=	$(LIBFT_DIR)/libft.a

RM				:=	/bin/rm -rf

green			:=	\033[32m
yellow			:=	\033[33m
normal			:=	\033[0m

all:				$(NAME)

$(NAME):			$(OBJS) libs
							@echo "Linking $@"
							@$(CC) $(OBJS) $(LIBS) -o $(NAME)
							@echo "> $(yellow)Ready$(normal) to execute"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
							@echo "Compiling $<"
							@$(CC) $(CFLAGS) -o $@ -c $<

libs:
							@echo "Making libft"
							@$(MAKE) -s -C $(LIBFT_DIR)

$(OBJS_DIR):
							@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))


clean:
							@echo "Cleaning pushswap"
							@$(RM) $(OBJS)

cleanlibft:
							@echo "Cleaning libft"
							@make -C libft clean -s
				
fclean:				clean cleanlibft
							@$(RM) $(NAME_LIBFT)
							@$(RM) $(NAME)
							@$(RM) $(OBJS_DIR)

re:					fclean all

.PHONY:				all clean fclean re

