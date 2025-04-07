/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_add_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:12:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:26:29 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_button_component *igmlx_panel_add_button_component(t_igmlx_panel *panel)
{
	t_igmlx_button_component *button;

	button = igmlx_create_button_component(panel);
	if (!button)
		return (NULL);
	igmlx_panel_add_component(panel, (t_igmlx_component *)button);
	return (button);
}
