/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:40:58 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/04 03:58:03 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	dlst_clear(t_dlst *a)
{
	t_dlst	*tmp;

	a->prev->next = NULL;
	while (a)
	{
		tmp = a->next;
		a->prev = NULL;
		free(a);
		a = tmp;
	}
}

void
	ch_free(t_dlst *a, t_dlst *b, char *line, t_ps *ps)
{
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
	free(line);
}

void
	init_free(t_ps *ps)
{
	dlst_clear(ps->ans);
	free(ps);
}

void
	def_free(t_dlst *a, t_ps *ps)
{
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
}

void
	all_free(t_dlst *a, t_dlst *b, t_ps *ps)
{
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
