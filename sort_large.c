/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:12:27 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:38 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_stack **stack_a, t_stack **stack_b,
			int chunk_start, int chunk_end)
{
	int	closest_pos;
	int	stack_a_size;

	while (get_stack_size(*stack_a) > 0)
	{
		update_positions(*stack_a);
		closest_pos = find_closest_chunk_element(*stack_a,
				chunk_start, chunk_end);
		if (closest_pos == -1)
			break ;
		stack_a_size = get_stack_size(*stack_a);
		if (closest_pos <= stack_a_size / 2)
		{
			while (closest_pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			while (closest_pos++ < stack_a_size)
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
		if ((*stack_b)->index <= (chunk_end - (chunk_end - chunk_start) / 2))
			rb(stack_b, 1);
	}
}

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;
	int	num_chunks;
	int	chunk;
	int	chunk_start;
	int	chunk_end;

	chunk_size = get_chunk_size(size);
	num_chunks = get_num_chunks(size);
	chunk = 1;
	while (chunk <= num_chunks)
	{
		chunk_start = (chunk - 1) * chunk_size + 1;
		chunk_end = chunk * chunk_size;
		push_chunk(stack_a, stack_b, chunk_start, chunk_end);
		chunk++;
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	best_pos;

	while (*stack_b)
	{
		update_positions(*stack_a);
		update_positions(*stack_b);
		best_pos = find_best_element_to_push(*stack_a, *stack_b);
		move_element_to_top_b(stack_b, best_pos);
		move_to_target_in_a(stack_a, (*stack_b)->index);
		pa(stack_a, stack_b, 1);
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_chunks_to_b(stack_a, stack_b, size);
	push_back_to_a(stack_a, stack_b);
	move_min_to_top(stack_a);
}
