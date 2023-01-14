/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:26:13 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/06 09:03:32 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long
	dlst_size(t_dlst *dlst)
{
	long	size;
	t_dlst	*tmp;

	size = 0;
	tmp = dlst->next;
	while (tmp->value != -1)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

bool
	dlst_addback(t_dlst *dlst, long value)
{
	t_dlst	*new;
	t_dlst	*ptmp;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (false);
	new->value = value;
	ptmp = dlst->prev;
	ptmp->next = new;
	new->next = dlst;
	dlst->prev = new;
	new->prev = ptmp;
	return (true);
}

t_dlst
	*dlst_def(void)
{
	t_dlst	*dlst;

	dlst = (t_dlst *)malloc(sizeof(t_dlst));
	if (!dlst)
		return (NULL);
	dlst->value = -1;
	dlst->next = dlst;
	dlst->prev = dlst;
	return (dlst);
}

t_dlst
	*make_dlst(t_ps *ps)
{
	t_dlst	*dlst;
	long	i;

	dlst = dlst_def();
	if (!dlst)
		exit(init_err(ps));
	i = -1;
	while (++i < ps->size)
		if (!dlst_addback(dlst, ps->n[i].value))
			return (NULL);
	return (dlst);
}
