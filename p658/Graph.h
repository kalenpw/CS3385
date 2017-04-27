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
            _isStart = false;
            _isFinish = false;
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


        Point getPoint(){
            return _point;
        }


        Color getColor(){
            if(_isStart){ 
                //R G B
                setColor(1,0,0);
            }
            if(_isFinish){
                setColor(0,0,1);
            }
            return _vertexColor;
        }

        bool getIsStart(){
            return _isStart;
        }
        bool getIsFinish(){
            return _isFinish;
        }

        void setIsStartNode(bool boolean){
            _isStart = boolean;
        }

        void setIsFinishNode(bool b){
            _isFinish = b;
        }

            
        void setColor(int r, int g, int b){
            Color newColor = Color(r, g, b);
            _vertexColor = newColor;
        }

        void setD(int d){
            _d = d;
        }

        void setPi(Vertex* v){
            _pi = v;
        }



    private:
        bool _isStart;
        bool _isFinish;
        Point _point;
        std::string _data;
        Color _vertexColor = Color(0,0,0);
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
  void mouseControlClick(const Point& p); void mouseMoved(const Point& p);

  Vertex* addVertex(const std::string& data, const Point& p);
  void addEdge(Vertex* u, Vertex* v, const std::string& data);

  Vertex* getStartNode();
  Vertex* getFinishNode();

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
