/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:54:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/08 15:27:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

int	igmlx_mouse_motion_event_callback(int x, int y, t_igmlx *igmlx)
{
	t_igmlx_default_component	*component;

	// _debug("Mouse Moved");
	component = get_component_at(igmlx, (t_uvec_2){(unsigned int)x,
			(unsigned int)y});
	if (component && component == igmlx->last_hovered_component)
		return (0);
	// printf("%d %d\n", x, y);
	if (component && component == igmlx->drag_component)
	{
		component->base.pos = (t_uvec_2){x, y};
		component->base.rendered = false;
		return (0);
	}
	if (component)
	{
		_error("Touched");
		igmlx_set_component_state(component, IGMLX_STATE_HOVERED);
		igmlx->last_hovered_component = component;
	}
	else if (igmlx->last_hovered_component
		&& is_timer_finished(&igmlx->last_hovered_component->base.last_change_state_timer))
	{
		igmlx_set_component_state(igmlx->last_hovered_component, IGMLX_STATE_DEFAULT);
		igmlx->last_hovered_component = NULL;
	}
	return (0);
}

int	igmlx_mouse_button_released_event_callback(int key, int x, int y,
		t_igmlx *igmlx)
{
	_debug("Mouse Released");
	if (igmlx->drag_component)
	{
		_debug("darg off");
		igmlx->drag_component->base.pos = (t_uvec_2){x, y};
		igmlx->drag_component->base.rendered = false;
		igmlx->drag_component = NULL;
	}
	(void)key, (void)x, (void)y, (void)igmlx;
	return (0);
}

int	igmlx_mouse_button_pressed_event_callback(int key, int x, int y,
		t_igmlx *igmlx)
{
	t_igmlx_default_component	*component;

	_debug("Mouse Pressed");
	component = get_component_at(igmlx, (t_uvec_2){(unsigned int)x,
			(unsigned int)y});
	if (key == 1 && component && component->base.type == IGMLX_COMPONENT_BUTTON)
	{
		if (((t_igmlx_button_component *)component)->press
			&& ((t_igmlx_button_component *)component)->data
			&& !component->base.last_change_state_timer.started)
		{
			igmlx_set_component_state(component, IGMLX_STATE_PRESSED);
			component->base.last_change_state_timer.duration = ((t_igmlx_button_component *)component)->delay;
			start_timer(&component->base.last_change_state_timer);
			((t_igmlx_button_component *)component)->press(((t_igmlx_button_component *)component)->data);
		}
	}
	if (key == 1 && component && component->base.type == IGMLX_COMPONENT_PANEL && ((t_igmlx_panel *)component)->dragable)
	{
		_debug("yeah");
		igmlx->drag_component = component;
	}
	return (0);
}
