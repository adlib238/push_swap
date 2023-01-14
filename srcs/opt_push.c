/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 03:08:31 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/21 23:55:19 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool
	push(t_dlst *a, t_dlst *b)
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
	return (false);
}
