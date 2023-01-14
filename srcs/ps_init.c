/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:10:10 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/04 02:59:32 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void
	value_check(t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(init_err(ps));
	}
}

static void
	change_val_to_key(t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size)
	{
		ps->def[i] = ps->n[i].value;
		ps->n[i].value = i;
	}
}

long
	ps_atoi(char *str)
{
	long	sign;
	long	num;
	long	res;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	res = check_is_num(str);
	if (!res)
		return (ERR_FLAG);
	res = 0;
	while (ft_isdigit(*str))
	{
		num = (*str++ - '0');
		res = res * 10 + sign * num;
		if (res < INT_MIN || INT_MAX < res)
			return (ERR_FLAG);
	}
	return (res);
}

void
	ps_value_init(t_ps *ps, char **av)
{
	long	i;
	char	**strs;
	long	num;

	strs = av + 1;
	i = -1;
	while (++i < ps->size)
	{
		ps->n[i].key = i;
		num = ps_atoi(*strs);
		if (num > INT_MAX)
			exit(init_err(ps));
		else
			ps->n[i].value = num;
		strs++;
	}
	--i;
	while (++i < AR_LIMIT)
	{
		ps->n[i].key = i;
		ps->n[i].value = 0;
	}
}

t_ps
	*ps_init(long ac, char **av)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		exit(ar_err());
	ps->areq = 0;
	ps->breq = 0;
	ps->ans = dlst_def();
	if (!ps->ans)
		exit(init_err(ps));
	ps->size = ac - 1;
	ps->ans_turn = 0;
	ps_value_init(ps, av);
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	value_check(ps);
	change_val_to_key(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_KEY);
	return (ps);
}
