/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:55:56 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/21 23:55:56 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

/* Input parsing and validation */
int		is_number(const char *str);
int		is_duplicate(t_stack *stack, int value);
int		ft_atoi_safe(const char *str, int *error);
int		process_argument(char *arg, t_stack **stack, int *stack_size);
int		process_quoted_arg(char *arg, t_stack **stack, int *stack_size);
t_stack	*parse_args(int argc, char **argv, int *stack_size);
char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_words(char const *s);
void	free_split(char **split);

/* Stack operations */
t_stack	*create_new_node(int value);
void	add_to_stack(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
int		is_stack_sorted(t_stack *stack);

/* Basic operations */
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* Sorting algorithms */
void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	sort_three(t_stack **stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_large(t_stack **stack_a, t_stack **stack_b, int size);

/* Chunk sorting functions */
int		get_chunk_size(int stack_size);
int		get_num_chunks(int stack_size);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int size);
void	push_chunk(t_stack **stack_a, t_stack **stack_b, int start, int end);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);

/* Helper functions for sorting */
int		find_closest_chunk_element(t_stack *stack, int start, int end);
int		find_chunk_element_from_bottom(t_stack *stack, int start, int end);
int		find_best_element_to_push(t_stack *stack_a, t_stack *stack_b);
int		calculate_push_cost(t_stack *stack_a, t_stack *stack_b, int pos_b);
int		get_cost_for_element(int pos_b, t_stack *stack_a, t_stack *stack_b);
int		get_element_index(t_stack *stack, int pos);
void	move_element_to_top_b(t_stack **stack_b, int pos);
void	move_to_target_in_a(t_stack **stack_a, int index_b);
void	move_min_to_top(t_stack **stack_a);

/* Indexing and position helpers */
void	assign_index(t_stack *stack, int size);
void	update_positions(t_stack *stack);
int		find_min_index_position(t_stack *stack);
int		get_target_position(t_stack *stack_a, int index_b);
int		get_lowest_index_position(t_stack *stack);

/* Utility functions */
void	ft_putstr_fd(char *s, int fd);
int		abs_val(int n);
int		min(int a, int b);
char	*ft_strchr(const char *s, int c);

#endif
