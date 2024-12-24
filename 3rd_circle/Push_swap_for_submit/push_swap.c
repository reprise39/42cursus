/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:37:45 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 19:29:05 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

void print_error(int n)
{
	const char *str = "Error\n";
	const char *error1 = "input_range_error : Please give number in int range\n";
	const char *error2 = "marroc error : i dont know what to do\n";
	const char *error3 = "input_deplicate_error : Please give unique arguments in int range\n";
	char *error_message;
	
	if(n == 1)
		error_message = (char *)error1;
	else if(n == 2)
		error_message = (char *)error2;
	else if(n == 3)
		error_message = (char *)error3;
	write(STDERR_FILENO,str,ft_strlen(str));
	write(STDERR_FILENO,error_message,ft_strlen(error_message));
	return;
}

int main(int argc,char **argv)
{
	t_list **a;
	
	if(argc == 1)
		return (0);
	if(check_input(argc,argv) == -1)
	{
		print_error(1);
		return (-1);
	}
	a = malloc(sizeof(t_list **));
	if(a == NULL)
	{
		print_error(2);
		return (-1);
	}
	*a = pushtostack_and_checkoverlap(argc,argv);
	if(*a == NULL)
	{
		print_error(3);
		free(a);
		return (-1);
	}
	coodinatecompress(*a,argc-1);
	push_swap_algo(a);
	ft_lstclear(a,free);
	free(a);
	return (0);
}
