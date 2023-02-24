/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:50:38 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/24 01:31:48 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_list
{
	struct s_list	*perv;
	int				number;
	int				position;
	int				tartib;
	int				flag;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int		flag;
	int		position;
	int		*num;
	char	*arr;
	int		first;
	int		i;
	int		size;
	int		pass;
	int		chunk1;
	int		chunk2;
	int		var_split_chunk;
	int		index;
	int		better;
	int		move;
	int		stop;
	int		size_ninc;
	int		size_pinc;
}	t_data;

void	initial_vars(t_list **stack_a, t_list **stack_b, t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);
int		*read_and_check(char **av, t_data *data);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

void	free_all(char **s, size_t i);
void	free_data(t_data *data);

void	check_num(int *num, int j);
void	check_error1(char **av);
void	error_found(void);

void	full_numbers01(char **str, int *num, t_data *data);
int		*full_numbers(char **str, t_data *data);

t_list	*new_node(int x);
t_list	*new_node_p(int x, int y);
void	add_front(t_list **head, t_list *node);
void	delete_node(t_list *node);
void	get_head(t_list **stack_a);
void	get_tail(t_list **stack_a);

void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	get_best_move(t_list **stack_a, t_list **stack_b, t_data *data);
void	push_chunks(t_list **stack_a, t_list **stack_b, t_data *data);

void	start_the_moving_x(t_list **stack_b, t_list **stack_a, t_data *data);
void	start_the_moving_y(t_list **stack_b, t_list **stack_a, t_data *data);
void	big_element(t_list **stack_b, t_data *data);
void	get_data_back_sorted(t_list **stack_b, t_list **stack_a, t_data *data);

void	split_chunks(t_data *data);
void	put_positions(t_list **stack_a, t_data *data);
int		chunks_per_size(t_data *data);
void	list_of_nodes(t_list **head, t_data *data);

int		check_position(t_list **stack_a, int chunk);
void	check_stack_a(t_list **stack_a);

void	put_positions(t_list **stack_a, t_data *data);
void	put_p2(t_list **stack_a, t_data *data, int tmp);
int		first_time(t_list **stack_a);
int		small_calcul(t_list **stack_a, t_data *data);
void	set_up_stack_a(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a, t_data *data);
void	sort_2(t_list **stack_a);
int		better_move(t_list **stack_a, t_list **stack_b, t_data *data);
void	calcul(t_data *data);
void	better_element(t_list **stack_b, t_list **stack_a, t_data *data);
void	do_it(t_list **stack_a, t_list **stack_b, t_data *data);

void	read_her_doc(t_list **stack_a, t_list **stack_b, t_data *data);
void	make_instructions(t_list **stack_a, t_list **stack_b, int i);
int		check_the_instruction(char *str);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	sort_3_continue(t_list **stack_a, t_data *data);

#endif