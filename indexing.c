/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:23:25 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:26:44 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*min;
	int		value;
	int		i;

	i = 0;
	while (i < size)
	{
		current = stack;
		min = NULL;
		value = INT_MAX;
		while (current)
		{
			if (current->value < value && current->index == 0)
			{
				value = current->value;
				min = current;
			}
			current = current->next;
		}
		if (min)
			min->index = i + 1;
		i++;
	}
}

void	update_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

int	find_min_index_position(t_stack *stack)
{
	int	min_index;
	int	min_pos;
	int	i;

	if (!stack)
		return (-1);
	min_index = INT_MAX;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

int	get_target_position(t_stack *stack_a, int index_b)
{
	t_stack	*current;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = 0;
	update_positions(stack_a);
	current = stack_a;
	while (current)
	{
		if (current->index > index_b && current->index < target_index)
		{
			target_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	return (get_lowest_index_position(stack_a));
}

int	get_lowest_index_position(t_stack *stack)
{
	int		lowest_index;
	int		lowest_pos;
	int		i;

	if (!stack)
		return (0);
	lowest_index = INT_MAX;
	lowest_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < lowest_index)
		{
			lowest_index = stack->index;
			lowest_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (lowest_pos);
}
