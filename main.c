/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:22:36 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 01:00:44 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv, &stack_size);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_b = NULL;
	if (is_stack_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	assign_index(stack_a, stack_size);
	sort(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
