/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 02:33:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

/*
** The routine will observe the stack to decide which direction is better for a
** eventual rotation, then it predicts the movements and execute them till the
** stack be sorted.
**
** It does this recursively and only stops when the observe confirms that 
** everything was sorted. This prevent the program to try to sort a already 
** sorted stack, did this happened due to a perfect sequence be informed or for
** luck the stack be sorted after few attempts.
**
** During its execution, the decimal house is only updated when a merge happens
** because this means that the sort for that decimal house has ended. The need
** for a merge can be confirmed by obs[d] (d = 0) being equal to the size of 
** stack A less 1, what means that psc_observe looked to all items on stack A
** and no one is a candidate to go to stack B.
*/

static void	sort(t_prog *prog, t_stack *stk, t_act *mvs[3], int dch)
{
	int	is_b;
	int	mv_n;

	if (dch == prog->max_bits)
		return ;
	is_b = pscu_is_stack_b_mv(mvs[rotn]);
	mv_n = prog->a_size + 1;
	if (is_b)
		mv_n = prog->b_size + 1;
	dch += is_b;
	while (pscu_find_next(stk, mv_n, dch) != is_b && --mv_n)
	{
		if (((stk->rank >> dch) & 1) == is_b)
			mvs[push](&prog);
		else
			mvs[rotn](&prog);
		stk = prog->stack_a;
		if (is_b)
			stk = prog->stack_b;
	}
	while (--mv_n)
		mvs[cred](&prog);
	psc_invertmv(mvs);
	sort(prog, pscu_selstack(prog, is_b), mvs, dch);
}

/*
** Uses radix sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	t_act	*mvs[3];
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	mvs[rotn] = pscm_ra;
	mvs[push] = pscm_pb;
	mvs[cred] = pscm_rra;
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(argc - 1, pre_stack);
	sort(prog, prog->stack_a, mvs, 0);
	end_prog(&prog);
	return (0);
}
