/*
Copyright 2019
Original authors: Niko Procopi
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
<http://www.gnu.org/licenses/>.

Special Thanks to Exzap from Team Cemu,
he gave me advice on how to optimize Vulkan
graphics, he is working on a Wii U emulator
that utilizes Vulkan, see more at http://cemu.info
*/

#include "Helper.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <signal.h>
#include <vector>

void Helper::DbgMsg(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	vprintf(fmt, va);
	va_end(va);
	fflush(stdout);
}

// This function simply reads a file,
// records every byte into an array of bytes,
// and records the size. This can be used
// for textures and shaders
void Helper::ReadFile(const char* path, char** data, int* size)
{
	// open the file 
	FILE *fp = fopen(path, "rb");

	// Go to the end of the file
	fseek(fp, 0L, SEEK_END);

	// see how far away the end of 
	// the file was, from the beginning,
	// and record that number as size
	*size = ftell(fp);

	// go back to the beginning
	rewind(fp);

	// allocate memory that is big enough
	// for all bytes in the file
	*data = (char*)calloc(1, *size + 1);

	// dump every byte from the file
	// into our array of bytes
	fread(*data, *size, 1, fp);

	// close the file
	fclose(fp);
}