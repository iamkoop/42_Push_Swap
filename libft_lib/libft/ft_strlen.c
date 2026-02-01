/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:42:34 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/09 12:01:11 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}

/*int	main(void)
{
	printf("%zu\n", ft_strlen("WEEE"));
	printf("%zu\n", ft_strlen(" "));
	printf("%zu\n", ft_strlen("a"));
	printf("%zu\n", ft_strlen("\0"));
}*/
