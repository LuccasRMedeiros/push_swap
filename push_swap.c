/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/12 00:19:30 by lrocigno         ###   ########.fr       */
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

static void	sort(t_prog *prog, t_act *preds[5], unsigned int dch)
{
	int		dists[2];
	size_t	pd_i;

	dists[d] = 0;
	dists[u] = 0;
	pd_i = 0;
	psc_find_next(prog, dists, dch);
	if (dists[d] == (int)prog->a_size - 1)
	{
		psc_merge(prog);
		if (psc_observe(prog))
			return ;
		else
			++dch;
	}
	psc_predict(prog, preds, dists, dch);
	while (pd_i <= act2)
	{
		if (preds[pd_i])
		{
			preds[pd_i](&prog);
			preds[pd_i + 3] = preds[pd_i];
			preds[pd_i] = NULL;
		}
		++pd_i;
	}
	sort(prog, preds, dch);
}

/*
** Uses radix sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	t_act	*preds[5];
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	preds[act1] = NULL;
	preds[act2] = NULL;
	preds[await] = NULL;
	preds[hst1] = NULL;
	preds[hst1] = NULL;
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(argc - 1, pre_stack);
	sort(prog, preds, 0);
	end_prog(&prog);
	return (0);
}
