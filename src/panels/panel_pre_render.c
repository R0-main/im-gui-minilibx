/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_pre_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:18:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:27:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_panel_pre_render(t_igmlx_panel *panel)
{
	t_list	*current;

	if (!panel->igmlx)
		return ;
	current = panel->childs;
	while (current)
	{
		if (current->content)
			init_component_states_images(panel->igmlx, (t_igmlx_default_component *)current->content);
		current = current->next;
	}
	_info("Components PreRendered");
}
