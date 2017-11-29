/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/11/29 14:45:30 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

static	int	ft_error(void)
{
	ft_putendl(strerror(errno));
	exi(1);
}

int			main(void)
{
	int			ret;
	char*		content;
	t_lem_in	data;

	while ((ret = get_next_line(STDIN_FILENO, &content)) > 0)
	{
			ft_parser(&data, &content);
	}
	if (close(STDIN_FILENO) < 0)
		ft_error();
	return (0);
}
