/*
 * exp.c
 *
 * zeke-moses
 *
 * This experimental file will fill the data structures.
 */

#include "exp.h"

/*
 * exit function for errors
 */
static void die(const char *message)
{
	perror(message);
	exit(1);
}

/*
 * simply checks to see if the heirarchy of lists is working as intended
 */
static void check()
{
	int i, j, k;
	for (i = 0; i < 5; i++) {
		outer_list[i].num = i;
		for (j = 0; j < 5; j++) {
			outer_list[i].middle_list[j].num = i * j;

			for (k = 0; k < 5; k++) {
				outer_list[i].middle_list[j].inner_list[k].num = i*j*k;
			}
		}
	}

	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("%d ", outer_list[i].num);

		for (j = 0; j < 5; j++) {
			printf("%d ", outer_list[i].middle_list[j].num);

			for (k = 0; k < 5; k++) {
				printf("%d ", outer_list[i].middle_list[j].inner_list[k].num);
			}
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	//check();
	return 0;
}
