/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:07:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx	*igmlx_init(void *mlx)
{
	t_igmlx	*igmlx;

	igmlx = balloc(sizeof(t_igmlx));
	if (!igmlx)
		return (NULL);
	igmlx->mlx = mlx;
	return (igmlx);
}

static void free_component(t_igmlx *igmlx, t_igmlx_default_component *component)
{
	size_t i;

	i = 0;
	while (i < IGMLX_STATE_COUNT)
		mlx_destroy_image(igmlx->mlx, component->base.states[i++].render);
	free(component);
}

static void igmlx_destroy_component_list(t_igmlx *igmlx, t_list **components)
{
	t_list	*current;
	t_list	*tmp;

	if (!components)
		return ;
	current = *components;
	while (current)
	{
		tmp = current->next;
		if (current->content)
			free_component(igmlx, current->content);
		free(current);
		current = tmp;
	}
}

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
	ft_lstclear(&igmlx->wins_data, free);
	free(igmlx);
}
