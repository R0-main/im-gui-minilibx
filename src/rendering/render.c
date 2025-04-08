/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

// static void	igmlx_render_panel_component(t_igmlx *igmlx, void *win,
// 		t_igmlx_panel *panel)
// {
// 	t_list	*current;

// 	current = panel->childs;
// 	while (current)
// 	{
// 		igmlx_render_component(igmlx, win,
// 			(t_igmlx_default_component *)current->content);
// 		current = current->next;
// 	}
// }

// void	igmlx_render_component_as_base(t_igmlx *igmlx, void *win,
// 		t_igmlx_default_component *component)
// {
// 	t_img	*img;

// 	if (!component)
// 		return ;
// 	if (component->base.last_state == component->base.state
// 		&& component->base.rendered)
// 		return ;
// 	component->base.rendered = true;
// 	if (component->base.last_change_state_timer.started
// 		&& is_timer_finished(&component->base.last_change_state_timer))
// 	{
// 		if (is_inside_rectangle(component->base.pos,
// 				(t_uvec_2){component->base.collision_box.x
// 				+ component->base.pos.x, component->base.collision_box.y
// 				+ component->base.pos.y}, igmlx->mouse_pos))
// 			igmlx_set_component_state(component, IGMLX_STATE_HOVERED);
// 		else
// 			igmlx_set_component_state(component, IGMLX_STATE_DEFAULT);
// 		component->base.last_change_state_timer.started = false;
// 	}
// 	img = get_component_image(component);
// 	if (!img)
// 		return ;
// 	mlx_put_image_to_window(igmlx->mlx, win, img, component->base.pos.x,
// 		component->base.pos.y);
// }

void	igmlx_render_component(t_igmlx *igmlx, void *win,
		t_igmlx_default_component *component)
{
	t_img	*img;

	if (!component)
		return ;
	if (component->base.last_state == component->base.state
		&& component->base.rendered)
		return ;
	component->base.rendered = true;
	if (component->base.last_change_state_timer.started
		&& is_timer_finished(&component->base.last_change_state_timer))
	{
		if (is_inside_rectangle(component->base.pos,
				(t_uvec_2){component->base.collision_box.x
				+ component->base.pos.x, component->base.collision_box.y
				+ component->base.pos.y}, igmlx->mouse_pos))
			igmlx_set_component_state(component, IGMLX_STATE_HOVERED);
		else
			igmlx_set_component_state(component, IGMLX_STATE_DEFAULT);
		component->base.last_change_state_timer.started = false;
	}
	img = get_component_image(component);
	if (!img)
		return ;
	mlx_put_image_to_window(igmlx->mlx, win, img, component->base.pos.x,
		component->base.pos.y);
}

void	igmlx_render_panel_components_to_window(t_igmlx_panel *panel, void *win)
{
	t_list	*current;

	if (!panel)
		return ;
	current = panel->childs;
	igmlx_render_component(panel->igmlx, win,
		(t_igmlx_default_component *)panel);
	while (current)
	{
		if (((t_igmlx_default_component *)current->content)->base.type == IGMLX_COMPONENT_PANEL)
		{
			igmlx_render_panel_components_to_window((t_igmlx_panel *)current->content, win);
		}
		else
			igmlx_render_component(panel->igmlx, win,
				(t_igmlx_default_component *)current->content);
		current = current->next;
	}
}
