#include <stdio.h>
#include <strings.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "../common.h"

#include "core/log.h"

#ifdef MEMORYMON
static int malloc_counter = 0;
static int free_counter = 0;

void *_malloc (unsigned int size)
{
	malloc_counter++;
	return malloc (size);
}

void _free (void *value)
{
	free_counter++;
	free (value);
}

void print_meminfo()
{
	struct mallinfo meminfo = mallinfo();
	log_add ("Memory allocated -  MB: %d - kb: %d\n                    Memory occupied  -  MB: %d - kb: %d\n",
		meminfo.arena/(1024*1024), meminfo.arena/1024,
		meminfo.uordblks/(1024*1024), meminfo.uordblks/1024);
}

void memory_stats ()
{
	if ((malloc_counter - free_counter) > 0)
	{
		log_add ("ATTENTION!!! MEMORY NOT FULLY CLEANED!!!");
	}
	else
	{
		log_add ("CONGRATULATIONS!!! MEMORY WAS FULL CLEANED!!!");
	}
	log_add ("Memory elements allocated: %d", malloc_counter);
	log_add ("Memory elements cleaned: %d", free_counter);
	log_add ("Memory elements missed: %d", malloc_counter - free_counter);
}
#endif
