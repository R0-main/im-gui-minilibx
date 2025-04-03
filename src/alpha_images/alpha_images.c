/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:30:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 14:46:50 by rguigneb         ###   ########.fr       */
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

void get_blocks(t_igmlx *igmlx, t_img *origin, t_alpha_img *alpha)
{
	t_uvec_2 c;
	t_rectangle	max;
	t_list	*lst;
	t_img_block	*block;

	c = (t_uvec_2){-1, -1};
	ft_bzero(&max, sizeof(t_rectangle));
	max = get_largest_rectangle_available_img(origin);
	while (max.area > 0)
	{
		block = transform_to_block(igmlx, origin, max.pos, max.length);
		if (!block)
			return ; // free others
		lst = ft_lstnew(block);
		if (!lst)
			return ; // free others
		ft_lstadd_front(&alpha->blocks, lst);
		igmlx_set_to_null(origin, max.pos, max.length);
		max = get_largest_rectangle_available_img(origin);
	}
}

t_alpha_img	*transform_img_to_alpha_img(t_igmlx *igmlx, t_img *img)
{
	t_alpha_img	*alpha;

	alpha = balloc(sizeof(t_alpha_img));
	if (!alpha)
		return (NULL);
	get_blocks(igmlx, img, alpha);
	return (alpha);
}
