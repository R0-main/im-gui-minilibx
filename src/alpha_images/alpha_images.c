/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:30:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 11:50:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_img_block	*transform_to_block(t_igmlx *igmlx, t_img *origin, t_uvec_2 pos,
		t_uvec_2 length)
{
	t_img_block	*block;
	t_img		*img;

	block = balloc(sizeof(t_img_block));
	if (!block)
		return (NULL);
	img = mlx_new_image(igmlx->mlx, length.x, length.y);
	if (!img)
	{
		_error("mlx_new_image failed at (igmlx)transform_to_block");
		return (NULL);
	}
	block->img = img;
	igmlx_copy_to_dest(origin, pos, length, img, (t_uvec_2){0, 0});
	return (block);
}

t_img_block	*get_blocks(t_igmlx *igmlx, t_img *origin, t_alpha_img *alpha)
{
	t_uvec_2 c;
	t_uvec_2 end;

	c = (t_uvec_2){-1, -1};
	while (++c.x < origin->width)
	{
		c.y = -1;
		while (++c.y < origin->height)
		{
			end = c;
			if (get_pixel_color(origin, c) & 0x000000FF)
				continue;
			while (get_pixel(origin, end))
			{
				/* code */
			}

		}
	}
}

t_alpha_img	*transform_img_to_alpha_img(t_igmlx *igmlx, t_img *img)
{
	t_alpha_img	*alpha;

	alpha = balloc(sizeof(t_alpha_img));
	if (!alpha)
		return (NULL);
	alpha->blocks = get_blocks(igmlx, img, alpha);
	return (alpha);
}
