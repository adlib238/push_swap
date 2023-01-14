# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 02:59:02 by kfumiya           #+#    #+#              #
#    Updated: 2021/10/13 19:08:02 by kfumiya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		all_free.c is_sorted.c message.c ps_init.c util_dlst.c quick_sort.c \
			exec_opt.c opt_swap.c opt_push.c opt_rotate.c opt_r_rotate.c \
			opt_addans.c print_sleep.c util_str.c message_2.c init_check.c

SRC_PS =	push_swap.c ps_utils.c sort_under6.c allsort.c \
			sort_over7.c sort_over7_utils.c ans_replace.c

SRC_CHK =	checker.c

OBJ = 		$(SRC:.c=.o)
OBJ_PS = 	$(SRC_PS:.c=.o)
OBJ_CHK = 	$(SRC_CHK:.c=.o)

SRCDIR = 		srcs
SRCDIR_CHK = 	srcs_chk
OBJDIR_CHK = 	objs_chk
SRCDIR_PS = 	srcs_ps
OBJDIR_PS = 	objs_ps
LIBDIR = 		libft

SRCS_PS =	$(addprefix $(SRCDIR_PS)/, $(SRC_PS)) \
			$(addprefix $(SRCDIR)/, $(SRC))
OBJS_PS =	$(addprefix $(OBJDIR_PS)/, $(OBJ_PS)) \
			$(addprefix $(OBJDIR_PS)/, $(OBJ))
SRCS_CHK =	$(addprefix $(SRCDIR_CHK)/, $(SRC_CHK)) \
			$(addprefix $(SRCDIR)/, $(SRC))
OBJS_CHK =	$(addprefix $(OBJDIR_CHK)/, $(OBJ_CHK)) \
			$(addprefix $(OBJDIR_CHK)/, $(OBJ))

LIBS = -L $(LIBDIR) -lft
HEADER = -I includes -I $(LIBDIR)/includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME_PS = push_swap
NAME_CHK = checker

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all:	$(NAME_PS)
#PUSH_SWAP
$(OBJDIR_PS)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR_PS)/%.o: $(SRCDIR_PS)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME_PS): $(OBJS_PS)
	@make -C $(LIBDIR)
	$(CC) $(OBJS_PS) $(HEADER) $(LIBS) -o $@

bonus:	$(NAME_CHK)
#CHECKER
$(OBJDIR_CHK)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR_CHK)/%.o: $(SRCDIR_CHK)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@


$(NAME_CHK): $(OBJS_CHK)
	@make -C $(LIBDIR)
	$(CC) $(OBJS_CHK) $(HEADER) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_CHK)
	@make -C $(LIBDIR) clean
	@echo "[push_swap - clean]"
	@echo "[checker - clean]"

fclean:
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -f $(NAME_PS)
	@/bin/rm -f $(NAME_CHK)
	@make -C $(LIBDIR) fclean
	@echo "[Push_swap - fclean]"
	@echo "[checker - fclean]"

re: fclean all
