#include <iostream>
#include <vector>
#include "Node.hpp"

class Application {
  public:
    bool solucionado;
    std::unique_ptr<Bfs::Node> inicial;
    std::unique_ptr<Bfs::Node> solucion;

    Application()  {
      this->solucionado = false;

      this->inicial = std::unique_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({4,2,3,1})));
      this->solucion = std::unique_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({1,2,3,4})));

      findSolution();
    }

    void findSolution() {
      int level = 0;
      std::shared_ptr<Bfs::Node> tmp;
      while (!this->solucionado) {
        for (int i = level; i <= (level * 2); i++) {
          if ()
        }
        level++;
      }
    }
};

int main(int argc, char** argv) {
  Application app;
  return 0;
}

