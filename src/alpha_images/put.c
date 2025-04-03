/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:49:12 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 14:54:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_put_alpha_to_window(t_igmlx *igmlx, void *win, t_alpha_img *alpha, t_uvec_2 pos)
{
	t_list *lst;
	t_img_block *tmp;

	lst = alpha->blocks;
	while (lst)
	{
		tmp = (t_img_block *)lst->content;
		if (tmp)
			mlx_put_image_to_window(igmlx->mlx, win, tmp->img, pos.x + tmp->offset.x, pos.y + tmp->offset.y);
		lst = lst->next;
	}
}
