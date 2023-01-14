/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:38:46 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/13 19:06:02 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long
	checker_err(t_dlst *a, t_dlst *b, t_ps *ps)
{
	all_free(a, b, ps);
	ft_putstr_fd("Error\n", STDERR);
	return (EXIT_FAILURE);
}

long
	ar_err(void)
{
	ft_putstr_fd("Error\n", STDERR);
	return (EXIT_FAILURE);
}

long
	check_dlst_err(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (!a || !b)
	{
		def_free(a, ps);
		ft_putstr_fd("Error\n", STDERR);
		return (EXIT_FAILURE);
	}
	else
	{
		all_free(a, b, ps);
		return (EXIT_FAILURE);
	}
}
