/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarysarch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 18:47:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

int ft_binarysarch(int *arr,int arrsize,int target)
{
	int left;
	int right;
	int mid;
	int ans;

	left = -1;
	right = arrsize;
	while(right - left > 1)
	{
		mid = left + (right - left)/2;
		if(arr[mid] >= target)
		{
			if(arr[mid] == target)
				ans = mid;
			right = mid;
		}
		else if(arr[mid] < target)
			left = mid;
	}
	return (ans);
}
