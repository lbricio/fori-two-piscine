/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:50:06 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/05 17:55:10 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_joined_size(int size, char **strs, char *sep)
{
	unsigned int	total_size;
	unsigned int	offset;
	int				i;

	if (size < 1)
		return (1);
	i = 0;
	total_size = 0;
	while (i < size)
	{
		offset = 0;
		while (strs[i][offset] != '\0')
		{
			++total_size;
			++offset;
		}
		++i;
	}
	i = 0;
	while (*sep != '\0')
	{
		++sep;
		++i;
	}
	return (total_size + ((size - 1) * i) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	offset;
	char			*ret;
	char			*itstr;
	char			*itsep;
	int				i;

	ret = malloc(get_joined_size(size, strs, sep));
	if (ret == NULL)
		return (NULL);


		
	i = -1;
	itstr = ret;
	while (++i < size)
	{
		offset = 0;
		while (strs[i][offset] != '\0')
			*itstr++ = strs[i][offset++];
		if (i < size - 1)
		{
			itsep = sep;
			while (*itsep != '\0')
				*itstr++ = *itsep++;
		}
	}
	*itstr = '\0';
	return (ret);
}

/*
#include <stdio.h>
char	*ft_strjoin(int size, char **strs, char *sep);
int	main(void)
{
	// Test 1: Basic cases
	char *strs1[] = {"Hello", "world", "!"};
	char *sep1 = " ";
	char *result1 = ft_strjoin(3, strs1, sep1);
	printf("Result 1: %s\n", result1);  // "Hello world !"
	free(result1);

	// Test 2: No separator
	char *strs2[] = {"42", "Tokyo", "Seoul"};
	char *sep2 = "";
	char *result2 = ft_strjoin(3, strs2, sep2);
	printf("Result 2: %s\n", result2);  // "42SpSeoul"
	free(result2);

	// Test 3: One string
	char *strs3[] = {"Single"};
	char *sep3 = "42";
	char *result3 = ft_strjoin(1, strs3, sep3);
	printf("Result 3: %s\n", result3);  // "Single"
	free(result3);

	// Test 4: No strings
	char *result4 = ft_strjoin(0, NULL, "42");
	printf("Result 4: %s\n", result4);  // ""
	free(result4);

	// Test 5: Multiple empty strings
	char *strs5[] = {"", "", ""};
	char *sep5 = "SEP";
	char *result5 = ft_strjoin(3, strs5, sep5);
	printf("Result 5: '%s'\n", result5);  // "SEPSEP"
	free(result5);

	// Test 6: Empty separator
	char *strs6[] = {"A", "B", "C"};
	char *sep6 = "";
	char *result6 = ft_strjoin(3, strs6, sep6);
	printf("Result 6: %s\n", result6);  // "ABC"
	free(result6);

	// Test 7: Special characters
	char *strs7[] = {"abc", "123", "!@#"};
	char *sep7 = "==";
	char *result7 = ft_strjoin(3, strs7, sep7);
	printf("Result 7: %s\n", result7);  // "abc==123==!@#"
	free(result7);

	return 0;
}
*/