/*
 * exp.h
 *
 * zeke-moses
 *
 * This header file holds the functions and algorithms for manipulating
 * the data structures from exp-structs.h
 */

#ifndef __EXP_H__
#define __EXP_H__

#include "exp-structs.h"
// c libraries
#include <stdio.h>          // printf, fprintf
#include <sys/socket.h>     // socket, bind, connect
#include <arpa/inet.h>      // sockaddr_in and inet_ntoa
#include <stdlib.h>         // atoi, exit
#include <string.h>         // memset
#include <unistd.h>         // close
#include <time.h>           // time
#include <netdb.h>          // gethostbyname
#include <signal.h>         // signal
#include <sys/stat.h>       // stat
#include <math.h>
// cpp libraries
#include <fstream>          // for parsing text files
#include <sstream>          // for tokenizing string by commas

#define     SQR(x)      ((x)*(x))

/*
 * Needs to be updated.
 * Parses through list data structure to find the most optimal respones.
 * Proceeds to move them to the static queue (which is just an array).
 */
void move_to_queue();

/*
 * Now, need to successfully contact Google's API to find the 5 nearest bus
 * stops.
 *
 * So, make a connection to Google's API.
 *
 * Send request for 5 nearest bus stops.
 *
 * Record them into global_list
 */

struct dist_and_string {
        long double distance;
        string line;
};
struct dist_and_string nearest_stops[LIST_SIZE];

static int create_google_maps_connection();
void find_nearest_starting_stops(string curr_lat, string curr_lon);

#endif /* __EXP_H__ */
