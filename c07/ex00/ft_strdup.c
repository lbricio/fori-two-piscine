/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:50:26 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/02 17:53:41 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*head;

	head = str;
	while (*str)
		str++;
	return (str - head);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int main()
{
    int i = 0;
    char *current_test;
    current_test = ft_strdup(""); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup(" "); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("   "); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup(" a"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("a "); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup(" a "); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("absdfsfsd"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("newline adiante:\n"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("tab adiante:\t"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("sdfsdfsd....$@#"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("abcdefghijklmnopqrstuvwxyz"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("こんにちは"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
    current_test = ft_strdup("😊🌍🚀"); 
    printf("[%i]\t [%s]\n", i++, current_test); free(current_test);
}
*/
