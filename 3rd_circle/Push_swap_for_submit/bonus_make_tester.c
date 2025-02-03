/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_make_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/03 21:14:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

int check_list_is_sorted(t_list *lst)
{
	int		ans;
	int		temp;
	t_list	*check;

	ans = 1;
	if (lst == NULL)
		return (ans);
	temp = lst->content; 
	check = lst->next;
	while (check != NULL)
	{
		check = check->next;
		if((check->content) <= temp)
			ans = -1;
	}
	return (ans);
}

int check_list_is_ok(t_list **a,t_list **b)
{
	if(ft_lstsize(*b) != 0)
		return (-1);
	if(check_list_is_sorted(*a) == 1)
		return (1);
	else
		return (-1);
}

void exec_command(int com_num,t_list **a,t_list **b)
{
	if(com_num == 0) sa(a,0);
	if(com_num == 1) sb(b,0);
	if(com_num == 2) ss(a,b);
	if(com_num == 3) pb(a,b,);
	if(com_num == 4) pa(a,b,);
	if(com_num == 5) ra(a,0);
	if(com_num == 6) rb(b,0);
	if(com_num == 7) rr(a,b);
	if(com_num == 8) rra(a,0);
	if(com_num == 9) rrb(b,0);
	if(com_num == 10) rrr(a,b);

}


int check_command_number(char *line)
{
	int i;
	const int line_len = ft_strlen(line);
	char **command;
	command = malloc(sizeof(char **) * 11);

	command[0] = "sa";
    command[1] = "sb";
    command[2] = "ss";
	command[3] = "pb";
    command[4] = "pa";
    command[5] = "ra";
	command[6] = "rb";
    command[7] = "rr";
    command[8] = "rra";
	command[9] = "rrb";
    command[10] = "rrr";
	
	i = 0;
	while(i < 11)
	{
		if(line_len == strlen(command[i]))
		{
			if(ft_strncmp(line, command[i], line_len) == 0)
				return (i);
		}
		i++;		
	}
	free(command);
	return (-1);
}


int tester_main_process(t_list **a, t_list **b)
{
	char *line;
	int com_num;

	line = get_next_line(STDIN_FILENO);
	while(line != NULL)
	{
		com_num = check_command_number(line);
		if(com_num != -1)
		{
			exec_command(com_num,a,b);
		}
		else
		{
			ft_printf("Error\n");
			return (-1);
		}
	}
	if(check_list_is_ok(a,b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}


static void	print_error()
{
	const char	*str = "Error\n";

	write(STDERR_FILENO, str, ft_strlen(str));
	return ;
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = malloc(sizeof(t_list **));
	b = malloc(sizeof(t_list **));
	if (a == NULL || b == NULL ) print_error();
	if (argc == 1) return (0);
	if (check_input(argc, argv) == -1)
	{
		print_error();
		return (-1);
	}
	*a = pushtostack_and_checkoverlap(argc, argv);
	if (*a == NULL)
	{
		print_error();
		free(a);
		free(b);
		return (-1);
	}
	tester_main_process(a, b);
	free(a);
	free(b);
	return (0);
}

