/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:50:10 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/02 17:53:38 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		bound;
	int		index;
	int		*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min;
	buffer = malloc(bound * sizeof(int));
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index < bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound);
}

/*
#include <stdio.h>
void	test_ft_ultimate_range(int min, int max)
{
	int *arr;
	int size = ft_ultimate_range(&arr, min, max);
	
	if (size == -1)
		printf("Memory allocation failed for range [%d, %d]\n", min, max);
	else if (size == 0)
		printf("Invalid range: [%d, %d]\n", min, max);
	else
	{
		printf("Range [%d, %d]: ", min, max);
		for (int i = 0; i < size; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
	}
}
int main(void)
{
	test_ft_ultimate_range(5, 10);   // 5 6 7 8 9
	test_ft_ultimate_range(-3, 3);   // -3 -2 -1 0 1 2
	test_ft_ultimate_range(2, 2);    // Invalid range
	test_ft_ultimate_range(4, 3);    // Invalid range
	test_ft_ultimate_range(1, 2);    // 1
	test_ft_ultimate_range(-10, -5); // -10 -9 -8 -7 -6
	return 0;
}
*/
