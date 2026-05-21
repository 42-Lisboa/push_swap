#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	is_valid_argc(argc, argv);
	t_array *numeros = is_valid_number(argc, argv);
	has_duplicates(argc, numeros);
	has_valid_flag(argv);
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d\n", numeros->values[i]);
	}
}