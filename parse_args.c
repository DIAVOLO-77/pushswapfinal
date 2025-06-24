/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:20:16 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/21 23:20:16 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			*error = 1;
		i++;
	}
	return ((int)(result * sign));
}

int	process_argument(char *arg, t_stack **stack, int *stack_size)
{
	int	value;
	int	error;

	if (!is_number(arg))
		return (0);
	value = ft_atoi_safe(arg, &error);
	if (error || is_duplicate(*stack, value))
		return (0);
	add_to_stack(stack, create_new_node(value));
	(*stack_size)++;
	return (1);
}

t_stack	*parse_args(int argc, char **argv, int *stack_size)
{
	t_stack	*stack_a;
	int		i;
	int		success;

	stack_a = NULL;
	*stack_size = 0;
	i = 1;
	while (i < argc)
	{
		success = 1;
		if (ft_strchr(argv[i], ' '))
			success = process_quoted_arg(argv[i], &stack_a, stack_size);
		else
			success = process_argument(argv[i], &stack_a, stack_size);
		if (!success)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
