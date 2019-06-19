#include <iostream>
#include <vector>
#include <cmath>
#include "Node.hpp"

class Application {
  public:
    std::shared_ptr<Bfs::Node> inicial;
    std::shared_ptr<Bfs::Node> solucion;
    std::shared_ptr<Bfs::Node> it;
    std::shared_ptr<Bfs::Node> nextLevel;
    int level = 0;
    bool solucionado;

    Application()  {
      this->inicial = std::shared_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({4,3,5,2,1})));
      this->solucion = std::shared_ptr<Bfs::Node>(new Bfs::Node(std::vector<int>({1,2,3,4,5})));
      this->it = this->inicial;
      this->nextLevel = this->it;
      this->level = 0;
      this->solucionado = false;    

      compute();
    }

    void compute() {
      while (!this->solucionado && this->level <= 14) {
        this->findSolution();
      }
      if (this->solucionado) {
        std::cout << "The solution is: " << it->to_string() << " found in level: " << this->level << std::endl;
      } else {
        std::cout << "Imposible to found a solution" << std::endl;
      }
    }

    void findSolution() {
      int nodesByLevel = pow(2, this->level);
      std::cout << "nodes by level " << this->level << ": " << nodesByLevel << std::endl;
      for (int i = 0; i < nodesByLevel; i++) {
        if (it->isEqual(this->solucion)) {
          this->solucionado = true;
          break;
        } else {
          this->it->expand();
          if (i == 0) {
            this->nextLevel = it->childLeft;
          }
          if (i % 2 != 0) {
            this->it->brother->childRight->cousin = this->it->childLeft;
            this->it->childLeft->cousin = this->it->brother->childRight;
          }
          if (i % 2 == 0 && i != 0) {  
            this->it->cousin->childRight->cousin = this->it->childLeft;
            this->it->childLeft->cousin = this->it->cousin->childRight; 
          }
          if (i < (nodesByLevel - 1)) {
            if ( i % 2 == 0 ) {
              this->it = this->it->brother;
            } else {
              if (nodesByLevel >= 4) {
                this->it = this->it->cousin;
              }
            }
          }
          if (i == (nodesByLevel - 1)) {
            this->it = this->nextLevel;
          }
        }
      } 
      this->level++;
    }
};

int main(int argc, char** argv) {
  std::unique_ptr<Application> app(new Application());
  return 0;
}

