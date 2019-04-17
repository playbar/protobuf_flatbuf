//
// Created by hou guoli on 2019/4/17.
//

#include <iostream>
#include <flatbuffers/util.h>
#include "flatbuffers/flatbuffers.h"
#include "util.h"
#include "vector"
#include "TestFlat_generated.h"

using namespace std;
using namespace Jason::Flat::Test;

int main(int argc, char* argv[])
{
    //read serialized buffer
    flatbuffers::FlatBufferBuilder builder_data;

    int test_append = 300;
    auto name_test = builder_data.CreateString("TestAppend");
    auto testApp = CreateTestAppend(builder_data, test_append, test_append);

    int image_size = 12;
    unsigned char inv_data[] = { 11, 2, 4, 2, 10, 3, 5 ,7, 10, 39, 45, 23 };
    auto name = builder_data.CreateString("TextureData");
    auto image_data = builder_data.CreateVector(inv_data, image_size);

    int image_test = 900;
    auto texture_data = CreateTextureData(builder_data, image_size, image_data, image_test, image_test);

    //flatbuffers::FlatBufferBuilder builder_tex;
    int texture_num = 1;

    auto name_tex = builder_data.CreateString("Texture");

    vector<flatbuffers::Offset<TextureData>> tex_vec;
    tex_vec.push_back(texture_data);
    auto tex_data = builder_data.CreateVector(tex_vec);

    int num_text = 100, num_text2 = 200, num_text3 = 300;
    auto texture = CreateTexture(builder_data, texture_num, tex_data, num_text, num_text2, testApp);
    builder_data.Finish(texture);

    std::cout << builder_data.GetSize() << std::endl;
    flatbuffers::SaveFile("texture.bin", reinterpret_cast<char *>(builder_data.GetBufferPointer()), builder_data.GetSize(), true);

    return 0;
}

