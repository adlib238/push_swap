/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:26:21 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/24 21:18:19 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	ps_swap(t_pair *a, t_pair *b)
{
	long	tmp_key;
	long	tmp_value;

	tmp_key = a->key;
	tmp_value = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = tmp_key;
	b->value = tmp_value;
}

long
	partition_value(t_pair n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (i < j && n[++i].value < n[pivot].value)
			;
		while (j && n[pivot].value < n[--j].value)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

long
	partition_key(t_pair n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (n[++i].key < n[pivot].key)
			;
		while (n[pivot].key < n[--j].key)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

void
	quick_sort(t_pair n[], long left, long right, long flag)
{
	long	pivot;

	if (left < right)
	{
		if (flag == SORT_VALUE)
			pivot = partition_value(n, left, right);
		if (flag == SORT_KEY)
			pivot = partition_key(n, left, right);
		quick_sort(n, left, pivot - 1, flag);
		quick_sort(n, pivot + 1, right, flag);
	}
}
