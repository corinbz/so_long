/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:13:55 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/17 15:07:16 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void ft_error(char *error_txt)
{
	perror(error_txt);
	mlx_strerror(mlx_errno);
	exit(EXIT_FAILURE);
}