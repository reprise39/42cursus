/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_make_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 16:35:34 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"
#include "../get_next_line.h"

int check_list_is_sorted(t_list *lst)
{
	int		temp;
	t_list	*check;

	if (lst == NULL)
		return (1);
	temp = *((int *)(lst->content)); 
	check = lst->next;
	while (check != NULL)
	{
		if(*(int *)(check->content) < temp)
			return (-1);
		temp = *((int *)(check->content)); 
		check = check->next;
	}
	return (1);
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
	if(com_num == 0) bonus_swap(a);
	if(com_num == 1) bonus_swap(a);
	if(com_num == 2) bonus_ss(a,b);
	if(com_num == 3) bonus_push(b,a);
	if(com_num == 4) bonus_push(b,a);
	if(com_num == 5) bonus_rotate(a);
	if(com_num == 6) bonus_rotate(b);
	if(com_num == 7) bonus_rr(a,b);
	if(com_num == 8) bonus_rev_rotate(a);
	if(com_num == 9) bonus_rev_rotate(b);
	if(com_num == 10) bonus_rrr(a,b);

}


int check_command_number(char *line)
{
	int i;
	size_t line_len;
	char **command;
	command = malloc(sizeof(char *) * 11);
	if(command == NULL) return (-1);
	line_len = ft_strlen(line);

	command[0] = "sa\n";
    command[1] = "sb\n";
    command[2] = "ss\n";
	command[3] = "pa\n";
    command[4] = "pb\n";
    command[5] = "ra\n";
	command[6] = "rb\n";
    command[7] = "rr\n";
    command[8] = "rra\n";
	command[9] = "rrb\n";
    command[10] = "rrr\n";
	
	i = 0;
	while(i < 11)
	{
		if(line_len == ft_strlen(command[i]))
		{
			if(ft_strncmp(line, command[i], line_len) == 0)
			{
				free(command);
				return (i);
			}
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

	while((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		com_num = check_command_number(line);
		if(com_num != -1)
		{
			exec_command(com_num,a,b);
		}
		else
		{
			ft_printf("Error\n");
			free(line);
			return (-1);
		}
		free(line);
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

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	if (a == NULL || b == NULL )
	{
		print_error();
		free(a);
		free(b);
		return (-1);
	}
	if (check_input(argc, argv) == -1)
	{
		print_error();
		free(a);
		free(b);
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
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
	return (0);
}

