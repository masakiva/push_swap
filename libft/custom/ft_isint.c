/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:09:57 by mvidal-a          #+#    #+#             */
/*   Updated: 2021/04/08 10:56:32 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_int_limits(char *str, int neg)
{
	long	tmp;

	tmp = ft_atol(str);
	if ((neg == FALSE && tmp > 2147483647)
			|| (neg == TRUE && tmp > 2147483648))
		return (FALSE);
	return (TRUE);
}

int		ft_isint(char *str)
{
	size_t	len;
	t_byte	neg;

	neg = FALSE;
	if (str[0] == '-')
	{
		str++;
		neg = TRUE;
	}
	len = 0;
	while (str[len] == '0')
		str++;
	while (str[len] != '\0')
	{
		if (!ft_isdigit(str[len]))
			return (FALSE);
		len++;
	}
	if (len > 10 || (len == 10 && !check_int_limits(str, neg)))
		return (FALSE);
	return (TRUE);
}
