/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasbai <sasbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:04:22 by sasbai            #+#    #+#             */
/*   Updated: 2025/06/22 01:05:57 by sasbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_word_len(const char *s, int start)
{
	int	len;

	len = 0;
	while (s[start + len] && s[start + len] != ' ' && s[start + len] != '\t')
		len++;
	return (len);
}

char	**allocate_result(int words)
{
	char	**result;

	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s)
{
	char	**result;
	int		words;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	words = count_words(s);
	result = allocate_result(words);
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && (s[start] == ' ' || s[start] == '\t'))
			start++;
		result[i] = ft_substr(s, start, get_word_len(s, start));
		start += get_word_len(s, start);
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	process_quoted_arg(char *arg, t_stack **stack, int *stack_size)
{
	char	**split;
	int		i;
	int		success;

	split = ft_split(arg);
	if (!split)
		return (0);
	success = 1;
	i = 0;
	while (split[i] && success)
	{
		if (!process_argument(split[i], stack, stack_size))
			success = 0;
		i++;
	}
	free_split(split);
	return (success);
}
