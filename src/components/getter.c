/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 14:45:24 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_default_component	*get_win_component_at(t_igmlx *igmlx, void *win,
		t_uvec_2 coords)
{
	t_win_data					*data;
	t_list						*current;
	t_igmlx_default_component	*component;

	data = get_window_data(igmlx, win);
	if (!data)
		return (NULL);
	current = data->components;
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
	t_list *current;
	t_igmlx_default_component *component;

	component = NULL;
	current = igmlx->wins_data;
	while (current)
	{
		component = get_win_component_at(igmlx, ((t_win_data *)current->content)->win, coords);
		if (component)
			return (component);
		current = current->next;
	}
	return (component);
}
