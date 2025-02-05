/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_make_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 17:25:16 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

void	exec_command(int com_num, t_list **a, t_list **b)
{
	if (com_num == 0)
		bonus_swap(a);
	if (com_num == 1)
		bonus_swap(b);
	if (com_num == 2)
		bonus_ss(a, b);
	if (com_num == 3)
		bonus_push(a, b);
	if (com_num == 4)
		bonus_push(b, a);
	if (com_num == 5)
		bonus_rotate(a);
	if (com_num == 6)
		bonus_rotate(b);
	if (com_num == 7)
		bonus_rr(a, b);
	if (com_num == 8)
		bonus_rev_rotate(a);
	if (com_num == 9)
		bonus_rev_rotate(b);
	if (com_num == 10)
		bonus_rrr(a, b);
}

int	check_command_number(char *line)
{
	int			i;
	size_t		line_len;
	const char	*command[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	line_len = ft_strlen(line);
	i = 0;
	while (i < 11)
	{
		if (line_len == ft_strlen(command[i]))
		{
			if (ft_strncmp(line, command[i], line_len) == 0)
			{
				return (i);
			}
		}
		i++;
	}
	return (-1);
}

int	tester_main_process(t_list **a, t_list **b)
{
	char	*line;
	int		com_num;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			free(line);
			break ;
		}
		com_num = check_command_number(line);
		if (com_num != -1)
			exec_command(com_num, a, b);
		else
		{
			ft_printf("Error\n");
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	print_list_is_ok_or_ko(a, b);
	return (1);
}

static void	print_error(void)
{
	const char	*str = "Error\n";

	write(STDERR_FILENO, str, ft_strlen(str));
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	if (check_input(argc, argv) == -1)
	{
		print_error();
		return (-1);
	}
	a = pushtostack_and_checkoverlap(argc, argv);
	if (a == NULL)
	{
		print_error();
		return (-1);
	}
	tester_main_process(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
