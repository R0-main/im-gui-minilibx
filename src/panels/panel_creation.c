/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:57 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 13:23:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

//attach to window
//attach to buffer



t_igmlx_panel *create_panel(t_igmlx *igmlx)
{
	t_igmlx_panel *panel;

	panel = balloc(sizeof(t_igmlx_panel));
	if (!panel)
		return (NULL);
	panel->igmlx = igmlx;
	panel->render_on_window = igmlx_panel_render_on_window;
	panel->render_on_buffer =
}
