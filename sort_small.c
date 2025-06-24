/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:12:33 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:34 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min_pos;

	while (size > 3)
	{
		update_positions(*stack_a);
		min_pos = find_min_index_position(*stack_a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			while (min_pos++ < size)
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
