/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:12:09 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:27:56 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_for_element(int pos_b, t_stack *stack_a, t_stack *stack_b)
{
	int	target_pos;
	int	stack_a_size;
	int	stack_b_size;
	int	cost;
	int	index_b;

	stack_a_size = get_stack_size(stack_a);
	stack_b_size = get_stack_size(stack_b);
	index_b = get_element_index(stack_b, pos_b);
	target_pos = get_target_position(stack_a, index_b);
	cost = 0;
	if (pos_b <= stack_b_size / 2)
		cost = pos_b;
	else
		cost = stack_b_size - pos_b;
	if (target_pos <= stack_a_size / 2)
		cost += target_pos;
	else
		cost += stack_a_size - target_pos;
	return (cost);
}

int	get_element_index(t_stack *stack, int pos)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = 0;
	while (i < pos && temp)
	{
		temp = temp->next;
		i++;
	}
	if (!temp)
		return (0);
	return (temp->index);
}

int	calculate_push_cost(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	if (!stack_b || pos_b < 0)
		return (INT_MAX);
	return (get_cost_for_element(pos_b, stack_a, stack_b));
}

void	move_element_to_top_b(t_stack **stack_b, int pos)
{
	int	stack_b_size;

	stack_b_size = get_stack_size(*stack_b);
	if (pos <= stack_b_size / 2)
	{
		while (pos-- > 0)
			rb(stack_b, 1);
	}
	else
	{
		while (pos++ < stack_b_size)
			rrb(stack_b, 1);
	}
}

void	move_to_target_in_a(t_stack **stack_a, int index_b)
{
	int	target_pos;
	int	stack_a_size;

	target_pos = get_target_position(*stack_a, index_b);
	stack_a_size = get_stack_size(*stack_a);
	if (target_pos <= stack_a_size / 2)
	{
		while (target_pos-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (target_pos++ < stack_a_size)
			rra(stack_a, 1);
	}
}
