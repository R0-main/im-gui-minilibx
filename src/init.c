/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:21:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx	*igmlx_init(void *mlx)
{
	t_igmlx	*igmlx;

	igmlx = malloc(sizeof(t_igmlx));
	if (!igmlx)
		return (NULL);
	ft_bzero(igmlx, sizeof(t_igmlx));
	igmlx->mlx = mlx;
	return (igmlx);
}

void	igmlx_destroy(t_igmlx *igmlx)
{
	t_list	*current;
	t_list	*tmp;

	_log(IGMLX_LOG_INFO, "Destroyed !");
	if (!igmlx)
		return ;
	free(igmlx);
	current = igmlx->wins_data;
	while (current)
	{
		tmp = current->next;
		ft_lstclear(&((t_win_data *)current->content)->components, free);
		current = tmp;
	}
	ft_lstclear(&igmlx->wins_data, free);
}
