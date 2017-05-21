/*
 * exp.cpp
 *
 * zeke-moses
 *
 * This experimental file will fill the data structures.
 */

#include "exp.h"

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
    cout<<"\n";

	for (i = 0; i < 5; i++) {
		printf("%d ", outer_list[i].num);

		for (j = 0; j < 5; j++) {
			printf("%d ", outer_list[i].middle_list[j].num);

			for (k = 0; k < 5; k++) {
                cout<<outer_list[i].middle_list[j].inner_list[k].num<<" ";
			}
		}
	}
    cout<<"\n";
}

int main(int argc, char **argv)
{
	//check();
	return 0;
}
