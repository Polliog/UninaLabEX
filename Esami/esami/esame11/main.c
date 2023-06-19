#include "functions.h"
#include <stdio.h>



int main() {
	struct Match *m;
	init_node(&m);

	load_matches_from_file("configurazioni.txt", &m);

	//struct Match *temp = m;
	//print_list(temp);
	
	remove_tied(&m);

	struct Match *temp = m;
	print_list(temp);
	
	write_winners_on_file("vittorie_X.txt", &m, 'X');
	write_winners_on_file("vittorie_O.txt", &m, 'O');

	free_memory(&m);

	printf("\nFinito\n");
}
