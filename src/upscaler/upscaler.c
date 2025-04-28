/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:32:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/28 13:39:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_img	*igmlx_upscale_img(t_igmlx *igmlx, t_img *img, unsigned int factor)
{
	t_uvec_2	c;
	t_uvec_2	i;
	t_img		*new_img;

	c = (t_uvec_2){-1, -1};
	i = (t_uvec_2){-1, -1};
	if (factor == 1)
		return (img);
	new_img = mlx_new_image(igmlx->mlx, img->width * factor, img->height
			* factor);
	if (!new_img)
		return (NULL);
	while (++c.x < (unsigned int)img->width)
	{
		c.y = -1;
		while (++c.y < (unsigned int)img->height)
		{
			i.x = -1;
			while (++i.x <= factor)
			{
				i.y = -1;
				while (++i.y <= factor)
				{
					*get_pixel(new_img, (t_uvec_2){(c.x * factor) + i.x, (c.y
								* factor) + i.y}) = *get_pixel(img,
							(t_uvec_2){c.x, c.y});
				}
			}
		}
	}
	return (new_img);
}
