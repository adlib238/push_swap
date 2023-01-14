/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:03 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/13 19:05:24 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void
	print_judge(t_dlst *a, t_dlst *b)
{
	if (is_sorted(a) && b->next->value == -1)
		ps_ok();
	else
		ps_ko();
}

static long
	get_option(char *line)
{
	if (!(ft_strncmp("sa", line, 3)))
		return (SA);
	if (!(ft_strncmp("sb", line, 3)))
		return (SB);
	if (!(ft_strncmp("ss", line, 3)))
		return (SS);
	if (!(ft_strncmp("pa", line, 3)))
		return (PA);
	if (!(ft_strncmp("pb", line, 3)))
		return (PB);
	if (!(ft_strncmp("ra", line, 3)))
		return (RA);
	if (!(ft_strncmp("rb", line, 3)))
		return (RB);
	if (!(ft_strncmp("rr", line, 3)))
		return (RR);
	if (!(ft_strncmp("rra", line, 4)))
		return (RRA);
	if (!(ft_strncmp("rrb", line, 4)))
		return (RRB);
	if (!(ft_strncmp("rrr", line, 4)))
		return (RRR);
	return (ERR_FLAG);
}

static void
	line_operate(t_dlst *a, t_dlst *b, char *line, t_ps *ps)
{
	print_sleep(42);
	if (*line)
	{
		if (get_option(line) == ERR_FLAG)
			exit(ch_err(a, b, line, ps));
		change_dlst(a, b, get_option(line), true);
		ps->ans_turn++;
	}
	free(line);
}

void
	checker(int ac, char **av)
{
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;
	long	ret;
	char	*line;

	ps = ps_init(ac, av);
	a = make_dlst(ps);
	b = dlst_def();
	if (!a || !b || is_sorted(a))
		exit(check_dlst_err(a, b, ps));
	while (42)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			break ;
		line_operate(a, b, line, ps);
		if (!ret)
			break ;
	}
	if (ret < 0)
		exit(checker_err(a, b, ps));
	print_judge(a, b);
	all_free(a, b, ps);
}

int
	main(int ac, char **av)
{
	if (ac > AR_LIMIT)
		exit(ar_err());
	else
		checker(ac, av);
	return (0);
}
