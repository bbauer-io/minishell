/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_intmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:12:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 19:52:41 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <inttypes.h>
#include "libft.h"

/*
** ft_itoa_base takes a number and returns it as a string in whichever base is
** specified, up to 16.
*/

/*
** generate_base_digit_array creates an array of chars "123456789ABCDEF"
*/

static void		generate_base_digit_array(char *arr)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		arr[i] = i + 'A' - 10;
		i++;
	}
}

/*
** calc_indices calculates the index (in the base_digit_array) which corresponds
** to the character that represents the next digit in base /base/. These indices
** are saved to the indices array.
*/

static int		calc_indices(int *indices, uintmax_t value, int base)
{
	int		i;

	i = 0;
	while (value != 0)
	{
		indices[i++] = value % base;
		value = value / base;
	}
	return (--i);
}

/*
** create_base_str access the digits array at the indices stored in the indices
** array to create the string which will be returned;
*/

static char		*create_base_str(char *digits, int *indices, int i)
{
	int		j;
	char	*result;

	result = (char *)malloc((i + 2) * sizeof(char));
	j = 0;
	while (i >= 0)
		result[j++] = digits[indices[i--]];
	result[j] = '\0';
	return (result);
}

/*
** ft_itoa_base takes a number and returns it as a string in whichever base is
** specified, up to 16.
*/

char			*ft_itoa_base_uintmax(uintmax_t value, int base)
{
	char		base_digits[16];
	int			conversion_index[64];
	int			i;

	if (value == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	generate_base_digit_array(base_digits);
	i = calc_indices(conversion_index, value, base);
	return (create_base_str(base_digits, conversion_index, i));
}
