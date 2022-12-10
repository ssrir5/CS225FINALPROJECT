//#include "utils.h"
class Graph {
    public:
        void Traversal();
        std::vector<std::vector<std::string>> CSVReader;
        std::string file_to_string(const std::string& filename);
        std::string TrimRight(const std::string & str);
        std::string TrimLeft(const std::string & str);
        std::string Trim(const std::string & str);
        int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
        
}