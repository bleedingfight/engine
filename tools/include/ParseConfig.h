//
// Created by liushuai on 2021/2/19.
//

#ifndef ENGINE_PARSECONFIG_H
#define ENGINE_PARSECONFIG_H
#include "model_config.pb.h"
#include <string>
#include <map>
using namespace std;
map<string,string> parseCaffeConfig(ModelConfig& mc);

#endif //ENGINE_PARSECONFIG_H
