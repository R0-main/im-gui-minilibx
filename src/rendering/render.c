/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void	render_component(t_igmlx *igmlx, void *win,
		t_igmlx_default_component *component)
{
	t_img	*img;

	if (!component)
		return ;
	if (component->base.last_change_state_timer.started
		&& is_timer_finished(&component->base.last_change_state_timer))
	{
		if (is_inside_rectangle(component->base.pos,
				(t_uvec_2){component->base.collision_box.x
				+ component->base.pos.x, component->base.collision_box.y
				+ component->base.pos.y}, igmlx->mouse_pos))
			component->base.state = IGMLX_STATE_HOVERED;
		else
		component->base.state = IGMLX_STATE_DEFAULT;
		component->base.last_change_state_timer.started = false;
	}
	img = get_component_image(component);
	if (!img)
		return ;
	mlx_put_image_to_window(igmlx->mlx, win, img, component->base.pos.x,
		component->base.pos.y);
}

void	igmlx_render_window_components(t_igmlx *igmlx, void *win)
{
	t_win_data	*data;
	t_list		*current;

	data = get_window_data(igmlx, win);
	if (!data)
		return ;
	current = data->components;
	while (current)
	{
		render_component(igmlx, win,
			(t_igmlx_default_component *)current->content);
		current = current->next;
	}
}

int	igmlx_render(t_igmlx *igmlx, void *win)
{
	mlx_mouse_get_pos(igmlx->mlx, win, (int *)&igmlx->mouse_pos.x,
		(int *)&igmlx->mouse_pos.y);
	render_window_components(igmlx, win);
	igmlx->last_mouse_pos = igmlx->mouse_pos;
	return (0);
}
