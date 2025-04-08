/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:57 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/08 14:24:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

//attach to window
//attach to buffer

void		igmlx_init_panel_base(t_igmlx_panel *panel)
{
	panel->base.type = IGMLX_COMPONENT_PANEL;
	panel->base.pos = (t_uvec_2){0, 0};
	// panel->base.states[IGMLX_STATE_DEFAULT]
	panel->base.collision_box = (t_uvec_2){150, 550};
}

t_igmlx_panel *igmlx_create_panel(t_igmlx *igmlx)
{
	t_igmlx_panel *panel;
	t_list			*lst;

	panel = balloc(sizeof(t_igmlx_panel));
	if (!panel)
		return (NULL);
	lst = ft_lstnew(panel);
	if (!lst)
		return (NULL);
	panel->igmlx = igmlx;

	panel->pre_render = igmlx_panel_pre_render;
	panel->add_button = igmlx_panel_add_button_component;
	panel->render_on_window = igmlx_panel_render_on_window;
	panel->set_background = igmlx_change_panel_background_color;
	panel->render_on_buffer = NULL;
	panel->destroy = igmlx_destroy_panel;
	igmlx_init_panel_base(panel);
	ft_lstadd_back(&igmlx->panels, lst);
	return (panel);
}
