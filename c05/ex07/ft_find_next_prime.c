/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:00:22 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/02 16:23:43 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n <= nb / 2)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb < 2147483647 && !ft_is_prime(nb))
		nb++;
	return (nb);
}

#include <stdio.h>
int main(void)
{
    printf("Próximo primo após -1: %d\n", ft_find_next_prime(-1));
    printf("Próximo primo após 0: %d\n", ft_find_next_prime(0));
    printf("Próximo primo após 1: %d\n", ft_find_next_prime(1));
    printf("Próximo primo após 2: %d\n", ft_find_next_prime(2));
    printf("Próximo primo após 4: %d\n", ft_find_next_prime(4));
	printf("Próximo primo após 9: %d\n", ft_find_next_prime(9));
    printf("Próximo primo após 10: %d\n", ft_find_next_prime(10));
    printf("Próximo primo após 17: %d\n", ft_find_next_prime(17));
    printf("Próximo primo após 100: %d\n", ft_find_next_prime(100));
    return 0;
}