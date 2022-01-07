# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 14:51:57 by lrocigno          #+#    #+#              #
#    Updated: 2021/12/17 18:05:03 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_testsuit

CC = clang-13

FLAGS = -Wall -Werror -Wextra -g

SANITIZERS = -fsanitize=address

INCLUDES =	-I ../includes/ \
			-I ../libs/libft/ \

DEPS =	-L ./ -lpushswap \
		-L ../libs/libft/ -lft \

SRC =	count_tests.c \
		init_tests.c \
		set_test.c \

OBJ = $(SRC:%.c=%.o)

all: make_push $(NAME)
	./$(NAME)

try: fclean $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) push_swap_testsuit.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) -c $(SRC)

clean:
	@echo "This action does not change the files on the push_swap directories."
	@rm -f *.o
	@echo "Cleaned all the objects."

fclean: clean
	@rm -f libpushswap.a
	@rm -f $(NAME)
	@echo "Static library and executable were deleted."

make_push:
	@make -C ../ CC=$(CC) SANITIZERS=$(SANITIZERS) re
	@ar -rcs libpushswap.a ../*.o
	@echo "lib push_swap was created."

re: fclean all

.PHONY: all clean fclean make_push re try
