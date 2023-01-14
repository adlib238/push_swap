/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_addans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:04:54 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:49:09 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool
	swap_addans(t_dlst *dlst, t_ps *ps, long opt, t_dlst *sub_dlst)
{
	t_dlst	*tmp1;
	t_dlst	*tmp2;
	t_dlst	*tmp3;

	if (dlst->next->next->value == -1)
		return (true);
	tmp1 = dlst->next;
	tmp2 = dlst->next->next;
	tmp3 = dlst->next->next->next;
	dlst->next = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = dlst;
	if (!dlst_addback(ps->ans, opt))
		exit(ps_err(dlst, sub_dlst, ps));
	return (false);
}

bool
	rotate_addans(t_dlst *dlst, t_ps *ps, long opt, t_dlst *sub_dlst)
{
	t_dlst	*tmp1;
	t_dlst	*tmp2;
	t_dlst	*tmp3;

	if (dlst->next->next->value == -1)
		return (true);
	tmp1 = dlst->prev;
	tmp2 = dlst->next;
	tmp3 = dlst->next->next;
	dlst->next = tmp3;
	tmp3->prev = dlst;
	dlst->prev = tmp2;
	tmp2->prev = tmp1;
	tmp1->next = tmp2;
	tmp2->next = dlst;
	if (!dlst_addback(ps->ans, opt))
		exit(ps_err(dlst, sub_dlst, ps));
	return (false);
}

bool
	push_addans(t_dlst *a, t_dlst *b, t_ps *ps, long opt)
{
	t_dlst	*atmp;
	t_dlst	*btmp1;
	t_dlst	*btmp2;

	if (b->next->value == -1)
		return (true);
	atmp = a->next;
	btmp1 = b->next;
	btmp2 = b->next->next;
	b->next = btmp2;
	btmp2->prev = b;
	a->next = btmp1;
	btmp1->next = atmp;
	atmp->prev = btmp1;
	btmp1->prev = a;
	if (!dlst_addback(ps->ans, opt))
		exit(ps_err(a, b, ps));
	return (false);
}

bool
	r_rotate_addans(t_dlst *dlst, t_ps *ps, long opt, t_dlst *sub_dlst)
{
	t_dlst	*tmp1;
	t_dlst	*tmp2;
	t_dlst	*tmp3;

	if (dlst->next->next->value == -1)
		return (true);
	tmp1 = dlst->prev->prev;
	tmp2 = dlst->prev;
	tmp3 = dlst->next;
	dlst->next = tmp2;
	tmp2->next = tmp3;
	tmp3->prev = tmp2;
	tmp2->prev = dlst;
	dlst->prev = tmp1;
	tmp1->next = dlst;
	if (!dlst_addback(ps->ans, opt))
		exit(ps_err(dlst, sub_dlst, ps));
	return (false);
}
