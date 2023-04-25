/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:52:02 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:58:18 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				move;
	struct s_list	*next;
}		t_list;

void	radix(int *stacks, int *sep);
void	push_it_back(int *sep, t_list **soluce);
void	apply_this_round(int *stacks, int *sep, t_list **soluce, int bit);
int		biggest_value(int *stacks);
int		max_nbr_value(int *stacks);
int		*simplify(int *argz);
int		*remaster(int argc, char **argv);
int		compare_limitz_int(char *argv, char *max_int);
int		for_min_int(char *argv, int z, char *min_int);
int		check_arg_in_str(char *argv);
int		check_arg_in_int(int *argz, int z);
int		find_smallest(int *argz);
int		position_of_x(int *argz, int x);
int		*errorz(int argc, char **argv);
void	push(int *sep, int opt);
void	rotate_a(int *pos_tracker, int *sep);
void	rotate_b(int *pos_tracker, int *sep);
void	rr(int *pos_tracker, int *sep);
void	rev_rot_a(int *pos_tracker, int *sep);
void	rev_rot_b(int *pos_tracker, int *sep);
void	rrr(int *pos_tracker, int *sep);
int		ft_strlen(char *str);
void	ft_putchar(char ch);
void	ft_putstr(char *str);
int		last_index(int opt);
t_list	*lstnew(int content);
void	lstadd_back(t_list **head, t_list *nw);
void	broute_force(int *pos_tracker, int *sep);
int		check_soluce(int *pos_tracker, int *sep);
int		*stack_tracker(int *pos_tracker, int opt);
int		security_check(int *sep, int loop, int max_moves);
int		rek_me_daddy(int max_moves, int loop, int prev, int *sep);
int		randomness_optimization(int move, int prev, int *sep, int loop);
int		first_move(int move);
int		possibilityz_sa(int move, int *sep);
int		possibilityz_sb(int move, int *sep);
int		possibilityz_ss(int move, int *sep);
int		possibilityz_ra(int move, int *sep);
int		possibilityz_rb(int move, int *sep);
int		possibilityz_rr(int move, int *sep);
int		possibilityz_rra(int move, int *sep);
int		possibilityz_rrb(int move, int *sep);
int		possibilityz_rrr(int move, int *sep);
int		possibilityz_pa(int move, int *sep);
int		possibilityz_pb(int move, int *sep);
void	reverse_move(int *pos_tracker, int move, int *sep);
void	apply_move(int *pos_tracker, int move, int *sep);
void	swap(int *pos_tracker, int *sep, int opt);
void	print_moves(int move);
void	read_the_book(int *book_of_knowledge);
int		book_of_knowledge(int loop, int move);
int		last_check(int *tab_remastered);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		check_signs(char *argv, int z, int y);
int		check_signs_two(char *argv);
void	print_soluce(t_list *soluce);
void	free_lst(t_list *lst);
int		*exit_error(int *argz);

#endif
