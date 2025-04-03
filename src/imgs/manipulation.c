/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:11:32 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 15:04:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_color	*get_pixel(t_img *img, t_uvec_2 pos)
{
	return ((t_color *)img->data + pos.y * (img->size_line / 4) + pos.x);
}

t_color	get_pixel_color(t_img *img, t_uvec_2 pos)
{
	return (*get_pixel(img, pos));
}

void	igmlx_copy_to_dest(t_img *origin, t_uvec_2 origin_pos, t_uvec_2 length, t_img *dest, t_uvec_2 dest_pos)
{
	t_uvec_2 c;

	c = (t_uvec_2){-1, -1};
	while (++c.x < length.x)
	{
		c.y = -1;
		while (++c.y < length.y)
		{
			*get_pixel(dest, (t_uvec_2){dest_pos.x + c.x, dest_pos.y + c.y}) = *get_pixel(origin, (t_uvec_2){origin_pos.x + c.x, origin_pos.y + c.y});
		}
	}
}

void	igmlx_set_to_null(t_img *origin, t_uvec_2 origin_pos, t_uvec_2 length)
{
	t_uvec_2 c;

	c = (t_uvec_2){-1, -1};
	while (++c.x < length.x)
	{
		c.y = -1;
		while (++c.y < length.y)
		{
			*get_pixel(origin, (t_uvec_2){origin_pos.x + c.x, origin_pos.y + c.y}) = 0xFF000000;
		}
	}
}
