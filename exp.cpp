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

int main(int argc, char **argv)
{
        if (argc != 3)
                cout<<"run ./test.sh\n";

        // get current position.
        string curr_lat(argv[1]);
        string curr_lon(argv[2]);

        if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
                die("signal failed");

        // start filling out list structure
        find_nearest_starting_stops(curr_lat, curr_lon);

        return 0;
}
