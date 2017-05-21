/*
 * exp.h
 *
 * zeke-moses
 *
 * This header file holds the definitions of the data structures.
 */

#ifndef __EXP_H__
#define __EXP_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct inner_node {
        int num;
};

struct middle_node {
        int num;
        struct inner_node inner_list[5];
};

/*
 * serves as 'starting points' for algorithm. Idea is to treat each as a first
 * point for either filling in corresponding structures or for parsing to find
 * "responses"
 */
struct outer_node {
        int num;
        struct middle_node middle_list[5];
};

/*
 * access point for main data structure that holds the middle lists and the
 * inner lists. used for data keeping.
 */
static struct outer_node outer_list[5];

// now need to make queue that holds responses.

struct response {
        int num;
};

//static vector<response> vec_q;

static struct response q_list[5];

#endif /* __EXP_H__ */
