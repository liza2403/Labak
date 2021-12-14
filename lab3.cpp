#include <iostream>
#include <getopt.h>

#define no_arg 0
#define required_arg 1

using namespace std;

/*
 *  args: help(h), service(s), data(d), volume(v)
 *
*/

int main (int argc, char *argv[]) {
    bool help_flag = 0;
    bool service_flag = 0;
    bool data_flag = 0;

    string volume = "";

    int index, n;

    opterr = 0;

    const struct option longopts[] =
    {
        {"help", no_arg, 0, 'h'},
        {"data", no_arg, 0, 'd'},
        {"service", no_arg, 0, 's'},
        {"volume", required_arg, 0, 'v'},
        {0, 0, 0, 0}
    };
    
    while ((n = getopt_long(argc, argv, "hsdv:", longopts, &index)) != -1) {
        switch (n)
        {
            case 'h':
                help_flag = true;
                break;
            case 's':
                service_flag = true;
                break;
            case 'd':
                data_flag = true;
                break;
            case 'v':
                volume = optarg;
                break;
            case '?':
                cout << "Incorretc key\n";
                break;
        }
    }
    
    if (help_flag ) 
        cout << "Arg: Help\n";

    if (service_flag) 
        cout << "Arg: Service\n";

    if (data_flag) 
        cout << "Arg: Data\n";

    if (volume != "") 
        cout << "Volume=" << volume << "\n";

    return 0;
}
