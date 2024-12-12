/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarysarch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/12 16:28:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_binarysarch(int *arr,int arrsize,int target)
{
	int left;
	int right;
	int mid;

	left = 0;
	right = arrsize - 1;
	while(left <= right)
	{
		mid = left + (right - left)/2;
		if(arr[mid] == target)
			return (mid);
		else if(arr[mid] < target)
			left = mid + 1;
		else if (arr[mid] > target)
			right = mid - 1;
	}
	return (-1);
}
