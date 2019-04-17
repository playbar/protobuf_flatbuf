//
// Created by hou guoli on 2019/4/17.
//

#include <iostream>
#include <flatbuffers/util.h>
#include "flatbuffers/flatbuffers.h"
#include "util.h"
#include "string"
#include "TestFlat_generated.h"

using namespace std;
using namespace Jason::Flat::Test;

int main(int argc, char* argv[])
{

    string binaryfile;
    bool ok = flatbuffers::LoadFile("texture.bin", false, &binaryfile);

    flatbuffers::FlatBufferBuilder builderOut;
    TextureBuilder* texBuilder = new TextureBuilder(builderOut);
    builderOut.PushBytes(reinterpret_cast<unsigned char*>(const_cast<char *>(binaryfile.c_str())), binaryfile.size());
    std::cout << builderOut.GetSize() << std::endl;

    auto model = GetTexture(builderOut.GetBufferPointer());

    int outNum = model->num_textures();
    const flatbuffers::Vector<flatbuffers::Offset<TextureData>>* outTex = model->textures();
    TextureData* outTexData = (TextureData *)outTex->Get(0);
    int outSize = outTexData->image_size();
    const flatbuffers::Vector<unsigned char>* outData = outTexData->image_data();
    int x = outData->Get(5);
    int len = outData->Length();
    delete texBuilder;

    return 0;
}
