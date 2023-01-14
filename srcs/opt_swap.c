/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 03:20:26 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/22 00:24:25 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool
	dswap(t_dlst *a, t_dlst *b)
{
	if (a->next->next->value == -1 || b->next->next->value == -1)
		return (true);
	swap(a);
	swap(b);
	return (false);
}

bool
	swap(t_dlst *dlst)
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
	return (false);
}
