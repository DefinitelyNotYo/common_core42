/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:56:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 18:18:07 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct s_stack
{
	long long		content;
	int				index;
	struct s_stack	*next;
}	t_stack;

void		sort_exe_dis_case_1(t_stack **a, t_stack **b, int *cost_a);
void		sort_exe_dis_case_2(t_stack **a, t_stack **b, int *cost_b);

void		first_sort(t_stack **s);
void		sort_three(t_stack **s);
int			check_stack(t_stack **s);
void		push_foreplay(t_stack **a, t_stack **b);

void		push_from_to(t_stack **a, t_stack **b, int toggle);
void		swap(t_stack **s, int toggle);
void		rotate(t_stack **s, int toggle);
void		reverse_rotate(t_stack **s, int toggle);
t_stack		*ft_lastnode(t_stack **s, int toggle);

void		combo_reverse_rotate(t_stack **a, t_stack **b);
void		combo_rotate(t_stack **a, t_stack **b);

int			is_number(char *str);
int			check_overflows(long long n);
int			check_duplicates(t_stack **s);
int			parsing(t_stack **s, char *str);
void		fix_sorting(t_stack **s, int index);

void		sort_exe_pos_case_1(\
			t_stack **a, t_stack **b, int cost_a, int cost_b);
void		sort_exe_pos_case_2(\
			t_stack **a, t_stack **b, int cost_a, int cost_b);
void		sort_exe_neg_case_1(\
			t_stack **a, t_stack **b, int cost_a, int cost_b);
void		sort_exe_neg_case_2(\
			t_stack **a, t_stack **b, int cost_a, int cost_b);

void		ft_sorting(t_stack **a, t_stack **b);
int			*find_indexs(\
			t_stack **a, t_stack **b, int *a_c, int *b_c);
int			pair_cost(int index_a, int index_b, int *a_costs, int *b_costs);
void		sort_exe(t_stack **a, t_stack **b, int cost_a, int cost_b);

t_stack		*ft_newnode(long long content);
int			ft_stacksize(t_stack *stk);
void		ft_add_node(t_stack **stk, t_stack *new);
// void		ft_show_stack(t_stack **stk);
void		ft_clean_stack(t_stack **stk);

int			split_v2(char *str, t_stack **s);
int			split_exe(char *str, t_stack **s, int i, int j);

void		update_costs(\
			t_stack **a, t_stack **b, int **a_costs, int **b_costs);
void		update_indexs(t_stack **a, t_stack **b);

void		*ft_calloc(size_t nmemb, size_t size);
long long	ft_atoi(const char *nptr);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strlen(const char *s);
// void		ft_putnbr(long long n);
int			ft_abs(int n);

int			find_min_from_max(t_stack **a, t_stack *node_b);
int			find_min(t_stack **a);

void		ft_pushswap(t_stack **a, t_stack **b);
int			ft_sorted_stack(t_stack **s);
#endif