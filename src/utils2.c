/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:29:04 by ealbayra          #+#    #+#             */
/*   Updated: 2023/05/20 23:35:24 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

char *ft_itoa(int number)
{
    int n = number;
    int len = 0;
    char *result;

    if(number < 0)
        len++;
    while(n)
    {
        n/=10;
        len++;
    }
    result = (char *)malloc(sizeof(char) * len + 1);
    if(!result)
        return(NULL);
    result[len] = '\0';
    if(number < 0)
    {
        result[0] = '-';
        number = -number;
    }
    while(number)
    {
        result[--len] = number % 10 + '0';
        number /= 10;
    }
    return(result);
}