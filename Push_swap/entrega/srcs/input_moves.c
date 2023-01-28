/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:09 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/24 10:14:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	def_arr_mov_func(void **move_func)
{
	move_func[0] = sa;
	move_func[1] = sb;
	move_func[2] = ss;
	move_func[3] = ra;
	move_func[4] = rb;
	move_func[5] = rr;
	move_func[6] = rra;
	move_func[7] = rrb;
	move_func[8] = rrr;
	move_func[9] = pa;
	move_func[10] = pb;
	return ;
}

char	**def_arr_mov_names(void)
{
	int		i;
	char	**move_names;
	char	*str;

	str = (char *) malloc(57 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "sa\n sb\n ss\n ra\n rb\n rr\n rra\n rrb\n rrr\n pa\n pb\n", 57);
	move_names = ft_split(str, ' ');
	return (move_names);
}

int	make_move(int (*move)(t_stack **, int), t_stack **stacks, int print_move)
{
	return (move(stacks, print_move));
}

int	sel_mov2exec(t_stack **stacks, void **move_func, char **data_moves, int prt)
{
	int		es_ok;
	int		i;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		i = -1;
		es_ok = 0;
		while (++i < NBR_MOVES)
		{
			if (!ft_strncmp(str, data_moves[i], ft_strlen(data_moves[i])))
			{
				make_move(move_func[i], stacks, prt);
				es_ok = 1;
				break ;
			}
		}
		if (es_ok == 0)
			return (1);
		str = get_next_line(0);
	}
	free(str);
	return (0);
}

int	input_moves(t_stack **stacks, int prt)
{
	int		es_ok;
	char	**data_moves;
	void	*move_func[11];

	def_arr_mov_func(move_func);
	data_moves = def_arr_mov_names();
	if (!data_moves)
		return (0);
	es_ok = sel_mov2exec(stacks, move_func, data_moves, prt);
	free_double_point(data_moves);
	return (es_ok);
}
