/*
 * Copyright (c) 2012 Samsung Electronics Co., Ltd.
 *	Minsung Kim <ms925.kim@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __LINUX_CPUFREQ_LIMIT_H__
#define __LINUX_CPUFREQ_LIMIT_H__

#define CPUFREQ_MIN	0
#define CPUFREQ_MAX	1
size_t cpufreq_limit_requests_get(int type);

struct cpufreq_limit_handle;

#ifdef CONFIG_CPU_FREQ_LIMIT
struct cpufreq_limit_handle *cpufreq_limit_get(unsigned long min_freq,
		unsigned long max_freq, char *label);
int cpufreq_limit_put(struct cpufreq_limit_handle *handle);

static inline
struct cpufreq_limit_handle *cpufreq_limit_min_freq(unsigned long min_freq,
						    char *label)
{
	return cpufreq_limit_get(min_freq, 0, label);
}

static inline
struct cpufreq_limit_handle *cpufreq_limit_max_freq(unsigned long max_freq,
						    char *label)
{
	return cpufreq_limit_get(0, max_freq, label);
}
#else
static inline
struct cpufreq_limit_handle *cpufreq_limit_get(unsigned long min_freq,
		unsigned long max_freq, char *label)
{
	return NULL;
}

int cpufreq_limit_put(struct cpufreq_limit_handle *handle)
{
	return 0;
}

static inline
struct cpufreq_limit_handle *cpufreq_limit_min_freq(unsigned long min_freq,
						    char *label)
{
	return NULL;
}

static inline
struct cpufreq_limit_handle *cpufreq_limit_max_freq(unsigned long max_freq,
						    char *label)
{
	return NULL;
}
#endif

#ifdef CONFIG_SPRD_CPU_DYNAMIC_HOTPLUG
struct cpu_num_min_limit_handle {
        struct list_head node;
        unsigned int cpu_num_min_limit;
        char label[20];
};
struct cpu_num_min_limit_handle *_store_cpu_num_min_limit(unsigned int input, char *label);
int cpu_num_min_limit_put(struct cpu_num_min_limit_handle *handle);
#endif

#endif /* __LINUX_CPUFREQ_LIMIT_H__ */
