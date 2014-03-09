#ifndef __UTIL_H__
#define __UTIL_H__

#define _printf(FMT, ARGS...) printf("[%s %d] " FMT "\n", __FILE__, __LINE__, ##ARGS)

void print_cur_datetime();
void get_cur_datetime(char* tmstr, size_t tmstr_size);

#endif
