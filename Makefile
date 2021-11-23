# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 10:30:55 by lrocigno          #+#    #+#              #
#    Updated: 2021/11/23 00:36:55 by lrocigno         ###   ########.fr        #
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

SANITIZERS =

DEPS = -L libs/libft/ -lft \

INCLUDES =	-I ./libs/libft/ \
	  		-I ./includes/ \

BASE =	del_item.c \
		end_prog.c \
		init_prog.c \

MD_ERROR =	pse_check_args.c \
			pse_try_parse_args.c \

MD_MOVES =	psm_pa.c \
			psm_pb.c \
			psm_ra.c \
			psm_rb.c \
			psm_rr.c \
			psm_rra.c \
			psm_rrb.c \
			psm_rrr.c \
			psm_sa.c \
			psm_sb.c \
			psm_ss.c \

MD_CORE =	psc_execute.c \
			psc_look.c \

SRC =	$(BASE) \
		$(MD_ERROR) \
		$(MD_MOVES) \
		$(MD_CORE) \

OBJ = $(SRC:%.c=%.o)

SRC_FULL =	$(addprefix ./src/, $(BASE)) \
			$(addprefix ./error/, $(MD_ERROR)) \
			$(addprefix ./moves/, $(MD_MOVES)) \
			$(addprefix ./core/, $(MD_CORE)) \

all: makelibft $(NAME)
	echo "$$PUSHSWAP"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(SANITIZERS) push_swap.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(INCLUDES) $(SANITIZERS) -c $(SRC_FULL)

clean:
	make -C ./libs/libft clean
	rm -f *.o

fclean: clean
	make -C ./libs/libft fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	make -C ./libs/libft all
