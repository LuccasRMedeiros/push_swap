/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testsuit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:27:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/14 01:53:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

static int	test_if_pop_the_third_node_still_updating_correctly_all_the_positions(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);

	stack = stack->next->next;
	stack = pop(stack);

	for (size_t pos = 3; pos <= n_nodes; ++pos)
	{
		if (stack->pos != pos && pos < 10)
		{
			printf("\e[0;31mpop has failed to update the positions\n");
			printf("Expected: %zu; but instead it is %zu\e[0m\n", pos, stack->pos);
			del_stack(stack);
			return (0);
		}
		if (pos > 9 && stack->pos != pos - 9)
		{
			printf("\e[0;31mpop has failed to update the positions\n");
			printf("Expected: %zu; but instead it is %zu\e[0m\n", pos - 9, stack->pos);
			del_stack(stack);
			return (0);
		}
		stack = stack->next;
	}
	del_stack(stack);
	return (1);
}

static int	test_if_pop_update_correctly_all_the_positions(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);

	stack = pop(stack);

	for (size_t pos = 1; pos <= n_nodes; ++pos)
	{
		if (stack->pos != pos && pos != 10)
		{
			printf("\e[0;31mpop has failed to update the positions\n");
			printf("Expected: %zu; but instead it is %zu\e[0m\n", pos, stack->pos);
			del_stack(stack);
			return (0);
		}
		if (pos == 10 && stack->pos == pos) // Cause the last node can inform pos = 10.
		{
			printf("\e[0;31mpop has failed to update the positions\n");
			printf("Expected: 1; but instead it is 10\n\e[0m");
			del_stack(stack);
			return (0);
		}
		stack = stack->next;
	}
	del_stack(stack);
	return (1);
}

static int	test_if_pop_remove_the_top_node(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);

	stack->item = 1;
	stack = pop(stack);
	if (stack->item == 1)
	{
		printf("\e[0;31mpop has failed to delete the item\e[0m\n");
		del_stack(stack);
		return (0);
	}
	del_stack(stack);
	return (1);
}

static int	test_if_all_the_positions_are_correct(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);

	for (size_t pos = 1; pos <= n_nodes; ++pos)
	{
		if (stack->pos != pos)
		{
			printf("\e[0;31mThe positions are not correctly placed.\n");
			printf("Expected: %zu; but instead it is %zu\n", pos, stack->pos);
			del_stack(stack);
			return (0);
		}
		stack = stack->next;
	}
	del_stack(stack);
	return (1);
}

static int	test_if_new_stack_return_a_stack_with_the_total_amount_of_nodes_asked(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);
	t_stack	*head = stack;
	size_t	count = 1;

	while (stack->next != head)
	{
		++count;
		stack = stack->next;
	}
	del_stack(stack);
	head = NULL;
	if (count != n_nodes)
	{
		printf("\e[0;31mnew_stack does not created the desired amount of nodes\e[0m\n");
		return (0);
	}
	return (1);
}

/*
** Batery of tests for parts of push_swap.
*/

int	main(void)
{
	int	success = 0;

	printf("====================================================================\n");
	
	success += test_if_new_stack_return_a_stack_with_the_total_amount_of_nodes_asked();
	success += test_if_all_the_positions_are_correct();
	success += test_if_pop_remove_the_top_node();
	success += test_if_pop_update_correctly_all_the_positions();
	success += test_if_pop_the_third_node_still_updating_correctly_all_the_positions();

	printf("\n--------------------------------------------------------------------\n");
	if (success == 5)
		printf("\n\e[0;32mOK!\e[0m\n");
	else
		printf("\nSome tests had failed.\n");
	return (0);
}
