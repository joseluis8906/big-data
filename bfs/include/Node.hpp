#include <iostream>
#include <string>
#include <memory>
#include <vector>

#ifndef _BFS_NODE_
#define _BFS_NODE_
namespace Bfs {
  class Node {
    public:
      std::vector<int> data;
      std::unique_ptr<Node> left;
      std::unique_ptr<Node> right;

      Node();
      Node(std::vector<int> data);
      void print();
      bool isEqual(Node &other);
      void operateLeft();
      void operateRight();
  };
}
#endif
