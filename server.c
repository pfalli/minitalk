/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:53 by pfalli            #+#    #+#             */
/*   Updated: 2024/05/24 10:12:53 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_intro(void)
{
	ft_printf(YELLOW);
	ft_printf("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_printf("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_printf("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_printf("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_printf("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_printf("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
	ft_printf("            Created By: pfalli\n\n>> " RESET);
}

// print newline --  when ch is equal to 4, the function will print a newline character before 
// resetting ch and bit. This means that when the client sends the End of Transmission character, the server will print a newline.

static void		signal_handler(int signum)
{
	static unsigned char	ch;
	static int				bit;

	if (signum == SIGUSR1)
		ch |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (ch == 4)
		{
			ft_printf("\n"); 
			ch = 0;
			bit = 0;
			return ;
		}
		ft_printf("%c", ch);
		ch = 0;
		bit = 0;
	}
}

static void		signal_reception(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

int		main(void)
{
	print_intro();
	ft_printf("Server's PID: %d\n\n", getpid());
	while (1)
		signal_reception();
	return (0);
}