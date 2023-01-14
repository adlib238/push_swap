/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:00:31 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:46:33 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	dfs(t_dlst *a, t_dlst *b, t_sort *s, long turn)
{
	long	opt;

	if (turn >= s->max_turn)
		return ;
	if (b->next->value == -1 && is_sorted(a))
		return (ans_update(turn, s));
	opt = -1;
	while (++opt < 11)
	{
		if (avoid_opt(opt, s) || turn >= s->max_turn)
			continue ;
		if (change_dlst(a, b, opt, true))
			continue ;
		s->prev = opt;
		s->tmp[turn] = opt;
		dfs(a, b, s, turn + 1);
		change_dlst(a, b, opt, false);
	}
}

void
	sort_under6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_sort		s;
	long		i;

	s.max_turn = SORTLIMIT_U_6;
	i = -1;
	while (++i < SORTLIMIT_U_6)
	{
		s.tmp[i] = -1;
		s.ans[i] = -1;
	}
	s.prev = -1;
	dfs(a, b, &s, 0);
	if (!addans(ps, &s))
		exit(ps_err(a, b, ps));
	dlst_update_ans(a, b, &s);
}
