/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 03:28:22 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/24 21:18:00 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool
	drotate(t_dlst *a, t_dlst *b)
{
	if (a->next->next->value == -1 || b->next->next->value == -1)
		return (true);
	rotate(a);
	rotate(b);
	return (false);
}

bool
	rotate(t_dlst *dlst)
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
	return (false);
}
