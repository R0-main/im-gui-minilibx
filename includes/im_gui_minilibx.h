/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_gui_minilibx.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 13:21:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IM_GUI_MINILIBX_H
# define IM_GUI_MINILIBX_H

# include "mlx.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void	*instance;
	void	*window;
}			t_mlx;

typedef struct s_igmlx
{
	void	*mlx;

}			t_igmlx;

t_igmlx		*igmlx_init(void *mlx);
bool		igmlx_hook(t_igmlx *igmlx);

#endif
