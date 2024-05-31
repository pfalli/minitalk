/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:57 by pfalli            #+#    #+#             */
/*   Updated: 2024/05/24 10:12:57 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		exit_error(void)
{
	ft_printf(RED "\nError\n\n" RESET);
	exit(1);
}

static void		validate_pid(char *pid)
{
	int		i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf(RED "\nInvalid PID\n\nOnly digits are accepted!\n\n" RESET);
			exit(1);
		}
		i++;
	}
}

// bitwise AND operator to isolate after the shifting
void	signals_send(char c, int pid)
{
	int		bit;
	int		i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_error();
		}
		else if (bit == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error();
		}
		usleep(100);
		i--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		pid;

	if (argc != 3)
	{
		ft_printf(RED "\nError on amount of arguments!\n\n" RESET);
		ft_printf("How to write ==> ./client <PID> <MESSAGE>\n\n");
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf(RED "\nInvalid PID! Use only positive numbers!\n\n" RESET);
		return (1);
	}
	validate_pid(argv[1]);
	while (argv[2][i])
	{
		signals_send(argv[2][i], pid);
		i++;
	}
	signals_send((char)4, pid);
	return (0);
}