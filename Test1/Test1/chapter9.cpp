#include <iostream>
#include "chapter9.h"


//heapSize = 0;

int Left(int index) {
	return ((index << 1) + 1);
}

int Right(int index) {
	return ((index << 1) + 2);
}