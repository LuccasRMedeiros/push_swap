/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 00:13:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

/*
** Will predict what movements are the probably the best to sort.
**
** This routine is recursive and will only stop when psc_predict don't predict
** nothing anymore. Note that this doesn't mean that all the numbers are placed
** in their correct order, it is possible that the first number is at the middle
** of the stack A, the stack B can still be holding some items, what actually
** happens when psc_observe doesn't bring any problem is that all the items in 
** both stacks are followed by its supposed sequence. 
**
** Because of this is necessary to merge then (or just rotate the items on stack
** A till the rank 1 be placed on top of the stack), only then the sort routine
** will exit itself letting the program to finish.
*/

void	sort(t_prog *prog, t_act *preds[5])
{
	size_t	act;
	int	obs[2][2];

	act = 0;
	psc_observe(prog, obs);
	psc_predict(prog, preds, obs);
	if (!preds[act1] && !preds[act2] && !preds[await])
	{
		psc_merge(prog);
		psc_observe(prog, obs);
		if (obs[a][d] == prog->a_size && obs[b][u] == prog->b_size)
			return ;
	}
	while (act < await)
	{
		if (preds[act])
		{
			preds[act](&prog);
			preds[act + 3] = preds[act];
			preds[act] = NULL;
		}
		++act;
	}
	sort(prog, preds);
}

/*
** Uses sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	t_act	*acts[5];
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	acts[act1] = NULL;
	acts[act2] = NULL;
	acts[await] = NULL;
	acts[3] = NULL;
	acts[4] = NULL;
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(argc - 1, pre_stack);
	sort(prog, acts);
	end_prog(&prog);
	return (0);
}
