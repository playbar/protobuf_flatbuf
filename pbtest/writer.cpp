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
using namespace pb;

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

    Sample sample;
    for (int i = 0; i < count; i++) {
        sample.set_id(i);
        sample.set_name("kobe");
        sample.clear_addr_list();
        for (int j = i; j < i + 20; j++) {
//            sample.add_addr_list(j);
            auto list = sample.mutable_addr_list();
            list->Add(j);
        }

        auto color = sample.mutable_color();
        color->set_a(1.2f);
        color->set_g(1.4f);
        color->set_b(1.6f);
        color->set_a(1.8f);

        auto pcolor = sample.add_colors();
//        pb_color pcolor;
        pcolor->set_a(1.3f);
        pcolor->set_g(1.5f);
        pcolor->set_b(1.7f);
        pcolor->set_a(1.9f);

        sample.mutable_colors()->RemoveLast();

//        colors->RemoveLast();

        auto map = sample.mutable_map_data();
        (*map)["test"] = i;
        (*map)["1"] = i + 1;

        auto &mmap = *sample.mutable_map_data();
        mmap["2"] = i + 2;

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
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
