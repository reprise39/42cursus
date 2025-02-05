/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:32:49 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 15:47:26 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

void	ft_intswitch(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	qsort_partition(int *array, int left, int right)
{
	const int	pivot = array[right];
	int			i;
	int			j;

	i = left;
	j = left - 1;
	while (i < right)
	{
		if (array[i] < pivot)
		{
			j++;
			ft_intswitch(&array[i], &array[j]);
		}
		i++;
	}
	ft_intswitch(&array[j + 1], &array[right]);
	return (j + 1);
}

void	ft_qsort(int *array, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = qsort_partition(array, left, right);
		ft_qsort(array, pivot + 1, right);
		ft_qsort(array, left, pivot - 1);
	}
}
