#pragma once

#include<string>
#include<vector>

namespace VT {

    class VTPipeline {
        public:
            VTPipeline(const std::string &vertFilepath, const std::string &fragFilepath);


        private:
            static std::vector<char> readFile(const std::string &filpath);
            void createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath);
    };
}