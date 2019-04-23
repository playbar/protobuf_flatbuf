/**
 * 
 * @file    writer
 * @author  chosen0ne(louzhenlin86@126.com)
 * @date    2015/01/19 17:08:01
 */

#include "protos/Sample.pb.h"

#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    int fd, count;
    char buf[1024];

    count = 10;
    std::cout << "count: " << count << std::endl;

    fd = open("buf", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }

    Sample::Sample sample;
    for (int i = 0; i < count; i++) {
        sample.set_id(i);
        sample.set_name("kobe");
        sample.clear_addr_list();
        for (int j = i; j < i + 20; j++) {
            sample.add_addr_list(j);
        }

        auto map = sample.mutable_map_data();
        (*map)["test"] = i;
        (*map)["1"] = i + 1;

//        auto data = sample.map_data();
//        string key = "test";
//        sample.map_data()["test"] = 2;
//        sample.map_data().insert(pair<string, int>("test", 1));
//        data[key] = 2;
//        sample.data().insert(pair<std::string, int>("test", 1>);


        int size = sample.ByteSize();
        int nwritten = write(fd, &size, sizeof(size));
        if (nwritten == -1) {
            std::cout << "failed to write" << std::endl;
            return -1;
        }

        if (!sample.SerializeToArray(buf, 1024)) {
            std::cout << "failed to serialize" << std::endl;
            return -1;
        }

        nwritten = write(fd, buf, size);
        if (nwritten == -1) {
            std::cout << "failed to write" << std::endl;
            return -1;
        }
    }

    return 0;
}
