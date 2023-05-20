/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:46:42 by yerkiral          #+#    #+#             */
/*   Updated: 2023/05/20 22:58:56 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*put_line(char *buffer, int *bf) // cakma get_next_line
{
	char	*line;
	int		buffer_index;
	int		line_length;
	int		index;

	buffer_index = (*bf);
	line_length = 0;
	index = buffer_index;
	while (buffer[buffer_index] != '\n' && buffer[buffer_index] != '\0')
	{
		line_length++;
		buffer_index++;
	}
	(*bf) += line_length + 1;
	buffer_index = index;
	index = 0;
	line = (char *) malloc(sizeof(char) * (line_length + 1));
	while (index < line_length)
		line[index++] = buffer[buffer_index++];
	line[index] = '\0';
	return (line);
}

static int	count_nl(char *buffer, int size) // newline counter
{
	int	enter;
	int	i;

	i = 0;
	enter = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

static char	**map_builder(char *buffer, int size, t_game *sl)
{
	int		enter;
	int		index;
	int		bf;
	char	**map;

	index = 0;
	bf = 0;
	enter = count_nl(buffer, size); // newline sayisini enter'a atama
	sl->map_height = enter;
	map = (char **) malloc(sizeof(char *) * enter); // height-newline kadar map degiskenine malloc ile yer aciliyor 
	while (index < enter)
	{
		map[index] = put_line(buffer, &bf); // cakma gnl ile map'in kutucuklarina yerlestirme? ASK HIM
		index++;
	}
	return (map);
}

char	**map_constractor(t_game *game, int fd) // dosyayi/ map'i okuma
{
	char	buffer[10000];
	int		i;
	int		bytes;

	bytes = 1;
	i = 0;
	ft_reset(buffer); // neden resetliyoruz? ASK HIM
	while (bytes)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
		{
			free(game);
			exit(1);
		}
		i++;
	}
	return (map_builder(buffer, i, game));
}
