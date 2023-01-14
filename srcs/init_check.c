/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 03:49:53 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/13 19:07:16 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool
	init_check(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (!b)
		exit(check_dlst_err(a, b, ps));
	if (a->next->value == -1)
	{
		(all_free(a, b, ps));
		return (false);
	}
	return (true);
}
