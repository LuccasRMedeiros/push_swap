# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 10:30:55 by lrocigno          #+#    #+#              #
#    Updated: 2021/11/17 16:56:49 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

define PUSHSWAP
                                                                                
          _________                                                             
    ___  /________/                                                             
   (___________)     _____   _   _   _____   _   _                              
      (____)        |  _  \ | | | | /  ___| | | | |                             
     (______)       | |_| | | | | | | /___  | |_| |                             
    (________)      |  ___/ | | | | \____ \ |  _  |                             
    ___(__)___	    | |     | \_/ |  ___/ | | | | |          ____               
   (__________)	    |_|     \_____/ |_____/ |_| |_|         (____( ______          
                             _____   _   _     _     _____     ___)______)         
                            /  ___| | | | |   / \   |  _  \   (________)        
                            | /___  | | | |  / ^ \  | |_| |  (_________)       
                            \____ \ | |^| | / /_\ \ |  ___/  (__________)       
                             ___/ | \  ^  / |  _  | | |     (____________)      
                            |_____/  \/ \/  |_| |_| |_|     (_____________)     
                                                                                
endef
export PUSHSWAP

CC = clang

FLAGS = -Wall -Werror -Wextra -g

DEPS = -L libs/libft/ -lft \

INCLUDES =	-I ./libs/libft/ \
	  		-I ./includes/ \

BASE =	del_stack.c \
		new_stack.c \

MD_ERROR =	push_swap_error_check_args.c \
			push_swap_error_try_parse_args.c \

SRC = $(MD_ERROR)

OBJ = $(SRC:%.c=%.o)

SRC_FULL =	$(addprefix ./error/, $(MD_ERROR)) \

all: makelibft $(NAME)
	echo "$$PUSHSWAP"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) push_swap.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRC_FULL)

clean:
	make -C ./libs/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libs/libft fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	make -C ./libs/libft all
