/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 03:39:26 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/22 00:21:18 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool
	dr_rotate(t_dlst *a, t_dlst *b)
{
	if (a->next->next->value == -1 || b->next->next->value == -1)
		return (true);
	r_rotate(a);
	r_rotate(b);
	return (false);
}

bool
	r_rotate(t_dlst *dlst)
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
	return (false);
}
