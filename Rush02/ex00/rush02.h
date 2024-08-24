/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeddah <almeddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:47:07 by almeddah          #+#    #+#             */
/*   Updated: 2024/08/24 16:30:56 by almeddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include "get_next_line/get_next_line.h"

typedef struct s_list1
{
	char			*nb;
	char			*trad;
	struct s_list1	*next;
}					t_list1;

char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				**ft_split(char *str, char *sep);

#endif
