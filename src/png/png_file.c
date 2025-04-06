/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:27:10 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/06 12:00:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

typedef struct s_igmlx_iend_chunk
{
	unsigned int crc;
};

typedef struct s_igmlx_idat_chunk
{
	unsigned int cmf;
	unsigned int flg;
};

typedef struct s_igmlx_ihdr_chunk
{
	unsigned int width;
	unsigned int heigth;
	unsigned char depth;
	unsigned char color_type;
	unsigned char compression;
	unsigned char interlaced;
	// crc
};

typedef enum e_igmlx_png_chunk_type
{
	IHDR,
	PLTE,
	IDAT,
	IEND,
};

unsigned int	igmlx_get_chunk_type(int fd, unsigned char *bytes)
{
	unsigned char	ihdr[4] = {0x49, 0x48, 0x44, 0x52};
	unsigned char	iend[4] = {0x49, 0x45, 0x4E, 0x44};
	unsigned char	idat[4] = {0x49, 0x44, 0x41, 0x54};
	unsigned char	buffer[4];

	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), 0);
	if (memcmp(buffer, ihdr, 4) == 0)
	{

	}
	else if (memcmp(buffer, iend, 4) == 0)
	{

	}
	else if (memcmp(buffer, idat, 4) == 0)
	{
		
	}

}

unsigned int	igmlx_read_big_endian_bytes(unsigned char *bytes,
		unsigned int len)
{
	unsigned int	result;
	unsigned int	i;

	result = 0;
	i = 0;
	while (i < len)
	{
		result <<= 8;
		result |= bytes[i++];
	}
	return (result);
}

void	igmlx_parse_chunks(int fd, t_alpha_img *img)
{
	unsigned int	chunk_size;
	unsigned char	buffer[4];

	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), (void)0);
	chunk_size = igmlx_read_big_endian_bytes(buffer, 4);
	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), (void)0);
	printf("%d\n", chunk_size);
	(void)img;
}

int	igmlx_open_png_file(const char *path)
{
	int				fd;
	unsigned char	png_magic[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A,
			0x0A};
	unsigned char	buffer[8];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (_error("failed to load png file"), -1);
	if (read(fd, buffer, 8) != 8)
		return (_error("failed to read png file"), -1);
	if (ft_memcmp(buffer, png_magic, 8) != 0)
		return (_warning("wrong png format"), -1);
	igmlx_parse_chunks(fd, NULL);
	return (fd);
}
