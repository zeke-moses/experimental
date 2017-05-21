/*
 * exp.cpp
 *
 * zeke-moses
 *
 * This experimental file will fill the data structures.
 */

#include "exp.h"

static void die(const char *msg)
{
        perror(msg);
        exit(1);
}

void move_to_queue()
{
}

static int create_google_maps_connection()
{
        return 0;
}

/*
 * normally, need to square the result. But honestly, it shouldn't matter
 * since we're using it to compare here.
 */
long double find_euclid_dist(string curr_lat, string curr_lon,
                                            string other_lat, string other_lon)
{
        long double term1 = (long double) SQR(stod(curr_lat)-stod(other_lat));
        long double term2 = (long double) SQR(stod(curr_lon)-stod(other_lon));
        return sqrt(term1 + term2);
}

void find_nearest_starting_stops(string curr_lat, string curr_lon)
{
        /*
         * going to cheat a little, parse through stops.txt and
         * caclulate five nearest spots by measuring euclidean distance.
         */
        string line, element;
        string other_lat, other_lon;
        int i;
        long double dist;
        ifstream in_file("../data/google_transit/stops.txt");
        if (!in_file)
                die("stops.txt could not be opened");

        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        while (getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                cout<<"adding new entry\n";
                                cout<<"dist "<<dist<<"\nline "<<line<<"\n";
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }
        in_file.close();

        // move the five nearest bus stops to the global_list
        for (i = 0; i < LIST_SIZE; i++) {
                global_list[i].bus_stop = nearest_stops[i].line;
        }
}

void thread_func0()
{
        // here, working on global_list[0]
        // going to fill outer_list.
        int i;
        long double dist;
        // can use a mutex and a broadcast to access file one at a time
        // for the moment.
        string curr_lat, curr_lon;
        string other_lat, other_lon;
        string line, element;
        istringstream iss(global_list[0].bus_stop);
        for (i = 0; getline(iss, element, ','); i++) {
                if (i == 4)
                        curr_lat = element;
                if (i == 5)
                        curr_lon = element;
        }

        ifstream in_file("../data/google_transit/stops.txt");
        if(!in_file)
                die("stops.txt could not be opened");

        // zero out nearest stops struct.
        // better yet, can make a local copy for use in this thread (idea)
        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        // parse file for five bus stops nearest to our val
        while(getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }

        for (i = 0; i < LIST_SIZE; i++) {
                global_list[0].outer_list[i].bus_stop = nearest_stops[i].line;
        }

        // now going to fill middle list.
}

void thread_func1()
{
         // going to fill outer_list.
        int i;
        long double dist;
        // can use a mutex and a broadcast to access file one at a time
        // for the moment.
        string curr_lat, curr_lon;
        string other_lat, other_lon;
        string line, element;
        istringstream iss(global_list[1].bus_stop);
        for (i = 0; getline(iss, element, ','); i++) {
                if (i == 4)
                        curr_lat = element;
                if (i == 5)
                        curr_lon = element;
        }

        ifstream in_file("../data/google_transit/stops.txt");
        if(!in_file)
                die("stops.txt could not be opened");

        // zero out nearest stops struct.
        // better yet, can make a local copy for use in this thread (idea)
        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        // parse file for five bus stops nearest to our val
        while(getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }

        for (i = 0; i < LIST_SIZE; i++) {
                global_list[1].outer_list[i].bus_stop = nearest_stops[i].line;
        }

        // now going to fill middle list.
}

void thread_func2()
{
        // here, working on global_list[2]
        // going to fill outer_list
        int i;
        long double dist;
        // can use a mutex and a broadcast to access file one at a time
        // for the moment.
        string curr_lat, curr_lon;
        string other_lat, other_lon;
        string line, element;
        istringstream iss(global_list[2].bus_stop);
        for (i = 0; getline(iss, element, ','); i++) {
                if (i == 4)
                        curr_lat = element;
                if (i == 5)
                        curr_lon = element;
        }

        ifstream in_file("../data/google_transit/stops.txt");
        if(!in_file)
                die("stops.txt could not be opened");

        // zero out nearest stops struct.
        // better yet, can make a local copy for use in this thread (idea)
        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        // parse file for five bus stops nearest to our val
        while(getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }

        for (i = 0; i < LIST_SIZE; i++) {
                global_list[2].outer_list[i].bus_stop = nearest_stops[i].line;
        }

        // now going to fill middle list.
}

void thread_func3()
{
        // here, working on global_list[3]
        // going to fill outer_list
        int i;
        long double dist;
        // can use a mutex and a broadcast to access file one at a time
        // for the moment.
        string curr_lat, curr_lon;
        string other_lat, other_lon;
        string line, element;
        istringstream iss(global_list[3].bus_stop);
        for (i = 0; getline(iss, element, ','); i++) {
                if (i == 4)
                        curr_lat = element;
                if (i == 5)
                        curr_lon = element;
        }

        ifstream in_file("../data/google_transit/stops.txt");
        if(!in_file)
                die("stops.txt could not be opened");

        // zero out nearest stops struct.
        // better yet, can make a local copy for use in this thread (idea)
        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        // parse file for five bus stops nearest to our val
        while(getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }

        for (i = 0; i < LIST_SIZE; i++) {
                global_list[3].outer_list[i].bus_stop = nearest_stops[i].line;
        }

        // now going to fill middle list.
}

void thread_func4()
{
        // going to fill global_list[4].outer_list
        int i;
        long double dist;
        // can use a mutex and a broadcast to access file one at a time
        // for the moment.
        string curr_lat, curr_lon;
        string other_lat, other_lon;
        string line, element;
        istringstream iss(global_list[4].bus_stop);
        for (i = 0; getline(iss, element, ','); i++) {
                if (i == 4)
                        curr_lat = element;
                if (i == 5)
                        curr_lon = element;
        }

        ifstream in_file("../data/google_transit/stops.txt");
        if(!in_file)
                die("stops.txt could not be opened");

        // zero out nearest stops struct.
        // better yet, can make a local copy for use in this thread (idea)
        for (i = 0; i < LIST_SIZE; i++) {
                nearest_stops[i].distance = 0;
        }

        // get past first line
        getline(in_file, line);
        // parse file for five bus stops nearest to our val
        while(getline(in_file, line)) {

                istringstream iss(line);
                for (i = 0; getline(iss, element, ','); i++) {
                        if (i == 4)
                                other_lat = element;
                        if (i == 5)
                                other_lon = element;
                }

                if (other_lat.empty() || other_lon.empty())
                        continue;

                dist = find_euclid_dist(curr_lat, curr_lon, other_lat, other_lon);

                for (i = 0; i < LIST_SIZE; i++) {
                        if (nearest_stops[i].distance > dist ||
                                        nearest_stops[i].distance == 0) {
                                nearest_stops[i].distance = dist;
                                nearest_stops[i].line = line;
                                break;
                        }
                }
        }

        for (i = 0; i < LIST_SIZE; i++) {
                global_list[4].outer_list[i].bus_stop = nearest_stops[i].line;
        }

        // now going to fill middle list.
}

static void *thread_main(void *j)
{
        int i = *(int *)j;
        switch (i) {
                case 0:
                        thread_func0();
                        break;
                case 1:
                        thread_func1();
                        break;
                case 2:
                        thread_func2();
                        break;
                case 3:
                        thread_func3();
                        break;
                case 4:
                        thread_func4();
                        break;
                default:
                        die("splitting into threads didn't work");
        }
}

int main(int argc, char **argv)
{
        int i;
        int params[LIST_SIZE];
        if (argc != 3)
                cout<<"run ./test.sh\n";

        // get current position.
        string curr_lat(argv[1]);
        string curr_lon(argv[2]);

        if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
                die("signal failed");

        // start filling out list structure
        // fill out first level
        find_nearest_starting_stops(curr_lat, curr_lon);

        // move to next level
        // first split into threads tho.
        for (i = 0; i < LIST_SIZE; i++)
                params[i] = i;
        for (i = 0; i < LIST_SIZE; i++) {
                pthread_create(&thread_list[i], NULL, thread_main, &params[i]);
        }

        // wait for threads to finish.
        for (i = 0; i < LIST_SIZE; i++) {
                pthread_join(thread_list[i], NULL);
        }

        return 0;
}
