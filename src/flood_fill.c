/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:42:00 by corin             #+#    #+#             */
/*   Updated: 2024/04/20 16:33:40 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
void ft_print_map(char **map, size_t height, size_t width);

void	flood_fill(size_t row, size_t col, t_game game, char **map)
{
	if (row >= game.map.height || row >= game.map.width
		|| map[row][col] == '1'
		|| map[row][col] == 'V')
		return;
	map[row][col] = 'V';
	flood_fill (row -1, col, game, map);
	flood_fill (row +1, col, game, map);
	flood_fill (row, col -1, game, map);
	flood_fill (row, col +1, game, map);
}
static bool	check_coll_exists(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		while (j < game->map.width)
			{
				if(map[i][j] == 'C')
				{
					printf("at pos %zu %zu\n",i, j);
					return (ft_error("Collectible not accesible\n"),false);
				}
				j++;
			}
		j = 0;
		i++;
	}
	return (true);
}
bool	collectibles_accesible(t_game *game)
{
	size_t	row;
	bool	res;

	row = 0;
	res = true;
	char **map_copy = ft_calloc(game->map.height + 1, sizeof(char *));
	if(!map_copy)
		return(ft_error("malloc failed\n"), NULL);
	while(row < game->map.height)
	{
		map_copy[row] = ft_strdup(game->map.cell_value[row]);
		if(!map_copy[row])
			return(ft_error("malloc failed\n"), ft_free_2d(map_copy), NULL);
		row++;
	}
	flood_fill(game->player_pos.x, game->player_pos.y, *game, map_copy);
	res = check_coll_exists(map_copy, game);
	res = true;
	ft_free_2d(map_copy);
	return (res);
}
