/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:25:22 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:11 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* rra: reverse rotate a - shift down all elements of stack a by 1 */
void	rra(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/* rrb: reverse rotate b - shift down all elements of stack b by 1 */
void	rrb(t_stack **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/* rrr: rra and rrb at the same time */
void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
