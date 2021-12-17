/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testsuit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:27:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/16 23:05:54 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

static int	test_if_delete_stack_behave_normally_with_only_one_node_on_stack(void)
{
	t_stack	*stack = new_stack(1);
	del_stack(stack);
	
	return (1);
}

static int	test_if_add_update_the_positions_correctly(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);

	stack = add(0, 0, stack);
	for (size_t pos = 1; pos <= n_nodes + 1; ++pos)
	{
		if (stack->pos != pos)
		{
			printf("\e[0;31madd has failed to update the positions\n");
			printf("Expected: %zu; but instead it is %zu\e[0m\n", pos, stack->pos);
			del_stack(stack);
			return (0);
		}
		stack = stack->next;
	}
	del_stack(stack);
	return (1);
}

static int	test_if_add_adds_a_new_node_at_the_top_of_stack(void)
{
	size_t	n_nodes = 10;
	t_stack	*stack = new_stack(n_nodes);
	stack->item = 1;

	stack = add(2, 0, stack);
	if (stack->item != 2)
	{
		printf("\e[0;31madd has failed to place a new node at the top of the stack\e[0m\n");
		del_stack(stack);
		return (0);
	}
	del_stack(stack);
	return (1);
}

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
	t_test	**tests = init_tests();

	tests = set_test(test_if_new_stack_return_a_stack_with_the_total_amount_of_nodes_asked, tests);
	tests = set_test(test_if_all_the_positions_are_correct, tests);
	tests = set_test(test_if_pop_remove_the_top_node, tests);
	tests = set_test(test_if_pop_update_correctly_all_the_positions, tests);
	tests = set_test(test_if_pop_the_third_node_still_updating_correctly_all_the_positions, tests);
	tests = set_test(test_if_add_adds_a_new_node_at_the_top_of_stack, tests);
	tests = set_test(test_if_add_update_the_positions_correctly, tests);
	tests = set_test(test_if_delete_stack_behave_normally_with_only_one_node_on_stack, tests);

	printf("====================================================================\n\n");
	
	int 	success = 0;
	size_t	test_n = 0;
	size_t	total_tests = count_tests(tests);
	while (test_n < total_tests)
	{
		success += tests[test_n]();
		++test_n;
	}

	free(tests);
	tests = NULL;

	printf("\n--------------------------------------------------------------------\n");
	if (success == (int)total_tests)
		printf("\n\e[0;32mAll the %zu tests are passing!\e[0m\n", total_tests);
	else
	{
		printf("\nSome tests had failed.\n");
		printf("%i of %zu were successfully completed.\n", success, total_tests);
	}
	return (0);
}
