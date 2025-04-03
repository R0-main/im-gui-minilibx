/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:56:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 09:02:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_destroy(t_igmlx *igmlx)
{
	t_list	*current;
	t_list	*tmp;

	_info("Destroyed !");
	if (!igmlx)
		return ;
	current = igmlx->wins_data;
	while (current)
	{
		tmp = current->next;
		igmlx_destroy_component_list(igmlx, &((t_win_data *)current->content)->components);
		current = tmp;
	}
	igmlx_destroy_fonts_list(igmlx, &igmlx->fonts);
	ft_lstclear(&igmlx->wins_data, free);
	free(igmlx);
}
