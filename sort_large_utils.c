/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:12:15 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:21:46 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (20);
	else
		return (40);
}

int	get_num_chunks(int stack_size)
{
	int	chunk_size;

	chunk_size = get_chunk_size(stack_size);
	return ((stack_size + chunk_size - 1) / chunk_size);
}

int	find_closest_chunk_element(t_stack *stack, int chunk_start, int chunk_end)
{
	t_stack	*temp;
	int		pos;
	int		closest_pos;
	int		size;

	temp = stack;
	pos = 0;
	closest_pos = -1;
	size = get_stack_size(stack);
	while (temp && pos <= size / 2)
	{
		if (temp->index >= chunk_start && temp->index <= chunk_end)
		{
			closest_pos = pos;
			break ;
		}
		temp = temp->next;
		pos++;
	}
	if (closest_pos == -1)
		closest_pos = find_chunk_element_from_bottom(stack, chunk_start,
				chunk_end);
	return (closest_pos);
}

int	find_chunk_element_from_bottom(t_stack *stack, int chunk_start,
		int chunk_end)
{
	t_stack	*temp;
	int		pos;
	int		closest_pos;

	temp = stack;
	pos = 0;
	closest_pos = -1;
	while (temp)
	{
		if (temp->index >= chunk_start && temp->index <= chunk_end)
			closest_pos = pos;
		temp = temp->next;
		pos++;
	}
	return (closest_pos);
}

int	find_best_element_to_push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_b;
	int		best_pos;
	int		best_cost;
	int		pos_b;
	int		current_cost;

	temp_b = stack_b;
	best_pos = -1;
	best_cost = INT_MAX;
	pos_b = 0;
	while (temp_b)
	{
		current_cost = calculate_push_cost(stack_a, stack_b, pos_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_pos = pos_b;
		}
		temp_b = temp_b->next;
		pos_b++;
	}
	return (best_pos);
}
