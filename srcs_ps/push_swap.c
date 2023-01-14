/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:05:42 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/13 19:06:42 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	opt_export(long opt)
{
	if (opt == SA)
		ft_putstr_fd("sa", 1);
	if (opt == SB)
		ft_putstr_fd("sb", 1);
	if (opt == SS)
		ft_putstr_fd("ss", 1);
	if (opt == PA)
		ft_putstr_fd("pa", 1);
	if (opt == PB)
		ft_putstr_fd("pb", 1);
	if (opt == RA)
		ft_putstr_fd("ra", 1);
	if (opt == RB)
		ft_putstr_fd("rb", 1);
	if (opt == RR)
		ft_putstr_fd("rr", 1);
	if (opt == RRA)
		ft_putstr_fd("rra", 1);
	if (opt == RRB)
		ft_putstr_fd("rrb", 1);
	if (opt == RRR)
		ft_putstr_fd("rrr", 1);
}

void
	ans_print(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		opt_export(tmp->value);
		tmp = tmp->next;
		ft_putstr_fd("\n", 1);
	}
}

void
	push_swap(long ac, char **av)
{
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;

	ps = ps_init(ac, av);
	a = make_dlst(ps);
	b = dlst_def();
	if (!a || !b)
		exit(check_dlst_err(a, b, ps));
	if (a->next->value == -1)
		return (all_free(a, b, ps));
	else if (is_sorted(a))
		;
	else if (ps->size < 7)
		sort_under6(a, b, ps);
	else
		sort_over7(a, b, ps);
	ans_replace(ps->ans);
	ans_cut(ps->ans);
	ans_print(ps->ans);
	all_free(a, b, ps);
}

int
	main(int ac, char **av)
{
	if (ac > AR_LIMIT)
		exit(ar_err());
	else
		push_swap(ac, av);
	return (0);
}
