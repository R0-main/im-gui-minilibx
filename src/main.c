/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:15:20 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:06:18 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "igmlx.h"
#include "ft_fprintf.h"

void hook(t_mlx *mlx)
{
	(void)mlx;
	ft_fprintf(STDOUT_FILENO, "Hooked !\n");
}
