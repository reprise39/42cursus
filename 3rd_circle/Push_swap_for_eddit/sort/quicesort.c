/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:12:26 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/12 15:28:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_intswitch(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int qsort_partition(int *array,int left,int right)
{
	const int pivot = array[right];
	int i;
	int j;

	i = left;
	j = left - 1;
	while(i < right)
	{
		if(array[i] < pivot)
		{
			j++;
			ft_intswitch(&array[i],&array[j]);
		}
		i++;
	}
	ft_intswitch(&array[j+1],&array[right]);
	return (j+1);
}

void ft_qsort(int *array,int left,int right)
{
	int pivot;
	
	if(left < right)
	{
		pivot = qsort_partition(array,left,right);
		ft_qsort(array,pivot + 1,right);
		ft_qsort(array,left,pivot-1);
	}
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 3, 7, 6, 2, 5 , 82, 8872, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
	ft_qsort(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}


