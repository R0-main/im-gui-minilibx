/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:54:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 15:50:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

int	mouse_motion(int x, int y, t_igmlx *igmlx)
{
	t_igmlx_default_component	*component;

	_log(IGMLX_LOG_DEBUG, "Mouse Moved");
	component = get_component_at(igmlx, (t_uvec_2){(unsigned int)x,
			(unsigned int)y});
	if (component && component == igmlx->last_hovered_component)
		return (0);
	if (component)
	{
		_log(IGMLX_LOG_ERROR, "Touched");
		component->base.state = IGMLX_STATE_HOVERED;
		igmlx->last_hovered_component = component;
	}
	else if (igmlx->last_hovered_component && is_timer_finished(&igmlx->last_hovered_component->base.last_change_state_timer))
	{
		igmlx->last_hovered_component->base.state = IGMLX_STATE_DEFAULT;
		igmlx->last_hovered_component = NULL;
	}
	return (0);
}

int	release_mouse(int key, int x, int y, t_igmlx *igmlx)
{
	_log(IGMLX_LOG_DEBUG, "Mouse Released");
	(void)key, (void)x, (void)y, (void)igmlx;
	return (0);
}

int	press_mouse(int key, int x, int y, t_igmlx *igmlx)
{
	t_igmlx_default_component	*component;

	_log(IGMLX_LOG_DEBUG, "Mouse Pressed");
	component = get_component_at(igmlx, (t_uvec_2){(unsigned int)x,
			(unsigned int)y});
	if (key == 1 && component && component->base.type == IGMLX_COMPONENT_BUTTON)
	{
		if (((t_igmlx_button_component *)component)->press
			&& ((t_igmlx_button_component *)component)->data
			&& !component->base.last_change_state_timer.started)
		{
			component->base.state = IGMLX_STATE_PRESSED;
			start_timer(&component->base.last_change_state_timer);
			((t_igmlx_button_component *)component)->press(((t_igmlx_button_component *)component)->data);
		}
	}
	return (0);
}
