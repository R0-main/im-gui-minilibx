/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:26:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:10:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	_log(t_e_igmlx_log_level level, const char *msg)
{
	ft_fprintf(STDOUT_FILENO,
		BHBLK "[" BMAG IGMLX_LOG_PREFIX BHBLK "]" RESET " ");
	if (level == IGMLX_LOG_INFO)
		ft_fprintf(STDOUT_FILENO, BHBLK "[" BCYN "Info" BHBLK "]" RESET " ");
	if (level == IGMLX_LOG_DEBUG)
		ft_fprintf(STDOUT_FILENO, BHBLK "[" BBLU "Debug" BHBLK "]" RESET " ");
	if (level == IGMLX_LOG_WARNING)
		ft_fprintf(STDOUT_FILENO, BHBLK "[" BYEL "Warning" BHBLK "]" RESET " ");
	if (level == IGMLX_LOG_ERROR)
		ft_fprintf(STDOUT_FILENO, BHBLK "[" BRED "Error" BHBLK "]" RESET " ");
	ft_fprintf(STDOUT_FILENO, WHT "%s\n", msg);
}

void	_info(const char *msg)
{
	_log(IGMLX_LOG_INFO, msg);
}

void	_debug(const char *msg)
{
	_log(IGMLX_LOG_DEBUG, msg);
}

void	_warning(const char *msg)
{
	_log(IGMLX_LOG_WARNING, msg);
}

void	_error(const char *msg)
{
	_log(IGMLX_LOG_ERROR, msg);
}
