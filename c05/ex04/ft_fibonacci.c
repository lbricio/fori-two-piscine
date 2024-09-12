/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:00:13 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:46 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	aux;

	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index > 1)
	{
		aux = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (aux);
	}
	else
		return (-1);
}

#include <stdio.h>
int    main(void)
{
    printf("fibonacci (0) == %i, expected: %i\n", ft_fibonacci(0), 0);
    printf("fibonacci (1) == %i, expected: %i\n", ft_fibonacci(1), 1);
    printf("fibonacci (2) == %i, expected: %i\n", ft_fibonacci(2), 1);
    printf("fibonacci (3) == %i, expected: %i\n", ft_fibonacci(3), 2);
    printf("fibonacci (4) == %i, expected: %i\n", ft_fibonacci(4), 3);
    printf("fibonacci (5) == %i, expected: %i\n", ft_fibonacci(5), 5);
    printf("fibonacci (6) == %i, expected: %i\n", ft_fibonacci(6), 8);
    return (0);
}