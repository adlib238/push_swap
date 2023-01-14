/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over7_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:24:41 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:42:45 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool
	disturb_opt(t_dlst *a, long opt, t_sort *s)
{
	if (opt == SA && (a->next->next->value >= s->fin))
		return (true);
	if (opt == SS && (a->next->next->value >= s->fin))
		return (true);
	if (opt == RA && (a->next->value >= s->fin))
		return (true);
	if (opt == RR && (a->next->value >= s->fin))
		return (true);
	return (false);
}

bool
	breq_left(t_dlst *b, t_ps *ps)
{
	t_dlst	*tmp;
	long	begin;

	begin = b->value;
	tmp = b->next;
	while (tmp->value != begin)
	{
		if (tmp->value == ps->breq)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool
	breq_keep(t_dlst *b, t_ps *ps, t_dlst *a)
{
	ps->breq++;
	if (b->prev->value == ps->breq)
		ps->breq++;
	rotate_addans(b, ps, RB, a);
	return (false);
}

void
	partition_half(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;
	long	b_size;

	i = -1;
	b_size = 0;
	while (++i < ps->size && b_size < ps->size / 2)
	{
		while (b->next->value == ps->breq)
			if (breq_keep(b, ps, a))
				break ;
		if (b->next->value == ps->breq + 1 && !breq_left(b, ps) && b_size > 1)
			rotate_addans(b, ps, RB, a);
		if (a->next->value < (ps->size / 2))
		{
			push_addans(b, a, ps, PB);
			b_size++;
		}
		else
			rotate_addans(a, ps, RA, b);
	}
}
