#pragma once

#include<string>
#include<vector>

namespace VT {

    class VTPipline {
        public:
            VTPipline(const std::string &vertFilepath, const std::string &fragFilepath);


        private:
            static std::vector<char> readFile(const std::string &filpath);
            void createGraphicsPipline(const std::string &vertFilepath, const std::string &fragFilepath);
    };
}