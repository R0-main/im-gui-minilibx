/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_render_on_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:18:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 13:26:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

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

void	igmlx_panel_render_on_window(t_igmlx_panel *panel, void *win)
{
	mlx_mouse_get_pos(panel->igmlx->mlx, win, (int *)&panel->igmlx->mouse_pos.x,
		(int *)&panel->igmlx->mouse_pos.y);
	igmlx_render_window_components(panel->igmlx, win);
	panel->igmlx->last_mouse_pos = panel->igmlx->mouse_pos;
	return (0);
}
