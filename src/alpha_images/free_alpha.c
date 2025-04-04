/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:01:37 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/04 11:14:18 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_free_alpha(t_igmlx *igmlx, t_alpha_img *alpha)
{
	t_list		*lst;
	t_list		*tmp_lst;
	t_img_block	*tmp;

	if (!alpha)
		return ;
	lst = alpha->blocks;
	while (lst)
	{
		tmp_lst = lst->next;
		tmp = (t_img_block *)lst->content;
		if (tmp && tmp->img)
		{
			mlx_destroy_image(igmlx->mlx, tmp->img);
			free(tmp);
		}
		free(lst);
		lst = tmp_lst;
	}
	free(alpha);
}
