#pragma once
#include<cstring>

bool equal(const char left[], const char right[]) {
	return strcmp(left, right) == 0;
}

void copyString(char to[], const char from[]) {
	int i;
	for (i = 0; from[i] != '\0'; ++i) {
		to[i] = from[i];
	}
	to[i] = '\0';
}
