#include <stdio.h>
#include <stdlib.h>

/* main.c is a simple test program to excerise various DS's*/

int main(int argc, char **argv) {

	int i;
	int storeUs[5] = {5,10,15,7,2};

	for(i=0; i<5; i++) {
		add_new_node(storeUs[i]);
	}

	print_out_ll();

	return 0;
}
