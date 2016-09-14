/*  This file is part of The Firekylin Operating System.
 *
 *  Copyright 2016 Liuxiaofeng
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "stdio_loc.h"

char * fgets(char * buf, size_t n, FILE *stream)
{
	int c;
	char *p = buf;

	while (n-- && (c = fgetc(stream)) != EOF ) {
		*p++ = c;
		if (c == '\n')
			break;
	}

	if (feof(stream))
		return NULL;

	if(n)
		*p=0;
	return (p == buf) ? NULL : buf;
}
