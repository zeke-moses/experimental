/*
 * exp-structs.h
 *
 * zeke-moses
 *
 * This header file holds the definitions of the data structures.
 */

#ifndef __EXPSTRUCTS_H__
#define __EXPSTRUCTS_H__

#include <iostream>
#include <vector>
#include <string>
#define             LIST_SIZE                5

using namespace std;

struct inner_node {
        string bus_stop;
        int rest_points;            // restaurant_points
        int dist_from_prev_stop;
        int time_from_prev_stop;
};

struct middle_node {
        string bus_stop;
        int rest_points;
        int dist_from_prev_stop;    // think of as connecting edge
        int time_from_prev_stop;    // from outer_node
        struct inner_node inner_list[LIST_SIZE];
};

struct outer_node {
        string bus_stop;
        int rest_points; // idea: calculate rest_points, but don't hold list.
                    // recalculate when returning list of restaurants to user.
        int dist_from_prev_stop;    // in feet?
        int time_from_prev_stop;    // in minutes?
        struct middle_node middle_list[LIST_SIZE];
};

/*
 * serves as 'starting points' for algorithm. Idea is to treat each as a first
 * point for either filling in corresponding structures or for parsing to find
 * "responses"
 */
struct global_node {
        string bus_stop;
        int rest_points;
        int dist_from_user;
        int time_from_user;
        struct outer_node outer_list[LIST_SIZE];
};

/*
 * access point for main data structure that holds the middle lists and the
 * inner lists. used for data keeping.
 */
static struct global_node global_list[LIST_SIZE];

struct response {
        string starting_stop;       // c++ struct implementation
        string middle1_stop;        // means only four stops can be evaluated
        string middle2_stop;
        string ending_stop;         // but in the future this can be changed
};

/*
 * holds the responses that will be given to the user.
 * Will parse the outer_list to find most optimal results and fill its structure
 */
static struct response q_list[LIST_SIZE];

#endif /* __EXPSTRUCTS_H__ */
