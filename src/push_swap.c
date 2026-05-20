#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int *numeros = is_valid_number(argc, argv);
	has_duplicates(argc, numeros);
}