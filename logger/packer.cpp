//
// Created by l1Akr on 24-8-11.
//

#include "packer.h"

const char* packer::RootFormatStr               = "[%s {%Y-%m-%d %H:%M:%S}] [%level] %filepath:%line (%func): %message \n";
const packer::level packer::RootLevel           = packer::level::Debug;