/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:34 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/17 10:54:33 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_parse  parse;
    
    if (argc != 2)
        ft_helper();
    else
    {
        parse = ft_parse(argv, &parse);
    }
    return (0);
}