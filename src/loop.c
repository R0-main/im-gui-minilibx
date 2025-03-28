/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:24:10 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 15:26:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

int igmlx_loop(t_igmlx *igmlx)
{
	(void)igmlx;
	ft_fprintf(STDOUT_FILENO, "igmlx_hook !\n");
	return (0);
}
