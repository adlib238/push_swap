/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:19:02 by kfumiya           #+#    #+#             */
/*   Updated: 2021/05/21 23:40:48 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long
	recover(long opt)
{
	if (opt == PA)
		return (PB);
	if (opt == PB)
		return (PA);
	if (opt == RA)
		return (RRA);
	if (opt == RB)
		return (RRB);
	if (opt == RR)
		return (RRR);
	if (opt == RRA)
		return (RA);
	if (opt == RRB)
		return (RB);
	if (opt == RRR)
		return (RR);
	return (opt);
}

bool
	change_dlst(t_dlst *a, t_dlst *b, long opt, bool exec)
{
	if (!exec)
		opt = recover(opt);
	if (opt == SA)
		return (swap(a));
	if (opt == SB)
		return (swap(b));
	if (opt == SS)
		return (dswap(a, b));
	if (opt == PA)
		return (push(a, b));
	if (opt == PB)
		return (push(b, a));
	if (opt == RA)
		return (rotate(a));
	if (opt == RB)
		return (rotate(b));
	if (opt == RR)
		return (drotate(a, b));
	if (opt == RRA)
		return (r_rotate(a));
	if (opt == RRB)
		return (r_rotate(b));
	if (opt == RRR)
		return (dr_rotate(a, b));
	return (true);
}
