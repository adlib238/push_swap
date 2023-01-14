/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:50:06 by kfumiya           #+#    #+#             */
/*   Updated: 2021/10/13 19:04:52 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define STDERR		2
# define ERR_FLAG	2147483648

# define SORT_VALUE	0
# define SORT_KEY	1
# define SORT_SIZE	4
# define INT_MAX	INT32_MAX
# define INT_MIN	INT32_MIN
# define SORTLIMIT_U_6 12
# define SORTLIMIT_O_7 42
# define AR_LIMIT	1001

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

typedef struct s_dlst
{
	long			value;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}	t_dlst;

typedef struct s_pair
{
	long	key;
	long	value;
}	t_pair;

typedef struct s_ps
{
	t_dlst	*ans;
	t_pair	n[AR_LIMIT + 10];
	long	def[AR_LIMIT + 10];
	long	size;
	long	areq;
	long	breq;
	long	ans_turn;
}	t_ps;

typedef struct s_sort
{
	long	max_turn;
	long	turn;
	long	size;
	long	tmp[SORTLIMIT_O_7 + 10];
	long	ans[SORTLIMIT_O_7 + 10];
	long	prev;
	long	areq;
	long	fin;
}	t_sort;

void				push_swap(long ac, char **av);
void				sort_under6(t_dlst *a, t_dlst *b, t_ps *ps);
void				dfs(t_dlst *a, t_dlst *b, t_sort *s, long turn);
bool				addans(t_ps *ps, t_sort *s);
void				dlst_update_ans(t_dlst *a, t_dlst *b, t_sort *s);
bool				change_dlst(t_dlst *a, t_dlst *b, long opt, bool exec);
long				recover(long opt);
void				ans_update(long turn, t_sort *s);
bool				avoid_opt(long opt, t_sort *s);
bool				breq_left(t_dlst *b, t_ps *ps);
bool				breq_keep(t_dlst *b, t_ps *ps, t_dlst *a);
void				sort_over7(t_dlst *a, t_dlst *b, t_ps *ps);
void				partition_half(t_dlst *a, t_dlst *b, t_ps *ps);
void				b_adjust(t_dlst *a, t_dlst *b, t_ps *ps);
void				b_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size);
long				a_dlist_size(t_dlst *a, t_ps *ps);
void				allsort(t_dlst *a, t_dlst *b, t_ps *ps, long size);
long				fin_b_search(t_dlst *a, t_dlst *b, t_ps *ps);
void				allsort_dfs(t_dlst *a, t_dlst *b, t_sort *s, long turn);
void				allsort_a_adjust(t_dlst *a, t_dlst *b,
						t_sort *s, long turn);
void				allsort_b_adjust(t_dlst *a, t_dlst *b,
						t_sort *s, long turn);
bool				disturb_opt(t_dlst *a, long opt, t_sort *s);
void				ans_replace(t_dlst *ans);
void				dlst_replace(t_dlst *ans, long opt);
void				ans_cut(t_dlst *ans);
t_dlst				*dlst_delone(t_dlst *dlst);
t_dlst				*make_dlst(t_ps *ps);
t_dlst				*dlst_def(void);
bool				dlst_addback(t_dlst *dlst, long value);
long				dlst_size(t_dlst *dlst);
t_ps				*ps_init(long ac, char **av);
void				ps_value_init(t_ps *ps, char **av);
long				ps_atoi(char *str);
long				ar_err(void);
void				ps_ok(void);
void				ps_ko(void);
void				all_free(t_dlst *a, t_dlst *b, t_ps *ps);
void				dlst_clear(t_dlst *a);
void				ps_swap(t_pair *a, t_pair *b);
long				partition_value(t_pair n[], long left, long right);
long				partition_key(t_pair n[], long left, long right);
void				quick_sort(t_pair n[], long left, long right, long flag);
bool				is_sorted(t_dlst *dlst);
void				print_sleep(long k);
bool				swap(t_dlst *dlst);
bool				push(t_dlst *a, t_dlst *b);
bool				rotate(t_dlst *dlst);
bool				r_rotate(t_dlst *dlst);
bool				dswap(t_dlst *a, t_dlst *b);
bool				drotate(t_dlst *a, t_dlst *b);
bool				dr_rotate(t_dlst *a, t_dlst *b);
void				checker(int argc, char **argv);
bool				check_is_num(char *str);
long				init_err(t_ps *ps);
void				init_free(t_ps *ps);
long				ch_err(t_dlst *a, t_dlst *b, char *line, t_ps *ps);
void				ch_free(t_dlst *a, t_dlst *b, char *line, t_ps *ps);
long				checker_err(t_dlst *a, t_dlst *b, t_ps *ps);
long				ps_err(t_dlst *a, t_dlst *b, t_ps *ps);
bool				init_check(t_dlst *a, t_dlst *b, t_ps *ps);
long				check_dlst_err(t_dlst *a, t_dlst *b, t_ps *ps);
void				def_free(t_dlst *a, t_ps *ps);
bool				swap_addans(t_dlst *dlst, t_ps *ps,
						long opt, t_dlst *sub_dlst);
bool				rotate_addans(t_dlst *dlst, t_ps *ps,
						long opt, t_dlst *sub_dlst);
bool				push_addans(t_dlst *a, t_dlst *b,
						t_ps *ps, long opt);
bool				r_rotate_addans(t_dlst *dlst, t_ps *ps,
						long opt, t_dlst *sub_dlst);
#endif
