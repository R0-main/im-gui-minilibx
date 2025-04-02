/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:11:32 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:18:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_copy_to_dest(t_img *origin, t_uvec_2 origin_pos, t_uvec_2 length, t_img *dest, t_uvec_2 dest_pos)
{
	t_uvec_2 c;

	c = (t_uvec_2){-1, -1};
	while (++c.x < length.x)
	{
		c.y = -1;
		while (++c.y < length.y)
		{
			((int *)dest)[((dest_pos.y + c.y)/ dest->size_line) + (dest_pos.x + c.x)] = ((int *)origin)[((origin_pos.y + c.y) / origin->size_line) + (origin_pos.x + c.x)];
		}
	}
}
