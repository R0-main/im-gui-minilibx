/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:27:10 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 11:49:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"
#include <zlib.h>

typedef struct s_igmlx_iend_chunk
{
	unsigned int			crc;
}							t_igmlx_iend_chunk;

typedef struct s_igmlx_idat_chunk
{
	unsigned int			cmf;
	unsigned int			flg;
}							t_igmlx_idat_chunk;

typedef struct s_igmlx_plte_png_color
{
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}							t_igmlx_plte_png_color;

typedef struct s_igmlx_plte_chunk
{
	t_igmlx_plte_png_color	palette[256];
}							t_igmlx_plte_chunk;

typedef struct s_igmlx_ihdr_chunk
{
	unsigned int			width;
	unsigned int			heigth;
	unsigned char			depth;
	unsigned char			color_type;
	unsigned char			compression;
	unsigned char			filter;
	unsigned char			interlace;
	// crc
}							t_igmlx_ihdr_chunk;

typedef struct s_igmlx_png
{
	t_igmlx_ihdr_chunk		header;
	t_igmlx_plte_chunk		palette;
	t_igmlx_idat_chunk		idats[5];
	t_igmlx_iend_chunk		end;
	// crc
}							t_igmlx_png;

typedef enum e_igmlx_png_chunk_type
{
	IHDR,
	PLTE,
	IDAT,
	IEND,
}							t_e_igmlx_png_chunk_type;

void	igmlx_reverse_bytes_order(void *bytes, unsigned int len)
{
	unsigned char	tmp;
	unsigned int	i;

	tmp = 0;
	i = 0;
	while (i < len / 2)
	{
		tmp = ((unsigned char *)bytes)[i];
		((unsigned char *)bytes)[i] = ((unsigned char *)bytes)[len - i - 1];
		((unsigned char *)bytes)[len - i - 1] = tmp;
		i++;
	}
	// for (size_t i = 0; i < len; i++)
	// {
	// 	printf("%02x", ((unsigned char *)bytes)[i]);
	// }
	// printf("\n");
}

void	handle_ihdr(int fd, t_igmlx_png *png, unsigned int chunk_size)
{
	t_igmlx_ihdr_chunk	chunk;

	ft_bzero(&chunk, chunk_size);
	if (read(fd, &chunk, chunk_size) != chunk_size)
		return (_error("failed to read png file"), (void)0);
	// printf("after read :\n");
	// for (size_t i = 0; i < chunk_size; i++)
	// {
	// 	printf("%02x", ((unsigned char *)&chunk)[i]);
	// }
	// printf("\n");
	// printf("after reverse :\n");
	igmlx_reverse_bytes_order(((unsigned char *)&chunk), 4);      // width
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 4), 4);  // height
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 8), 1);  // depth
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 9), 1);  // color_type
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 10), 1); // compression
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 11), 1); // filter
	igmlx_reverse_bytes_order(((unsigned char *)&chunk + 12), 1); // interlace
	printf("width : %u\n", chunk.width);
	printf("height : %u\n", chunk.heigth);
	printf("depth : %u\n", chunk.depth);
	printf("color type : %u\n", chunk.color_type);
	printf("compression methode : %u\n", chunk.compression);
	printf("filter methode : %u\n", chunk.filter);
	printf("interlace methode : %u\n", chunk.interlace);
	png->header = chunk;
}

void	handle_plte(int fd, t_igmlx_png *png, unsigned int chunk_size)
{
	int						i;
	t_igmlx_plte_png_color	color;

	// This chunk shall appear for colour type 3,
	// and may appear for colour types 2 and 6; it shall not appear for colour types 0 and 4.
	// if (color_type == 3 && !plte) errro
	if (chunk_size % 3 != 0 || chunk_size < 1 || chunk_size > 256)
		return (_error("incorrect PLTE chunk size!"));
	i = chunk_size / 3;
	while (i > 0)
	{
		if (read(fd, &color, 3) != 3)
			return (_error("failed to read png file"), (void)0);
		igmlx_reverse_bytes_order(&color, 3);
		png->palette.palette[i] = color;
		i--;
	}
	(void)fd;
}

void print_bits(unsigned char n)
{
	int i = 7;

	while (i >= 0)
	{
		printf("%d ", (n >> i) & 1);
		i--;
	}
	printf("\n");
}

unsigned char reverseBits(unsigned char num) {
    unsigned char reversed = 0;
    int bitCount = 8;  // For an 8-bit number

    while (bitCount--) {
        reversed = (reversed << 1) | (num & 1);  // Shift reversed bits and add the LSB of num
        num >>= 1;  // Shift num to the right by 1 bit
    }

    return reversed;
}

void	handle_idat(int fd, t_igmlx_png *png, unsigned int chunk_size)
{
	unsigned char			buffer[2];

	// pass the first 2 zlib bytes
	if (read(fd, buffer, 2) != 2)
		return (_error("failed to read png file"), (void)0);

	unsigned char			is_last;
	if (read(fd, &is_last, 1) != 1)
		return (_error("failed to read png file"), (void)0);
	// igmlx_reverse_bytes_order(&is_last, 1);
	// is_last = 0b11101101;
	is_last = reverseBits(is_last);
	is_last = 0b10111011;
	printf("last DEFLATE block : %d\n", (is_last << 0) & 1);
	unsigned char type = (is_last << 1);
	type = type >> 6;
	// print_bits(is_last);
	// printf("DEFLATE block type : %d\n", 0b11011010);
	// printf("DEFLATE block type : %d\n", type);
	// print_bits(type);
	if (type == 0) // uncompressed
	{

	}
	else if (type == 1) // Compressed with fixed Huffman codes
	{

	}
	else if (type == 2) // Compressed with dynamic Huffman codes
	{

	}
	else if (type == 3)
	{
		// error
	}


	(void)png;
	(void)chunk_size;
}

unsigned int	igmlx_get_chunk_type(int fd, t_igmlx_png *png,
		unsigned int chunk_size)
{
	unsigned char	ihdr[4] = {0x49, 0x48, 0x44, 0x52};
	unsigned char	iend[4] = {0x49, 0x45, 0x4E, 0x44};
	unsigned char	plte[4] = {0x50, 0x4c, 0x54, 0x45};
	unsigned char	idat[4] = {0x49, 0x44, 0x41, 0x54};
	unsigned char	buffer[4];

	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), 0);
	// printf("Buffer :");
	// for (size_t i = 0; i < 4; i++)
	// {
	// 	printf("%02x ", buffer[i]);
	// }
	// printf("\n\n");
	if (memcmp(buffer, ihdr, 4) == 0)
	{
		printf("\n");
		printf("BEGIN IHDR chunk\n");
		handle_ihdr(fd, png, chunk_size);
		printf("END IHDR chunk\n");
	}
	else if (memcmp(buffer, iend, 4) == 0)
	{
		printf("\n");
		printf("BEGIN IEND chunk\n");
		printf("END IEND chunk\n");
	}
	else if (memcmp(buffer, plte, 4) == 0)
	{
		printf("\n");
		printf("BEGIN PLTE chunk\n");
		handle_plte(fd, png, chunk_size);
		printf("END PLTE chunk\n");
	}
	else if (memcmp(buffer, idat, 4) == 0)
	{
		printf("\n");
		printf("BEGIN IDAT chunk\n"); // concat all the IDAT togother ?
		handle_idat(fd, png, chunk_size);
		printf("END IDAT chunk\n");
	}
	else
	{
		// int i = -1;
		// while (++i < chunk_size)
		// {
		// 	read(fd, buffer2, 1);
		// }
		// read(fd, NULL, chunk_size);
	}
	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), 0);
	(void)png;
	return (1);
}

void	igmlx_parse_chunks(int fd, t_igmlx_png *png, t_alpha_img *img)
{
	unsigned int	chunk_size;
	unsigned char	buffer[4];

	if (read(fd, buffer, 4) != 4)
		return (_error("failed to read png file"), (void)0);
	igmlx_reverse_bytes_order(buffer, 4);
	chunk_size = *((unsigned int *)buffer);
	// printf("chunk size : %d\n", chunk_size);
	igmlx_get_chunk_type(fd, png, chunk_size);
	if (read(fd, buffer, 0) != -1)
		igmlx_parse_chunks(fd, png, img);
	(void)img;
}

int	igmlx_open_png_file(const char *path)
{
	int				fd;
	unsigned char	png_magic[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A,
			0x0A};
	unsigned char	buffer[8];
	t_igmlx_png		*png;

	png = malloc(sizeof(t_igmlx_png));
	if (!png)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (_error("failed to load png file"), -1);
	if (read(fd, buffer, 8) != 8)
		return (_error("failed to read png file"), -1);
	if (ft_memcmp(buffer, png_magic, 8) != 0)
		return (_warning("wrong png format"), -1);
	igmlx_parse_chunks(fd, png, NULL);
	free(png);
	return (fd);
}
