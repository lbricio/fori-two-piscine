/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:53:52 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/02 17:53:39 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	index;
	int	*buffer;

	if (min >= max)
		return (0);
	range = max - min;
	buffer = malloc(range * sizeof(int));
	if (!buffer)
		return (0);
	index = 0;
	while (index < range)
	{
		buffer[index] = min + index;
		index++;
	}
	return (buffer);
}

/*
#include <stdio.h>
void	test_ft_range(int min, int max) {
	int *arr = ft_range(min, max);
	if (arr) {
		printf("Range [%d, %d]: ", min, max);
		for (int i = 0; i < max - min; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
	}
	else
		printf("Invalid range: [%d, %d)\n", min, max);
}
int main(void) {
	test_ft_range(5, 10);  // 5 6 7 8 9
	test_ft_range(-3, 3);  // -3 -2 -1 0 1 2
	test_ft_range(0, 0);   // Invalid range
	test_ft_range(7, 3);   // Invalid range
	test_ft_range(1, 2);   // 1
	test_ft_range(-10, -5); // -10 -9 -8 -7 -6
	return 0;
}
*/