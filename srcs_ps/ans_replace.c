/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 05:32:41 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/24 21:21:14 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst
	*dlst_delone(t_dlst *dlst)
{
	t_dlst	*prev;
	t_dlst	*next;

	prev = dlst->prev;
	next = dlst->next;
	free(dlst);
	prev->next = next;
	next->prev = prev;
	return (next);
}

void
	ans_cut(t_dlst *ans)
{
	t_dlst	*tmp;
	bool	del;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		del = false;
		if (tmp->value == PA && tmp->next->value == PB)
			del = true;
		if (tmp->value == PB && tmp->next->value == PA)
			del = true;
		if (del)
		{
			tmp = dlst_delone(tmp);
			tmp = dlst_delone(tmp);
			tmp = tmp->prev->prev;
		}
		tmp = tmp->next;
	}
}

void
	dlst_replace(t_dlst *ans, long opt)
{
	t_dlst	*tmp;

	tmp = ans->next->next;
	free(ans->next);
	ans->next = NULL;
	ans->value = opt;
	ans->next = tmp;
	tmp->prev = ans;
}

void
	ans_replace(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		if (tmp->value == SA && tmp->next->value == SB)
			dlst_replace(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			dlst_replace(tmp, SS);
		if (tmp->value == RA && tmp->next->value == RB)
			dlst_replace(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			dlst_replace(tmp, RR);
		if (tmp->value == RRA && tmp->next->value == RRB)
			dlst_replace(tmp, RR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			dlst_replace(tmp, RRR);
		tmp = tmp->next;
	}
}
