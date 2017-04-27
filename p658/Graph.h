#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "linmath.h"

#include "./programs.h"
#include "./util.h"

class Vertex { 
    public:
        Vertex(std::string data, Point p){
            _data = data; 
            _point = p; 
        }

        std::string data(){
            return _data;
        }

        Vertex* pi(){
            return _pi;
        }

        int d(){
            return _d;
        }

        std::string color(){
            return _color;
        }

        void setColor(std::string color){
            _color = color;
        }

        void setD(int d){
            _d = d;
        }

        void setPi(Vertex* v){
            _pi = v;
        }


    private:
        Point _point;
        std::string _data;
        std::string _color;
        int _d;
        Vertex* _pi;
};

class Edge{
    public:
        Edge(Vertex* start, Vertex* finish, std::string name){
            _start = start;
            _finish = finish;
            _name = name;
        }

        Vertex* getStart(){
            return _start;
        }
        Vertex* getFinish(){
            return _finish;
        }
        std::string getName(){
            return _name;
        }


    private:
        Vertex* _start;
        Vertex* _finish;
        std::string _name;
};

class Graph {
 public:

  void render(FlatProgram& program, mat4x4 mvp);

  void mouseDown(const Point& p);
  void mouseShiftClick(const Point& p);
  void mouseControlClick(const Point& p);
  void mouseMoved(const Point& p);

  Vertex* addVertex(const std::string& data, const Point& p);
  void addEdge(Vertex* u, Vertex* v, const std::string& data);

 private:
  std::unordered_map<std::string, Vertex*> _key2vertex;
  std::vector<Vertex*> _vertices;
  std::vector<Edge> _edges;
};

//------------------------------------------------------------
// TODO: This is where the graph is initialized with vertices.
// You can add/take away vertices as you wish. This function
// is implemented in Graph.cpp.
//------------------------------------------------------------
void initGraph(Graph& g);
