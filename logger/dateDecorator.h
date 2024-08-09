//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_DATEDECORATOR_H
#define LOGGER_DATEDECORATOR_H

#include "decorator.h"

namespace logger {

    class dateDecorator :public decorator{
    public:
        dateDecorator():decorator(){};
        ~dateDecorator() override = default;

        void format() override;
    };

} // logger

#endif //LOGGER_DATEDECORATOR_H
