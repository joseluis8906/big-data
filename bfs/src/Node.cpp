#include "Node.hpp"

Bfs::Node::Node() {
  this->parent = std::shared_ptr<Node>(nullptr);
  this->data = std::vector<int>({});
  this->childLeft = std::shared_ptr<Node>(nullptr);
  this->childRight = std::shared_ptr<Node>(nullptr);
  this->brother = std::shared_ptr<Node>(nullptr);
  this->cousin = std::shared_ptr<Node>(nullptr);
}

Bfs::Node::Node(std::vector<int> data) {
  this->parent = std::shared_ptr<Node>(nullptr);
  this->data = data;
  this->childLeft = std::shared_ptr<Node>(nullptr);
  this->childRight = std::shared_ptr<Node>(nullptr);
  this->brother = std::shared_ptr<Node>(nullptr);
  this->cousin = std::shared_ptr<Node>(nullptr);
}

Bfs::Node::Node(std::shared_ptr<Node> parent, std::vector<int> data) {
  this->parent = parent;
  this->data = data;
  this->childLeft = std::shared_ptr<Node>(nullptr);
  this->childRight = std::shared_ptr<Node>(nullptr);
  this->brother = std::shared_ptr<Node>(nullptr);
  this->cousin = std::shared_ptr<Node>(nullptr);
}

std::string Bfs::Node::to_string() {
  return "[" + std::to_string(this->data[0]) + ", "  + std::to_string(this->data[1]) + ", " + std::to_string(this->data[2]) + ", " + std::to_string(this->data[3]) + "]"; 
}

bool Bfs::Node::isEqual(std::shared_ptr<Bfs::Node> other) {
  if (this->data[0] != other->data[0]) {
    return false;
  }
  
  if (this->data[1] != other->data[1]) {
    return false;
  }
  
  if (this->data[2] != other->data[2]) {
    return false;
  }
  
  if (this->data[3] != other->data[3]) {
    return false;
  }
  
  return true;
}

void Bfs::Node::expand() {
  std::vector<int> pivot({this->data[0], this->data[2], this->data[1], this->data[3]});
  this->childLeft = std::shared_ptr<Bfs::Node>(std::shared_ptr<Bfs::Node>(this), new Bfs::Node(std::vector<int>({pivot[1], pivot[0], pivot[2], pivot[3]})));
  this->childRight = std::shared_ptr<Bfs::Node>(std::shared_ptr<Bfs::Node>(this), new Bfs::Node(std::vector<int>({pivot[0], pivot[1], pivot[3], pivot[2]})));
  this->childLeft->brother = this->childRight;
  this->childRight->brother = this->childLeft;
}