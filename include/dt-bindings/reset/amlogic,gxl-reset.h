/*
 * include/dt-bindings/reset/amlogic,gxl-reset.h
 *
 * Copyright (C) 2017 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */

#ifndef _DT_BINDINGS_AMLOGIC_MESON_GXBB_RESET_H
#define _DT_BINDINGS_AMLOGIC_MESON_GXBB_RESET_H

/*	RESET0					*/
#define RESET_HIU			0
/*					1	*/
#define RESET_DOS_RESET			2
#define RESET_DDR_TOP			3
#define RESET_DCU_RESET			4
#define RESET_VIU			5
#define RESET_AIU			6
#define RESET_VID_PLL_DIV		7
/*					8	*/
#define RESET_PMUX			9
#define RESET_VENC			10
#define RESET_ASSIST			11
#define RESET_AFIFO2			12
#define RESET_VCBUS			13
/*					14	*/
/*					15	*/
#define RESET_GIC			16
#define RESET_CAPB3_DECODE		17
/*					18	*/
#define RESET_HDMITX_CAPB3		19
#define RESET_MALI_CAPB3		20
#define RESET_DOS_CAPB3			21
#define RESET_SYS_CPU_CAPB3		22
#define RESET_CBUS_CAPB3		23
#define RESET_AHB_CNTL			24
#define RESET_AHB_DATA			25
#define RESET_VCBUS_CLK81		26
#define RESET_MMC			27
/*					28	*/
/*					29	*/
/*					30	*/
/*					31	*/
/*	RESET1					*/
#define RESET_CPPM			32
#define RESET_DEMUX			33
#define RESET_USB_OTG			34
#define RESET_DDR			35
#define RESET_AO_RESET			36
#define RESET_BT656			37
#define RESET_AHB_SRAM			38
/*					39	*/
#define RESET_PARSER			40
#define RESET_BLKMV			41
#define RESET_ISA			42
#define RESET_ETHERNET			43
#define RESET_SD_EMMC_A			44
#define RESET_SD_EMMC_B			45
#define RESET_SD_EMMC_C			46
#define RESET_ROM_BOOT			47
#define RESET_SYS_CPU_0			48
#define RESET_SYS_CPU_1			49
#define RESET_SYS_CPU_2			50
#define RESET_SYS_CPU_3			51
#define RESET_SYS_CPU_CORE_0		52
#define RESET_SYS_CPU_CORE_1		53
#define RESET_SYS_CPU_CORE_2		54
#define RESET_SYS_CPU_CORE_3		55
#define RESET_SYS_PLL_DIV		56
#define RESET_SYS_CPU_AXI		57
#define RESET_SYS_CPU_L2		58
#define RESET_SYS_CPU_P			59
#define RESET_SYS_CPU_MBIST		60
#define RESET_AUDIO_CODEC		61
/*					62	*/
/*					63	*/
/*	RESET2					*/
#define RESET_VD_RMEM			64
#define RESET_AUDIN			65
#define RESET_HDMI_TX			66
/*					67	*/
/*					68	*/
/*					69	*/
#define RESET_GE2D			70
#define RESET_PARSER_REG		71
#define RESET_PARSER_FETCH		72
#define RESET_PARSER_CTL		73
#define RESET_PARSER_TOP		74
/*					75	*/
/*					76	*/
#define RESET_AO_CPU_RESET		77
#define RESET_MALI			78
#define RESET_HDMI_SYSTEM_RESET		79
/*					80-95	*/
/*	RESET3					*/
#define RESET_RING_OSCILLATOR		96
#define RESET_SYS_CPU			97
#define RESET_EFUSE			98
#define RESET_SYS_CPU_BVCI		99
#define RESET_AIFIFO			100
#define RESET_TVFE			101
#define RESET_AHB_BRIDGE_CNTL		102
/*					103	*/
/*					104	*/
#define RESET_DEMUX_TOP			105
#define RESET_DEMUX_DES			106
#define RESET_DEMUX_S2P_0		107
#define RESET_DEMUX_S2P_1		108
#define RESET_DEMUX_RESET_0		109
#define RESET_DEMUX_RESET_1		110
#define RESET_DEMUX_RESET_2		111
/*					112-127	*/
/*	RESET4					*/
/*					128	*/
/*					129	*/
/*					130	*/
/*					131	*/
#define RESET_DVIN_RESET		132
#define RESET_RDMA			133
#define RESET_VENCI			134
#define RESET_VENCP			135
/*					136	*/
#define RESET_VDAC			137
#define RESET_RTC			138
/*					139	*/
#define RESET_VDI6			140
#define RESET_VENCL			141
#define RESET_I2C_MASTER_2		142
#define RESET_I2C_MASTER_1		143
/*					144-159	*/
/*	RESET5					*/
/*					160-191	*/
/*	RESET6					*/
#define RESET_PERIPHS_GENERAL		192
#define RESET_PERIPHS_SPICC		193
#define RESET_PERIPHS_SMART_CARD	194
#define RESET_PERIPHS_SAR_ADC		195
#define RESET_PERIPHS_I2C_MASTER_0	196
#define RESET_SANA			197
/*					198	*/
#define RESET_PERIPHS_STREAM_INTERFACE	199
#define RESET_PERIPHS_SDIO		200
#define RESET_PERIPHS_UART_0		201
#define RESET_PERIPHS_UART_1_2		202
#define RESET_PERIPHS_ASYNC_0		203
#define RESET_PERIPHS_ASYNC_1		204
#define RESET_PERIPHS_SPI_0		205
#define RESET_PERIPHS_SDHC		206
#define RESET_UART_SLIP			207
/*					208-223	*/
/*	RESET7					*/
#define RESET_USB_DDR_0			224
#define RESET_USB_DDR_1			225
#define RESET_USB_DDR_2			226
#define RESET_USB_DDR_3			227
/*					228	*/
#define RESET_DEVICE_MMC_ARB		229
/*					230	*/
#define RESET_VID_LOCK			231
#define RESET_A9_DMC_PIPEL		232
/*					233-255	*/

#endif
