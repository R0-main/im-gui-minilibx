/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 15:44:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "colors.h"
# include "ft_fprintf.h"
# include "igmlx.h"
# include "libft.h"
# include "timer.h"

# define IGMLX_LOG_PREFIX "IGMLX"

# define IGMLX_BUTTON_DEFAULT                                                 \
	(t_igmlx_button_component)                                               \
	{                                                                        \
		(t_igmlx_component){IGMLX_COMPONENT_BUTTON,                          \
							(t_uvec_2){50, 50},                              \
							(t_uvec_2){50, 50},                              \
							NULL,                                            \
							(t_timer){500, (t_time){0}, (t_time){0}, false}, \
							IGMLX_STATE_DEFAULT,                             \
							{                                                \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
							}},                                              \
			NULL, NULL, NULL, NULL, NULL,                                    \
	}

typedef int						t_color;

typedef struct s_uvec_2
{
	unsigned int				x;
	unsigned int				y;
}								t_uvec_2;

typedef enum e_igmlx_state
{
	IGMLX_STATE_DEFAULT,
	IGMLX_STATE_HOVERED,
	IGMLX_STATE_PRESSED,

	IGMLX_STATE_COUNT
}								t_e_igmlx_state;

typedef enum e_igmlx_corner
{
	IGMLX_CORNER_TOP_LEFT,
	IGMLX_CORNER_BOTTOM_LEFT,
	IGMLX_CORNER_TOP_RIGHT,
	IGMLX_CORNER_BOTTOM_RIGHT,

	IGMLX_CORNER_COUNT
}								t_e_igmlx_corner;

typedef enum e_igmlx_log_level
{
	IGMLX_LOG_DEBUG,
	IGMLX_LOG_INFO,
	IGMLX_LOG_WARNING,
	IGMLX_LOG_ERROR
}								t_e_igmlx_log_level;

typedef enum e_igmlx_component_type
{
	IGMLX_COMPONENT_BUTTON,
}								t_e_igmlx_component_type;

typedef struct s_igmlx_component_state
{
	t_color						backgroud_color;
	t_color						text_color;
	int							size_mutliplier;
	int							opacity;
	unsigned int				borders_radius[IGMLX_CORNER_COUNT];
	t_img						*render;
}								t_igmlx_component_state;

typedef struct s_igmlx_component
{
	t_e_igmlx_component_type	type;
	t_uvec_2					collision_box;
	t_uvec_2					pos;
	void						*win;
	t_timer						last_change_state_timer;
	t_e_igmlx_state				state;
	t_igmlx_component_state		states[IGMLX_STATE_COUNT];
}								t_igmlx_component;

typedef struct s_igmlx_default_component
{
	t_igmlx_component			base;
}								t_igmlx_default_component;

typedef struct s_igmlx_button_component
{
	t_igmlx_component			base;
	void						*data;
	void						(*press)(void *);
	void						(*touch)(void *);
	void						(*leave)(void *);
	void						(*hover)(void *);
}								t_igmlx_button_component;

typedef struct s_win_data
{
	void						*win;
	t_list						*components;
}								t_win_data;

typedef struct s_igmlx
{
	void						*mlx;
	t_list						*wins_data;
	t_uvec_2					mouse_pos;
	t_uvec_2					last_mouse_pos;
	t_igmlx_default_component	*last_hovered_component;
}								t_igmlx;

int								igmlx_loop(t_igmlx *igmlx);

void							_log(t_e_igmlx_log_level level,
									const char *msg);

t_win_data						*get_window_data(t_igmlx *igmlx, void *win);
bool							add_to_window_data(t_igmlx *igmlx, void *win,
									void *component);

// COMPONENTS
void							init_component_states_images(t_igmlx *igmlx,
									t_igmlx_default_component *component);
t_igmlx_component_state			get_component_state(t_igmlx_default_component *component);
t_img							*get_component_image(t_igmlx_default_component *component);

int								mouse_motion(int x, int y, t_igmlx *igmlx);
int								release_mouse(int key, int x, int y,
									t_igmlx *igmlx);
int								press_mouse(int key, int x, int y,
									t_igmlx *igmlx);

t_igmlx_default_component		*get_win_component_at(t_igmlx *igmlx, void *win,
									t_uvec_2 coords);

t_igmlx_default_component		*get_component_at(t_igmlx *igmlx,
									t_uvec_2 coords);

// UTILS
bool							is_inside_rectangle(t_uvec_2 p1, t_uvec_2 p2,
									t_uvec_2 target);

#endif
