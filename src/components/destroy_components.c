/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:57:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 08:57:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void free_component(t_igmlx *igmlx, t_igmlx_default_component *component)
{
	size_t i;

	i = 0;
	while (i < IGMLX_STATE_COUNT)
		mlx_destroy_image(igmlx->mlx, component->base.states[i++].render);
	free(component);
}

void igmlx_destroy_component_list(t_igmlx *igmlx, t_list **components)
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
