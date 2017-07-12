/*
 * drivers/amlogic/pinctrl/pinctrl-meson.h
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

#include <linux/gpio.h>
#include <linux/pinctrl/pinctrl.h>
#include <linux/regmap.h>
#include <linux/types.h>

/**
 * struct meson_pmx_group - a pinmux group
 *
 * @name:	group name
 * @pins:	pins in the group
 * @num_pins:	number of pins in the group
 * @is_gpio:	whether the group is a single GPIO group
 * @reg:	register offset for the group in the domain mux registers
 * @bit		bit index enabling the group
 * @domain:	index of the domain this group belongs to
 */
struct meson_pmx_group {
	const char *name;
	const unsigned int *pins;
	unsigned int num_pins;
	bool is_gpio;
	unsigned int reg;
	unsigned int bit;
};

/**
 * struct meson_pmx_func - a pinmux function
 *
 * @name:	function name
 * @groups:	groups in the function
 * @num_groups:	number of groups in the function
 */
struct meson_pmx_func {
	const char *name;
	const char * const *groups;
	unsigned int num_groups;
};

/**
 * struct meson_reg_desc - a register descriptor
 *
 * @reg:	register offset in the regmap
 * @bit:	bit index in register
 *
 * The structure describes the information needed to control pull,
 * pull-enable, direction, etc. for a single pin
 */
struct meson_reg_desc {
	unsigned int reg;
	unsigned int bit;
};

/**
 * enum meson_reg_type - type of registers encoded in @meson_reg_desc
 */
enum meson_reg_type {
	REG_PULLEN,
	REG_PULL,
	REG_DIR,
	REG_OUT,
	REG_IN,
	NUM_REG,
};

/**
 * struct meson bank
 *
 * @name:	bank name
 * @first:	first pin of the bank
 * @last:	last pin of the bank
 * @irq:	irq base number of the bank
 * @regs:	array of register descriptors
 *
 * A bank represents a set of pins controlled by a contiguous set of
 * bits in the domain registers. The structure specifies which bits in
 * the regmap control the different functionalities. Each member of
 * the @regs array refers to the first pin of the bank.
 */
struct meson_bank {
	const char *name;
	unsigned int first;
	unsigned int last;
	int irq;
	struct meson_reg_desc regs[NUM_REG];
};

/**
 * struct meson_domain_data - domain platform data
 *
 * @name:	name of the domain
 * @banks:	set of banks belonging to the domain
 * @num_banks:	number of banks in the domain
 */
struct meson_domain_data {
	const char *name;
	struct meson_bank *banks;
	unsigned int num_banks;
	unsigned int pin_base;
	unsigned int num_pins;
};

/**
  *enum meson_irq_register - registers offset of gpio irq
  */
enum meson_irq_register {
	GPIO_IRQ_EDGE_OFFSET,
	GPIO_IRQ_MUX_0_3,
	GPIO_IRQ_MUX_4_7,
	GPIO_IRQ_FILTER_OFFSET,
};

/**
 * struct meson_gpio_irq_desc - describe the gpio irq
 *
 * @used_flag: indicate the 'parent_virq' whether be used or not
 * @parent_virq: gpio virtual interrupt number
 * @hwirq: hw irq for gpio
 */
struct meson_gpio_irq_desc {
	unsigned char used_flag;
	unsigned int parent_virq;
	unsigned int hwirq;
};

/*struct meson_irq_res - describe resource for gpio irq
 *
 * @irq_num: number of gpio irq
 * @irq_res_lock:
 * @gpio_irq: a pointer to 'struct meson_gpio_irq_desc'
 */
struct meson_irq_resource {
	unsigned char irq_num;
	spinlock_t irq_res_lock;
	struct meson_gpio_irq_desc *gpio_irq;
};

/**
 * struct meson_domain
 *
 * @reg_mux:	registers for mux settings
 * @reg_pullen:	registers for pull-enable settings
 * @reg_pull:	registers for pull settings
 * @reg_gpio:	registers for gpio settings
 * @reg_irq: registers for gpio irq settings
 * @chip:	gpio chip associated with the domain
 * @irq_res: irq resource
 * @data: platform data for the domain
 * @node: device tree node for the domain
 *
 * A domain represents a set of banks controlled by the same set of
 * registers.
 */
struct meson_domain {
	struct regmap *reg_mux;
	struct regmap *reg_pullen;
	struct regmap *reg_pull;
	struct regmap *reg_gpio;
	struct regmap *reg_irq;

	struct gpio_chip chip;
	struct meson_irq_resource irq_res;
	struct meson_domain_data *data;
	struct device_node *of_node;
};

struct meson_pinctrl_data {
	const struct pinctrl_pin_desc *pins;
	struct meson_pmx_group *groups;
	struct meson_pmx_func *funcs;
	const struct meson_desc_pin *meson_pins;
	struct meson_domain_data *domain_data;
	unsigned int num_pins;
	unsigned int num_groups;
	unsigned int num_funcs;
};

struct meson_pinctrl {
	struct device *dev;
	struct pinctrl_dev *pcdev;
	struct pinctrl_desc desc;
	struct meson_pinctrl_data *data;
	struct meson_domain *domain;
};

struct meson_pinctrl_private {
	unsigned char pinmux_type;
	struct meson_pinctrl_data *pinctrl_data;
	struct irq_chip *irq_chip;
	int (*init)(struct meson_pinctrl *pc);
};

struct meson_desc_function {
	const char *name;
	unsigned char muxval;
};

struct meson_desc_pin {
	struct pinctrl_pin_desc pin;
	unsigned int reg;
	unsigned int bit;
	struct meson_desc_function *functions;
};

/* enum PINMUX_TYPE - pinmux type
 *
 *@PINMUX_V1: use more bits that maybe from different registers to choose
 * function for per gpio
 *@PINMUX_V2: use continuous 4bit to choose function for per gpio
 *
 */
enum PINMUX_TYPE {
	PINMUX_V1 = 0,
	PINMUX_V2,
	PINMUX_MAX,
};

#define CMD_TEST_N_DIR 0x82000046
#define TEST_N_OUTPUT  1

#define PIN(x, b)	(b + x)
#define MESON_MUX_V2_MASK(x) (0xf << x)
#define MESON_MUX_V2_VAL(y, x) ((y & 0xf) << x)
#define MESON_PIN(x, b) PINCTRL_PIN(PIN(x, b), #x)

#define GROUP(grp, r, b)						\
	{								\
		.name = #grp,						\
		.pins = grp ## _pins,					\
		.num_pins = ARRAY_SIZE(grp ## _pins),			\
		.reg = r,						\
		.bit = b,						\
	}

#define GPIO_GROUP(gpio, b)						\
	{								\
		.name = #gpio,						\
		.pins = (const unsigned int[]){ PIN(gpio, b) },		\
		.num_pins = 1,						\
		.is_gpio = true,					\
	}

#define FUNCTION(fn)							\
	{								\
		.name = #fn,						\
		.groups = fn ## _groups,				\
		.num_groups = ARRAY_SIZE(fn ## _groups),		\
	}

#define BANK(n, f, l, i, per, peb, pr, pb, dr, db, or, ob, ir, ib)\
	{								\
		.name	= n,						\
		.first	= f,						\
		.last	= l,						\
		.irq    = i,						\
		.regs	= {						\
			[REG_PULLEN]	= { per, peb },			\
			[REG_PULL]	= { pr, pb },			\
			[REG_DIR]	= { dr, db },			\
			[REG_OUT]	= { or, ob },			\
			[REG_IN]	= { ir, ib },			\
		},							\
	}

#define MESON_FUNCTION(_val, _name)				\
	{							\
		.name = _name,					\
		.muxval = _val,					\
	}

#define MESON_PINCTRL_PIN(_pin, r, b, ...)		\
	{							\
		.pin = _pin,					\
		.reg = r,				\
		.bit = b,				\
		.functions = (struct meson_desc_function[]){	\
			__VA_ARGS__, { } },			\
	}

extern struct meson_pinctrl_data meson8_cbus_pinctrl_data;
extern struct meson_pinctrl_data meson8_aobus_pinctrl_data;
extern struct meson_pinctrl_data meson8b_cbus_pinctrl_data;
extern struct meson_pinctrl_data meson8b_aobus_pinctrl_data;
extern struct meson_pinctrl_data meson_gxl_periphs_pinctrl_data;
extern struct meson_pinctrl_data meson_gxl_aobus_pinctrl_data;
extern struct meson_pinctrl_data meson_axg_periphs_pinctrl_data;
extern struct meson_pinctrl_data meson_axg_aobus_pinctrl_data;

extern int meson_gxl_aobus_init(struct meson_pinctrl *pc);
extern int meson_gxl_periphs_init(struct meson_pinctrl *pc);
extern int meson_axg_aobus_init(struct meson_pinctrl *pc);
