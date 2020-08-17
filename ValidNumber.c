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
	while (*s != 0 && isdigit(*(s++))) {
		i = 1;
		if (*s == 0) return true;

	} --s;
	if (*s == '.') {
		++s;
		if (*s == 0 && i) return true;
		if (*s == 'e') return false;
		while (*s != 0 && isdigit(*(s++)));
		--s;

	}
	if (*s == 'e' && i) {
		++s;
		s = skipSpaces(s);
		if (*s == 0) return false;

	}
	if (*s == '-' || *s == '+') ++s;
	if (s != 0) {
		while (*s != 0 && isdigit(*(s++)))
			if (*s == 0) return true;
		--s;

	}
	s = skipSpaces(s);
	if (*s == 0 && i) return true;
	return false;

}
int
main(int argc, char **argv)
{
	printf("%d\n", isNumber(argv[1]));
}


