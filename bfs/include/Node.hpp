#include <iostream>
#include <string>
#include <memory>
#include <vector>

#ifndef _BFS_NODE_
#define _BFS_NODE_

namespace Bfs {
  class Node {
    public:
      std::shared_ptr<Node> parent;
      std::vector<int> data;
      std::shared_ptr<Node> childLeft;
      std::shared_ptr<Node> childRight;
      std::shared_ptr<Node> brother;
      std::shared_ptr<Node> cousin;

      Node();
      Node(std::vector<int> data);
      Node(std::shared_ptr<Node> parent, std::vector<int> data);
      std::string to_string();
      bool isEqual(std::shared_ptr<Node> other);
      void expand();
  };
}

#endif
