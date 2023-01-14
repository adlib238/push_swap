/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:11:50 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:44:48 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	a_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;

	i = -1;
	while (++i < size)
	{
		if (b->prev->value == ps->areq)
			r_rotate_addans(b, ps, RRB, a);
		if (b->next->next->value == ps->areq)
			swap_addans(b, ps, SB, a);
		if (b->next->value == ps->areq && (--i || 1))
			push_addans(a, b, ps, PA);
		if (a->next->next->value == ps->areq
			&& a->next->value == ps->areq + 1)
			swap_addans(a, ps, SA, b);
		if (a->next->value == ps->areq)
		{
			rotate_addans(a, ps, RA, b);
			++ps->areq;
		}
		else
			push_addans(b, a, ps, PB);
	}
}

long
	a_dlist_size(t_dlst *a, t_ps *ps)
{
	t_dlst	*tmp;
	long	size;
	long	max;

	tmp = a->next;
	size = 0;
	max = -AR_LIMIT - 10;
	while (max - ps->areq + 1 != size && tmp->value)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void
	b_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	pivot;
	long	i;

	pivot = ps->areq + (size - 1) / 2;
	i = -1;
	while (++i < size)
	{
		if (b->next->value == ps->areq && ++ps->areq)
		{
			push_addans(a, b, ps, PA);
			rotate_addans(a, ps, RA, b);
		}
		else if (b->next->value > pivot)
			push_addans(a, b, ps, PA);
		else
			rotate_addans(b, ps, RB, a);
	}
}

void
	b_adjust(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;

	i = -1;
	while (++i + ps->areq < ps->breq)
	{
		if (b->prev->value == ps->breq - i - 1)
			r_rotate_addans(b, ps, RRB, a);
		else if (b->prev->prev->value == ps->breq - i - 1)
		{
			r_rotate_addans(b, ps, RRB, a);
			r_rotate_addans(b, ps, RRB, a);
		}
		if (b->next->value == ps->breq - i - 1)
			push_addans(a, b, ps, PA);
	}
	while (a->next->value == ps->areq)
	{
		rotate_addans(a, ps, RA, b);
		ps->areq++;
	}
}

void
	sort_over7(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;

	partition_half(a, b, ps);
	while (ps->areq != ps->size)
	{
		b_adjust(a, b, ps);
		size = dlst_size(b);
		while (size > SORT_SIZE)
		{
			b_quick_sort(a, b, ps, size);
			size = dlst_size(b);
		}
		if (size)
			allsort(a, b, ps, size);
		size = a_dlist_size(a, ps);
		while ((a_dlist_size(a, ps)) && size <= SORT_SIZE)
		{
			allsort(a, b, ps, size);
			size = a_dlist_size(a, ps);
		}
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}
