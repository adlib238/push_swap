/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:27:01 by kfumiya           #+#    #+#             */
/*   Updated: 2021/06/08 20:17:29 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void
	print_sleep(long k)
{
	long	i;

	i = -1;
	while (++i < k)
		ft_putstr_fd("", 2);
}