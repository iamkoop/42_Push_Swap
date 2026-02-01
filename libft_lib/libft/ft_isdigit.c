/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:22:03 by nildruon          #+#    #+#             */
/*   Updated: 2025/10/17 18:16:53 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit(3));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit(120));
}
*/