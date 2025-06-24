/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:23:37 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 00:23:41 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack **stack_a)
{
	int	min_pos;
	int	stack_size;

	update_positions(*stack_a);
	min_pos = get_lowest_index_position(*stack_a);
	stack_size = get_stack_size(*stack_a);
	if (min_pos <= stack_size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (min_pos++ < stack_size)
			rra(stack_a, 1);
	}
}
