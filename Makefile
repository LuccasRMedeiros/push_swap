# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 10:30:55 by lrocigno          #+#    #+#              #
#    Updated: 2022/01/17 18:46:41 by lrocigno         ###   ########.fr        #
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

BASE =	copy.c \
		del_stack.c \
		end_prog.c \
		init_prog.c \
		new_stack.c \
		pop.c \

MD_ERROR =	pse_check_args.c \
			pse_try_parse_args.c \

MD_CORE =	psc_merge.c \
			psc_de_radixsort.c \
			psc_simplesort.c \

MD_CORE_MOVES =	pscm_pa.c \
				pscm_pb.c \
				pscm_ra.c \
				pscm_rb.c \
				pscm_rr.c \
				pscm_rra.c \
				pscm_rrb.c \
				pscm_rrr.c \
				pscm_sa.c \
				pscm_sb.c \
				pscm_ss.c \

MD_CORE_UTILS = pscu_calccred.c \
				pscu_find_next.c \
				pscu_flwnx.c \
				pscu_flwpv.c \
				pscu_invertmv.c \
				pscu_is_stack_a_mv.c \
				pscu_is_stack_b_mv.c \
				pscu_observe.c \
				pscu_selstack.c \

SRC =	$(BASE) \
		$(MD_ERROR) \
		$(MD_CORE) \
		$(MD_CORE_MOVES) \
		$(MD_CORE_UTILS) \

OBJ = $(SRC:%.c=%.o)

SRC_FULL =	$(addprefix ./src/, $(BASE)) \
			$(addprefix ./error/, $(MD_ERROR)) \
			$(addprefix ./core/, $(MD_CORE)) \
			$(addprefix ./core/moves/, $(MD_CORE_MOVES)) \
			$(addprefix ./core/utils/, $(MD_CORE_UTILS)) \

all: makelibft $(NAME)
	echo "$$PUSHSWAP"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) push_swap.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) -c $(SRC_FULL)

clean:
	make -C ./libs/libft clean
	rm -f *.o

fclean: clean
	make -C ./libs/libft fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	make -C ./libs/libft all

.PHONY: all clean fclean makelibft re
