/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:09:57 by mvidal-a          #+#    #+#             */
/*   Updated: 2021/03/30 16:46:19 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_limit(char *str, int neg)
{
	if (str[0] > '2')
		return (FALSE);
	else if (str[0] < '2')
		return (TRUE);
	else
	{
		if (str[1] > '1')
			return (FALSE);
	}
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
	while (str[len] != '\0')
	{
		if (!ft_isdigit(str[len]))
			return (FALSE);
		len++;
	}
	if (len > 10 || (len == 10 && !check_limit(str, neg)))
		return (FALSE);
	return (TRUE);
}
