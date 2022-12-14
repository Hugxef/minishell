/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:33:19 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 16:33:20 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Return the index of the n-th occurence of the
	given search in the given str
*/
int	index_of(char *str, char *search, int n)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		if (ft_strncmp(str + cur, search, ft_strlen(search)) == 0)
			n--;
		if (n <= 0)
			return (cur);
		cur++;
	}
	return (cur);
}

/*
	Return NEXT_PIPE, NEXT_AND, NEXT_OR, NEXT_END or NEXT_CONTINUE
	depending of the value of str (|, &&, ||, ; or someting else)
*/
int	get_arg_type(char *str)
{
	if (!strcmp_len(str, "|"))
		return (NEXT_PIPE);
	if (!strcmp_len(str, "&&"))
		return (NEXT_AND);
	if (!strcmp_len(str, "||"))
		return (NEXT_OR);
	if (!strcmp_len(str, ";"))
		return (NEXT_CONTINUE);
	return (NEXT_END);
}

/*
	Return 1 when str is a separator
	A separator can be : |, &, ||, &&, >, >>, <, <<, ;
*/
int	is_sep(char *str)
{
	if (get_arg_type(str) != 0)
		return (1);
	if (!strcmp_len(str, ">"))
		return (1);
	if (!strcmp_len(str, "<"))
		return (1);
	if (!strcmp_len(str, "<<"))
		return (1);
	if (!strcmp_len(str, ">>"))
		return (1);
	if (!strcmp_len(str, "&"))
		return (1);
	if (!strcmp_len(str, ";"))
		return (1);
	return (0);
}
