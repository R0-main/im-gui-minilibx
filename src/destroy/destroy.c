/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:56:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 16:01:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_destroy(t_igmlx *igmlx)
{
	_info("Destroyed !");
	if (!igmlx)
		return ;
	igmlx_destroy_fonts_list(igmlx, &igmlx->fonts);
	free(igmlx);
}
