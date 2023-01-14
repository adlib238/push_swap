/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:33:14 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:13:40 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	allsort_b_adjust(t_dlst *a, t_dlst *b, t_sort *s, long turn)
{
	push(a, b);
	s->tmp[turn] = PA;
	allsort_dfs(a, b, s, turn + 1);
	push(b, a);
	return ;
}

void
	allsort_a_adjust(t_dlst *a, t_dlst *b, t_sort *s, long turn)
{
	long	opt;

	opt = RA;
	rotate(a);
	s->prev = opt;
	s->tmp[turn] = opt;
	s->areq++;
	allsort_dfs(a, b, s, turn + 1);
	s->areq--;
	r_rotate(a);
	return ;
}

void
	allsort_dfs(t_dlst *a, t_dlst *b, t_sort *s, long turn)
{
	long	opt;

	if (turn >= s->max_turn - (s->fin - s->areq))
		return ;
	if (s->areq >= s->fin && b->next->value == -1)
		return (ans_update(turn, s));
	if (a->next->value == s->areq)
		return (allsort_a_adjust(a, b, s, turn));
	if (b->next->value == s->areq)
		return (allsort_b_adjust(a, b, s, turn));
	opt = -1;
	while (++opt < 11)
	{
		if (avoid_opt(opt, s) || turn >= s->max_turn - 1)
			continue ;
		if (disturb_opt(a, opt, s))
			continue ;
		if (change_dlst(a, b, opt, true))
			continue ;
		s->prev = opt;
		s->tmp[turn] = opt;
		allsort_dfs(a, b, s, turn + 1);
		change_dlst(a, b, opt, false);
	}
}

long
	fin_b_search(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_dlst	*tmpb;
	long	ret;

	ret = ps->areq;
	while (1)
	{
		tmpb = b->next;
		while (ret != tmpb->value && tmpb->value != -1)
			tmpb = tmpb->next;
		if (a->next->value != ret
			&& a->next->next->value != ret
			&& tmpb->value != ret)
			return (ret);
		ret++;
	}
}

void
	allsort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	t_sort	s;
	long	i;

	s.max_turn = SORTLIMIT_O_7;
	i = -1;
	while (++i < SORTLIMIT_O_7)
	{
		s.tmp[i] = -1;
		s.ans[i] = -1;
	}
	s.prev = ps->ans->prev->value;
	s.size = size;
	s.areq = ps->areq;
	if (b->next->value != -1)
		s.fin = fin_b_search(a, b, ps);
	else
		s.fin = size + ps->areq;
	allsort_dfs(a, b, &s, 0);
	if (!addans(ps, &s))
		exit(ps_err(a, b, ps));
	dlst_update_ans(a, b, &s);
	ps->areq = s.fin;
	ps->breq = s.fin;
}
