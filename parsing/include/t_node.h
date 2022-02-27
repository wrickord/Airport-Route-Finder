#include <stdint.h>
#include <string>

namespace Parser {

template <class T>
class Node {
    public:
        template <class T>
        Node(std::string data) : data(data_) {
            id_ = num_nodes_++;
        }

        template <class T>
        unsigned getID() { return id_; }
        
        template <class T>
        T getData() { return data_; }

        static unsigned num_nodes_;

    private:
        unsigned id_ = 0;
        T data_ = T();
};
}
