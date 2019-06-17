#include "Node.hpp"

Bfs::Node::Node(std::vector<int> data) {
  this->data = data;
} 

void Bfs::Node::print() {
  std::cout << "[" << this->data[0] << ", " << this->data[1] << ", " << this->data[2] << ", " << this->data[3] << "]" << std::endl; 
}

bool Bfs::Node::isEqual(Bfs::Node &other) {
  if (this->data[0] != other.data[0]) {
    return false;
  }
  
  if (this->data[1] != other.data[1]) {
    return false;
  }
  
  if (this->data[2] != other.data[2]) {
    return false;
  }
  
  if (this->data[3] != other.data[3]) {
    return false;
  }
  
  return true;
}

void Bfs::Node::operateLeft() {
  this->left = std::unique_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({this->data[1], this->data[0], this->data[2], this->data[3]})));
}

void Bfs::Node::operateRight() {
  this->right = std::unique_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({this->data[0], this->data[1], this->data[3], this->data[2]})));
}

