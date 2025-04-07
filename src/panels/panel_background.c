/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:56:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 14:58:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_change_panel_background_color(t_igmlx_panel *panel, t_color color)
{
	panel->base.states[panel->base.state].backgroud_color = color;
}
