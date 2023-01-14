/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:39:19 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/04 03:35:56 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	ps_ko(void)
{
	ft_putstr_fd("KO", 1);
	ft_putstr_fd("\n", 1);
}

void
	ps_ok(void)
{
	ft_putstr_fd("OK", 1);
	ft_putstr_fd("\n", 1);
}

long
	ps_err(t_dlst *a, t_dlst *b, t_ps *ps)
{
	all_free(a, b, ps);
	ft_putstr_fd("Error\n", STDERR);
	return (EXIT_FAILURE);
}

long
	init_err(t_ps *ps)
{
	init_free(ps);
	ft_putstr_fd("Error\n", STDERR);
	return (EXIT_FAILURE);
}

long
	ch_err(t_dlst *a, t_dlst *b, char *line, t_ps *ps)
{
	ch_free(a, b, line, ps);
	ft_putstr_fd("Error\n", STDERR);
	return (EXIT_FAILURE);
}
