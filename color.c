/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:25:00 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 21:25:09 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pallette1(int tab[30])
{
	tab[0] = 0x31698A;
	tab[1] = 0x2181AC;
	tab[2] = 0x1199CE;
	tab[3] = 0x01B0F0;
	tab[4] = 0x01B0F0;
	tab[5] = 0x01B0F0;
	tab[6] = 0x01B0F0;
	tab[7] = 0x01B0F0;
	tab[8] = 0x01B0F0;
	tab[9] = 0x01B0F0;
	tab[10] = 0x01B0F0;
	tab[11] = 0xffeb7f;
	tab[12] = 0x71A12F;
	tab[13] = 0x65902a;
	tab[14] = 0x5a8025;
}

void	fill_pallette2(int tab[30])
{
	tab[15] = 0x4f7020;
	tab[16] = 0x5a8025;
	tab[17] = 0x65902a;
	tab[18] = 0x71A12F;
	tab[19] = 0x8a745a;
	tab[20] = 0x8a745a;
	tab[21] = 0x7d6548;
	tab[22] = 0x7d6548;
	tab[23] = 0x705a40;
	tab[24] = 0x705a40;
	tab[25] = 0x645039;
	tab[26] = 0x645039;
	tab[27] = 0xFFFFFF;
	tab[28] = 0xFFFFFF;
	tab[29] = 0xFFFFFF;
}

void	fill_pallette(int tab[30])
{
	fill_pallette1(tab);
	fill_pallette2(tab);
}
