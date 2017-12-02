/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:21:28 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/01 19:23:02 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find_end(t_list *list)
{
	if (list->next == NULL)
		return (list);
	return (ft_list_find_end(list->next));
}
