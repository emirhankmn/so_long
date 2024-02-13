/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:03:25 by eakman            #+#    #+#             */
/*   Updated: 2023/07/12 13:11:13 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t len)
{
	void	*dst;

	dst = malloc(n * len);
	if (!dst)
		return (NULL);
	else
		ft_bzero(dst, n * len);
	return (dst);
}
