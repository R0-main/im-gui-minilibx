/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_destruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:11:57 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:53:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void igmlx_destroy_panel(t_igmlx_panel *panel, t_igmlx *igmlx)
{
	igmlx_free_component(igmlx, (t_igmlx_default_component *)panel);
}
