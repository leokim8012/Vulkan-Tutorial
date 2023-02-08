#pragma once

#include "_window.hpp"

namespace VT{
    class FirstApp {

        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT =600;

            void run();

        private:
            VTWindow VTWindow{
                WIDTH, HEIGHT, "New window"

            };
    };
}