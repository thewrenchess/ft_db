# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 16:11:06 by dhuang            #+#    #+#              #
#    Updated: 2017/05/04 20:15:02 by yherrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re testing

vpath %.h includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

ASAN = -fsanitize=address

INCLUDES = -I includes/

SRCFILES = 	main.c \
			ft_table.c \
			ft_open.c \
			ft_parse.c \
			ft_getstuff.c \
			ft_readdir.c \
			ft_display.c \
			ft_sort.c \
			ft_intchstrsort.c \
			ft_db_swap.c \
			ft_compareinput.c \
			ft_update.c \

SRCDIR := srcs

SRC:= $(addprefix $(SRCDIR)/, SRCFILES))

LFT = libft/libft.a

OBJDIR := obj

OBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRCFILES)))

NAME = ft_db

all: $(NAME)

$(LFT):
		make -C libft/

$(OBJS): ft_db.h $(SRCS) | $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(OBJDIR):
		@echo "Creating subdirectory for object files..."
		@mkdir $(OBJDIR)

$(NAME): $(OBJS) $(LFT)
		@echo "Creating $(NAME)..."
		@$(CC) $(CFLAGS) $(ASAN) $(OBJS) -o $@ -L libft/ -lft
		@echo "All done!"

clean:
		@echo "Deleting $(NAME) object files and subdirectory..."
		@rm -f $(OBJS)
		@rm -rf $(OBJDIR)
		make clean -C libft/

fclean: clean
		@echo "Deleting $(NAME)..."
		@rm -f $(NAME)
		make fclean -C libft/

re: fclean all
