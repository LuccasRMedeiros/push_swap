/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testsuit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:27:12 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/04 21:18:13 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** THIS IS NOT PART OF 42 CURRICULUM.
**
** Tests the functions of push_swap.
*/

static int	test_if_pse_try_parse_args_print_error_when_duplicated_values_are_informed(void)
{
	char	**argv = ft_split("1 2 3 4 5 5", ' ');
	char	*line[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int		pipefd[2];
	int		wstatus = 0;
	
	pipe(pipefd);
	
	pid_t	child = fork();
	if (child == 0)
	{
		// This is child.
		close(pipefd[0]);

		dup2(pipefd[1], 1);
		pse_try_parse_args(6, argv);
		exit(0);
	}
	else
	{
		// This is parent.
		wait(&wstatus);
		close(pipefd[1]);

		ft_destroyer((void **)argv);
		ft_gnl(pipefd[0], line);
		
		if (strcmp(*line, "Error"))
		{
			while (ft_gnl(pipefd[0], line)) {}
			close(pipefd[0]);

			printf("\e[1;33mpse_try_parse_args\e[0;31m did not printed 'Error'.\e[0m\n");
			return (0);
		}
	}

	while (ft_gnl(pipefd[0], line)) {}
	close(pipefd[0]);

	return (1);
}

static int	test_if_pse_check_args_does_not_when_a_correct_stack_is_informed(void)
{
	char	**argv = ft_split("1 2 3 4 5", ' ');
	char	*line[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int		pipefd[2];
	int		wstatus = 0;

	pipe(pipefd);
	
	pid_t	child = fork();
	if (child == 0)
	{
		// This is child.
		close(pipefd[0]);

		dup2(pipefd[1], 1);
		pse_check_args(argv);
		exit(0);
	}
	else
	{
		// This is parent.
		wait(&wstatus);
		close(pipefd[1]);

		ft_destroyer((void **)argv);
		ft_gnl(pipefd[0], line);

		if (!strcmp(*line, "Error"))
		{
			while (ft_gnl(pipefd[0], line)) {}
			close(pipefd[0]);

			printf("\e[1;33mpse_check_args\e[0;31m did printed 'Error'.\e[0m\n");
			return (0);
		}
	}

	while (ft_gnl(pipefd[0], line)) {}
	close(pipefd[0]);

	return (1);
}

static int	test_if_pse_check_args_print_error_when_wrong_arguments_are_informed(void)
{
	char	**argv = ft_split("1 2 3 d 5", ' ');
	char	*line[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int		pipefd[2];
	int		wstatus = 0;

	pipe(pipefd);
	
	pid_t	child = fork();
	if (child == 0)
	{
		// This is child.
		close(pipefd[0]);

		dup2(pipefd[1], 1);
		pse_check_args(argv);
		exit(0);
	}
	else
	{
		// This is parent.
		wait(&wstatus);
		close(pipefd[1]);

		ft_destroyer((void **)argv);
		ft_gnl(pipefd[0], line);

		if (strcmp(*line, "Error"))
		{
			while (ft_gnl(pipefd[0], line)) {}
			printf("\e[1;33mpse_check_args\e[0;31m did not printed 'Error'.\e[0m\n");
			return (0);
		}
	}

	while (ft_gnl(pipefd[0], line)) {}
	close(pipefd[0]);

	return (1);
}

static int	test_if_init_prog_initialize_a_t_prog_correctly(void)
{
	int	n_items = 10;
	int	*pre_stack = malloc(sizeof(int) * 10);
	for (int item = 1; item <= n_items; ++item)
	{
		pre_stack[item - 1] = item;
	}

	t_prog	*prog = init_prog(n_items, pre_stack);
	if (!prog)
	{
		printf("\e[0;31mReceived a null pointer from init_prog\e[0m\n");
		return (0);
	}

	if (!prog->stack_a)
	{
		printf("\e[0;31minit_prog failed to create the stack_a\e[0m\n");
		free(prog);
		return (0);
	}
	else if (!prog->stack_b)
	{
		printf("\e[0;31minit_prog failed to create the stack_b\e[0m\n");
		del_stack(prog->stack_a);
		free(prog);
		return (0);
	}

	for (int item = 1; item <= n_items; ++item)
	{
		if (prog->stack_a->item != item)
		{
			printf("\e[0;31mWrong item on node\n");
			printf("Expected: %i, but instead it is %i", item, prog->stack_a->item);
			end_prog(&prog);
			return (0);
		}
		prog->stack_a = prog->stack_a->next;
	}

	end_prog(&prog);
	
	return (1);
}

static int	test_if_delete_stack_behave_normally_with_only_one_node_on_stack(void)
{
	pid_t	child = fork();
	int		status = 0;

	if (child == 0)
	{
		t_stack	*stack = new_stack(1);
		del_stack(stack);

		exit(0);
	}
	else
	{
		waitpid(child, &status, 0);
		if (status == 256)
		{
			printf("\e[0;31mdel_stack caused a SEGMENTATION FAULT trying to delete a single node list\e[0m\n");
			return (0);
		}
	}

	return (1);
}

static int	test_if_pop_deletes_a_node(void)
{
	size_t	n_nodes_a = 10;

	t_stack	*stack_a = new_stack(n_nodes_a);

	for (int item = 1; item <= (int)n_nodes_a; ++item)
	{
		stack_a->item = item;
		stack_a->rank = (size_t)item;
		stack_a = stack_a->next;
	}
	
	stack_a = pop(stack_a);

	if (stack_a->item == 1)
	{
		del_stack(stack_a);
		printf("\e[0;33mpop\e[0;31m failed to remove the top item of stack A\e[0m\n");
		return (0);
	}
	else if (stack_a->prev->item == 1)
	{
		del_stack(stack_a);
		printf("\e[0;33mpop\e[0;31m only advanced one node or not complely deleted the node\e[0m\n");
		return (0);
	}
	
	del_stack(stack_a);
	return (1);
}

static int	test_if_copy_copies_a_node(void)
{
	size_t	n_nodes_a = 10;
	size_t	n_nodes_b = 5;

	t_stack	*stack_a = new_stack(n_nodes_a);
	t_stack *stack_b = new_stack(n_nodes_b);

	for (int item = 1; item <= (int)n_nodes_a; ++item)
	{
		stack_a->item = item;
		stack_a->rank = (size_t)item;
		stack_a = stack_a->next;
	}
	for (int item = 11; item - 10 <= (int)n_nodes_b; ++item)
	{
		stack_b->item = item;
		stack_b->rank = (size_t)item;
		stack_b = stack_b->next;
	}
	
	stack_b = copy(stack_a, stack_b);

	if (stack_b->item == 1)
	{
		if (stack_a->item != 1)
		{
			del_stack(stack_a);
			del_stack(stack_b);
			printf("\e[0;33mcopy\e[0;31m failed to remove the top item of stack A\e[0m\n");
			return (0);
		}
	}
	else
	{
		del_stack(stack_a);
		del_stack(stack_b);
		printf("\e[0;33mcopy\e[0;31m failed to place the item at the top of stack B\e[0m\n");
		return (0);
	}
	
	del_stack(stack_a);
	del_stack(stack_b);
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
	tests = set_test(test_if_copy_copies_a_node, tests);
	tests = set_test(test_if_pop_deletes_a_node, tests);
	tests = set_test(test_if_delete_stack_behave_normally_with_only_one_node_on_stack, tests);
	tests = set_test(test_if_init_prog_initialize_a_t_prog_correctly, tests);
	tests = set_test(test_if_pse_check_args_print_error_when_wrong_arguments_are_informed, tests);
	tests = set_test(test_if_pse_check_args_does_not_when_a_correct_stack_is_informed, tests);
	tests = set_test(test_if_pse_try_parse_args_print_error_when_duplicated_values_are_informed, tests);

	printf("====================================================================\n\n");
	
	int 	success = 0;
	size_t	test_n = 0;
	size_t	total_tests = count_tests(tests);
	while (test_n < total_tests)
	{
		if (tests[test_n]())
		{
			printf("\e[0;32m%zu - OK\e[0m\n", test_n + 1);
			++success;
		}
		++test_n;
	}

	free(tests);
	tests = NULL;

	printf("\n--------------------------------------------------------------------\n");
	if (success == (int)total_tests)
		printf("\n\e[0;32mAll the %zu tests were successfully completed!\e[0m\n", total_tests);
	else
	{
		printf("\nSome tests had failed.\n");
		printf("%i of %zu were successfully completed.\n", success, total_tests);
	}
	return (0);
}
