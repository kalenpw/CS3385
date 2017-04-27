#include <iostream>

#include "./Graph.h"
#include "./Vertex.h"
#include "./Circle.h"
#include "./Line.h"

// TODO: Move the "current" vertex to point p. You will set
// the current vertex in mouseDown(). If you have source
// and target vertices, call the dijkstra() function after
// moving the vertex to update the shortest path.
void Graph::mouseMoved(const Point& p) {
}

// TODO: Set the "current" vertex using the distance
// function in util.h.
void Graph::mouseDown(const Point& p) {
    std::cout << "x: " << p.x;
    std::cout << "y: " << p.y;
}

// TODO: Use the distance function to find the vertex closest
// to the mouse click. That vertex will become the new source
// vertex. Update the shortest path if appropriate.
void Graph::mouseControlClick(const Point& p) {
//    std::cout << "x: " << p.x;
//    std::cout << "y: " << p.y;

    std::cout << "x: " << p.x << std::endl;
    std::cout << "y: " << p.y << std::endl;
}

// TODO: Use the distance function to find the vertex closest
// to the mouse click. That vertex will become the new target
// vertex. Update the shortest path if appropriate.
void Graph::mouseShiftClick(const Point& p) {
    std::cout << "x: " << p.x;
    std::cout << "y: " << p.y;
}

void Graph::render(FlatProgram& program, mat4x4 mvp) {
  using namespace std;

  Circle* c = Circle::instance();
  Line* l = Line::instance();

  // Renders a line from point p to point q
  Point p(0, 0);
  Point q(1, 0);
  glLineWidth(1.0); // Use this to bold the shortest path line.
  l->render(program, mvp, p, q, Color::GRAY);

  // Renders dots at points p and q
  c->render(program, mvp, p, Color::RED, true);
  c->render(program, mvp, q, Color::BLUE, true);

  // TODO: Render edges and vertices using the functions
  // demonstrated above.
}

// TODO: Implement. Each vertex should have a point location
// associated with it.
Vertex* Graph::addVertex(const std::string& data, const Point& p) {
    Vertex* v = new Vertex(data, p);
    _vertices.push_back(v);
    _key2vertex[data] = v;

    return v;

}

// TODO: Implement.
void Graph::addEdge(Vertex* u, Vertex* v, const std::string& data) {
    Edge newEdge(u, v, data);
    _edges.push_back(newEdge);
}

//------------------------------------------------------------
// TODO: This is where the graph is initialized with vertices.
// You can add/take away vertices as you wish.
//------------------------------------------------------------
void initGraph(Graph& g) {
  // Layout of the vertices:
  //
  //               G
  //         D
  //   A           C
  // 
  //         E
  //         F 
  Vertex* A = g.addVertex("A", Point(-0.5, 0));
  Vertex* C = g.addVertex("C", Point(0.5, 0));
  Vertex* D = g.addVertex("D", Point(0, 0.25));
  Vertex* E = g.addVertex("E", Point(0, -0.3));
  Vertex* F = g.addVertex("F", Point(0, -0.7));
  Vertex* G = g.addVertex("G", Point(0.5, 0.35));

  g.addEdge(A, D, "A-D");
  g.addEdge(A, E, "A-E");
  g.addEdge(D, G, "D-G");
  g.addEdge(G, C, "G-C");
  g.addEdge(E, C, "E-C");
  g.addEdge(A, F, "A-F");
  g.addEdge(F, C, "F-C");
}

