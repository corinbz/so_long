/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:41:30 by ccraciun          #+#    #+#             */
/*   Updated: 2024/04/22 14:08:00 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static bool	map_size_valid(t_map *map)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_line_len(map->cell_value[0]);
	if(len > MAX_MAP_WIDTH)
		return(ft_error("Width too big\n") ,false);
	map->width = len;
	while(i < map->height)
	{
		if(ft_line_len(map->cell_value[i]) != len)
			return (ft_error("Invalid row length\n"), false);
		i++;
	}
	return (true);
}

static bool	check_walls(size_t row, size_t col, t_map *map)
{
	while (row < map->height)
	{
		while(col < map->width)
		{
			printf("%c", map->cell_value[row][col]);
			if (col == 0 || col == map->width)
			{
				if ((map->cell_value[row][col]) != '1')
					return (ft_error("incomplete wall\n"),false);
			}
			if (row == 0 || row == map->height)
			{
				if ((map->cell_value[row][col]) != '1')
				{
					return (ft_error("incomplete wall\n"),false);
				}
			}
			col++;
		}
		printf("\n");
		col = 0;
		row++;
	}
	return (true);
}

static bool	check_elements_count(t_count *count)
{
	if ((int)count->player != 1
		|| (int)count->exit != 1
		|| (int)count->collectible == 0)
		return (ft_error("Invalid elements count\n"), false);
	return (true);
}

static void	increment_elements(char cell, t_count *count)
{
	if (cell == 'P')
		count->player++;
	else if (cell == 'C')
		count->collectible++;
	else if (cell == 'E')
		count->exit++;
}

static bool	count_elements(size_t row, size_t col, t_map *map)
{
	char	cell;
	t_count	count;

	count = (t_count){0};
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			cell = map->cell_value[row][col];
			if (cell == '1' || cell == '0')
			{
				col++;
				continue ;
			}
			else if (cell == 'P' || cell == 'C' || cell == 'E')
				increment_elements(cell, &count);
			else
				return (ft_error("Invalid character found\n"), false);
			col++;
		}
		row++;
	}
	return (check_elements_count(&count));
}

static	bool check_map_elements(t_map *map)
{
	bool	res;
	size_t	row;
	size_t	col;

	// res = true;
	row = 0;
	col = 0;
	res = map_size_valid(map) && check_walls(row, col, map)
		&& count_elements(row, col, map);
	// res = check_walls(row, col, map);
	// res = count_elements(row, col, map);
	// printf("res: %d\n",res);
	return (res);
}
static bool get_rows_size(t_map *map, char *map_filename)
{
	int		map_fd;
	char	*line;
	size_t	rows;

	rows = 0;
	map_fd = open(map_filename, O_RDONLY);
	if (map_fd < 0)
		ft_error("Failed to open map file\n");
	line = get_next_line(map_fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	if(rows > MAX_MAP_HEIGHT || rows < 3)
		return(ft_error("Map height is invalid\n"), false);
	map->height = rows;
	return (true);
}

bool	parse_map(t_map *map, char *map_filename)
{
	if(!get_rows_size(map, map_filename))
		return(false);
	printf("rows: %zu\n", map->height);
	map->valid = get_map_elements(map, map_filename);
	if(!map->valid)
		return (false);
	map->valid = check_map_elements(map);
	if(!map->valid)
		return (false);
	return (true);
}
