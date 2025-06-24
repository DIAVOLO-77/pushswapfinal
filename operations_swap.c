/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:24:21 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:04 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/* sa: swap a - swap the first 2 elements at the top of stack a */
void	sa(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

/* sb: swap b - swap the first 2 elements at the top of stack b */
void	sb(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

/* ss: sa and sb at the same time */
void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
