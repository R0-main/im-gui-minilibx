/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_render_on_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:18:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:04 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_panel_render_on_window(t_igmlx_panel *panel, void *win)
{
	mlx_mouse_get_pos(panel->igmlx->mlx, win, (int *)&panel->igmlx->mouse_pos.x,
	(int *)&panel->igmlx->mouse_pos.y);
	igmlx_render_panel_components_to_window(panel, win);
	panel->igmlx->last_mouse_pos = panel->igmlx->mouse_pos;
}
