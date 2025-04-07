/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:57:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 16:03:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_free_component(t_igmlx *igmlx,
		t_igmlx_default_component *component)
{
	size_t	i;
	t_list	*current;
	t_list	*old;

	if (!component)
		return ;
	i = -1;
	current = NULL;
	if (component->base.type == IGMLX_COMPONENT_PANEL)
	{
		current = igmlx->panels;
		while (current)
		{
			if (current->content == component)
			{
				if (old)
					old->next = current->next;
				else
					igmlx->panels = NULL;
				free(current);
				break;
			}
			old = current;
			current = current->next;
		}
		current = ((t_igmlx_panel *)component)->childs;
		while (current)
		{
			old = current->next;
			igmlx_free_component(igmlx, current->content);
			free(current);
			current = old;
		}
	}
	while (++i < IGMLX_STATE_COUNT)
		if (component->base.states[i].render)
			mlx_destroy_image(igmlx->mlx, component->base.states[i].render);
	free(component);
}
