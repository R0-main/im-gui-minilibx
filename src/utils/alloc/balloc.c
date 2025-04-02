/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:25:45 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:09:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void *balloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		_error("a malloc failed!");
		return (NULL);
	}
	ft_bzero(ptr, size);
	return (ptr);
}
