/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:55:46 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:07 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

/* ra: rotate a - shift up all elements of stack a by 1 */
void	ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/* rb: rotate b - shift up all elements of stack b by 1 */
void	rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/* rr: ra and rb at the same time */
void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
