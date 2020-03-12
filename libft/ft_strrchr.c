/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybakker <ybakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:21:08 by ybakker           #+#    #+#             */
/*   Updated: 2019/11/19 13:46:35 by ybakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (0);
	while (*str)
	{
		if (*str == c)
			ptr = (char*)str;
		str += 1;
	}
	if (ptr)
		return (ptr);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
