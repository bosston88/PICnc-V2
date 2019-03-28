/*    Copyright (C) 2014 GP Orcullo
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PICNC_H
#define PICNC_H

enum pin_input_names {
	HOME_X,
	HOME_Y,
	HOME_Z,
	HOME_A,
	STOP
};

enum pin_output_names {
	SPINDLE,
	MIST,
	FLOOD,
	OUTPUT
};

#define NUMAXES			4		/* X Y Z A*/
#define PWMCHANS		3
#define NUMOUTPUTS		4
#define NUMINPUTS		5

#define REQ_TIMEOUT		10000ul

#define SPIBUFSIZE		20		/* SPI buffer size */
#define BUFSIZE			(SPIBUFSIZE/4)

#define STEPBIT			22		/* bit location in DDS accum */
#define STEP_MASK		(1<<STEPBIT)

#define BASEFREQ		80000ul		/* Base freq of the PIC stepgen in Hz */
#define SYS_FREQ		(40000000ul)    /* 40 MHz */

#define PERIODFP 		((double)1.0 / (double)(BASEFREQ))
#define VELSCALE		((double)STEP_MASK * PERIODFP)
#define ACCELSCALE		(VELSCALE * PERIODFP)

#define get_position(a)		(rxBuf[1 + (a)])
#define update_velocity(a, b)	(txBuf[1 + (a)] = (b))

#define PAGE_SIZE		(4*1024)
#define BLOCK_SIZE		(4*1024)

#define CMD_CFG			0x4746433E
#define CMD_TST			0x5453543E
#define CMD_CM1			0x314D433E
#define CMD_CM2			0x324D433E
#define CMD_RST			0x5453523E

/* Broadcom defines */

#define BCM2835_SPICLKDIV	32		/* ~8 Mhz */

#define BCM2835_PERI_BASE	0x20000000
#define BCM2709_OFFSET		0x1F000000
#define BCM2835_GPIO_BASE	(BCM2835_PERI_BASE + 0x200000) /* GPIO controller */
#define BCM2835_SPI_BASE	(BCM2835_PERI_BASE + 0x204000) /* SPI controller */

#define BCM2835_GPFSEL0		*(mem1)
#define BCM2835_GPFSEL1		*(mem1 + 1)
#define BCM2835_GPFSEL2		*(mem1 + 2)
#define BCM2835_GPFSEL3		*(mem1 + 3)
#define BCM2835_GPFSEL4		*(mem1 + 4)
#define BCM2835_GPFSEL5		*(mem1 + 5)
#define BCM2835_GPSET0		*(mem1 + 7)
#define BCM2835_GPSET1		*(mem1 + 8)
#define BCM2835_GPCLR0		*(mem1 + 10)
#define BCM2835_GPCLR1		*(mem1 + 11)
#define BCM2835_GPLEV0		*(mem1 + 13)
#define BCM2835_GPLEV1		*(mem1 + 14)

#define BCM2835_SPICS 		*(mem2 + 0)
#define BCM2835_SPIFIFO     	*(mem2 + 1)
#define BCM2835_SPICLK 		*(mem2 + 2)

#define BCM_SPI_CS_DONE		0x00010000
#define BCM_SPI_CS_TA		0x00000080
#define BCM_SPI_CS_CLEAR_RX	0x00000020
#define BCM_SPI_CS_CLEAR_TX	0x00000010
#define BCM_SPI_CS_CPHA		0x00000004

#endif
