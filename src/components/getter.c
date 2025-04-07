/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:37:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_default_component	*get_panels_component_at(t_igmlx_panel *panel,
		t_uvec_2 coords)
{
	t_list						*current;
	t_igmlx_default_component	*component;

	current = panel->childs;
	while (current && current->content)
	{
		component = (t_igmlx_default_component *)current->content;
		if (is_inside_rectangle(component->base.pos,
				(t_uvec_2){component->base.collision_box.x
				+ component->base.pos.x, component->base.collision_box.y
				+ component->base.pos.y}, coords))
		{
			return (component);
		}
		current = current->next;
	}
	return (NULL);
}

t_igmlx_default_component	*get_component_at(t_igmlx *igmlx, t_uvec_2 coords)
{
	t_list						*current;
	t_igmlx_default_component	*component;

	component = NULL;
	current = igmlx->panels;
	while (current)
	{
		component = get_panels_component_at(((t_igmlx_panel *)current->content),
				coords);
		if (component)
			return (component);
		current = current->next;
	}
	return (component);
}
