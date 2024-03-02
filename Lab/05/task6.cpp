/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
using namespace std;
class GraphicsEngine {
public:
    void render_graphics() {
        cout << "Rendering graphics..." << endl;
    }
};
class InputHandler {
public:
    void processInput() {
        cout << "Processing input..." << endl;
    }
};
class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Simulating physics..." << endl;
    }
};
class GameEngine {
private:
    GraphicsEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void runFrame() {
        inputHandler.processInput();    // Process user input
        physicsEngine.simulatePhysics(); // Simulate physics
        graphicsEngine.render_graphics(); // Render graphics
    }
};

int main() {
    GameEngine* g = new GameEngine;
    g->runFrame();
    delete g; //once the pointer is deleted, all the associated classes are deleted with it
    return 0;
}
