#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

char *
skipSpaces(char *s)
{

	while (*(s++) == ' ');
	--s;
	return s;
}

bool
isNumber(char *s)
{
	int i = 0;
	s = skipSpaces(s);

	if (*s == '-' || *s == '+') ++s;
	while (isdigit(*(s++))) {
		i = 1;
		if (*s == 0) return true;

	} --s;
	if (*s == '.') {
		++s;
		if (*s == 0) return i;
		if (s != skipSpaces(s)) return *skipSpaces(s) == 0 && i;
		if (*s == 'e' && i) {
			++s;
			if (s != skipSpaces(s)) return false;
			if (*s == '-' || *s == '+') ++s;
			if (!isdigit(*s)) return false;
		}
		while (isdigit(*(s++))) {
			if(*s == 0) return true;
			i = 1;
		}
		--s;
		if (s != skipSpaces(s)) return *skipSpaces(s) == 0;
	}
	if (*s == 'e' & i) {
		++s;
		if (*s == '-' || *s == '+') ++s;
		if(!isdigit(*s)) return false;

	}
	if (s != 0) {
		while (isdigit(*(s++)))
			if (*s == 0) return true;
		--s;
	}
	if (s != skipSpaces(s)) return *skipSpaces(s) == 0;
	if (*s == 0 && i) return true;
	return false;

}
