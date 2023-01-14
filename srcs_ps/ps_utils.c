/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:11:48 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:12:11 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	dlst_update_ans(t_dlst *a, t_dlst *b, t_sort *s)
{
	long	i;

	i = -1;
	while (++i < s->max_turn)
		change_dlst(a, b, s->ans[i], true);
}

bool
	addans(t_ps *ps, t_sort *s)
{
	long	i;

	i = -1;
	while (++i < s->max_turn)
	{
		if (!dlst_addback(ps->ans, s->ans[i]))
			return (false);
	}
	return (true);
}

void
	ans_update(long turn, t_sort *s)
{
	long	i;

	s->max_turn = turn;
	i = -1;
	while (++i < turn)
		s->ans[i] = s->tmp[i];
}

bool
	avoid_opt(long opt, t_sort *s)
{
	if (opt == SA && (s->prev == SA || s->prev == SB || s->prev == SS))
		return (true);
	if (opt == SB && (s->prev == SA || s->prev == SB || s->prev == SS))
		return (true);
	if (opt == SS && (s->prev == SA || s->prev == SB || s->prev == SS))
		return (true);
	if (opt == PA && (s->prev == PB))
		return (true);
	if (opt == PB && (s->prev == PA))
		return (true);
	if (opt == RA && (s->prev == RRA || s->prev == RRR))
		return (true);
	if (opt == RB && (s->prev == RRB || s->prev == RRR))
		return (true);
	if (opt == RR && (s->prev == RRA || s->prev == RRB || s->prev == RRR))
		return (true);
	if (opt == RRA && (s->prev == RA || s->prev == RR))
		return (true);
	if (opt == RRB && (s->prev == RB || s->prev == RR))
		return (true);
	if (opt == RRR && (s->prev == RA || s->prev == RB || s->prev == RR))
		return (true);
	return (false);
}
