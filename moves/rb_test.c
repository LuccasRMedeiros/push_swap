#include "push_swap_moves.h"

int main(void)
{
	t_dlist	*stack_b = ft_dlstnew("A");
	ft_dlstadd("B", &stack_b);
	ft_dlstadd("C", &stack_b);
	
	printf("before: %s\n", (char *)stack_b->content);

	push_swap_rb(&stack_b);

	printf("after: %s\n", (char *)stack_b->content);

	return (0);
}
