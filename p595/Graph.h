#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>

#include <list>


class Vertex{
    public:
        Vertex(std::string name){
            _name = name; 
        }

        std::string data(){
            return _name;
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
        std::string _name;
        std::string _color;
        int _d;
        Vertex* _pi;


};

class Neighbor{
    public:
        Neighbor(){

        }

    private:
        Vertex* next;
        std::string edgeName;
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

class Graph{
    public:
        //Constructors
        Graph(){

        }

        //Methods
        void bfs(Vertex* initialVertex){

            for(int i = 0; i < _vertices.size(); i++){
                _vertices[i]->setColor("white");
                _vertices[i]->setD(999);
                _vertices[i]->setPi(NULL);
            }

            initialVertex->setColor("gray");
            initialVertex->setD(0);
            initialVertex->setPi(NULL);

            std::queue<Vertex*> queue;

            //TODO  while q = null


        }

        void addEdge(Vertex* vOne, Vertex* vTwo, std::string name){
//            Edge newEdge = new Edge(vOne, vTwo, name);
            Edge newEdge(vOne, vTwo, name);
            _edges.push_back(newEdge);
         
        }

        bool hasEdge(Vertex* vOne, Vertex* vTwo){
            bool foundEdge = false;
            
            //Same point
            if(vOne == vTwo){
                return false;
            }

            for(int i = 0; i < _edges.size(); i++){
                Vertex* first = _edges[i].getStart();
                Vertex* second = _edges[i].getFinish();

                if( (vOne == first || vOne == second) && (vTwo == first || vTwo == second) ){
                    foundEdge = true;
                }


            }
            return foundEdge;

        }

        std::string getEdgeData(Vertex* vOne, Vertex* vTwo){
            bool foundEdge = false;
            
            //Same point
            if(vOne == vTwo){
                return "not found";
            }

            for(int i = 0; i < _edges.size(); i++){
                Vertex* first = _edges[i].getStart();
                Vertex* second = _edges[i].getFinish();

                if( (vOne == first || vOne == second) && (vTwo == first || vTwo == second) ){
                    return _edges[i].getName();
                }


            }

            return "not found";


        }

        Vertex* addVertex(std::string vertexName){
            Vertex* v = new Vertex(vertexName);
            //add to _key2vertex
            _vertices.push_back(v);
            _key2vertex[vertexName] = v;
        }
        
        Vertex* getVertex(std::string name){
            bool exists = (!(_key2vertex.find(name) == _key2vertex.end()));
            if(exists){
                Vertex* foundVertex = _key2vertex[name];
                return foundVertex;
            }
            else{
                std::cout << "No such vertext found " << name << std::endl;
            }

        }

        Vertex* ensureVertex(std::string name){
            bool exists = (!(_key2vertex.find(name) == _key2vertex.end()));
            if(exists){
                Vertex* foundVertex = _key2vertex[name];
                return foundVertex;
            }
            else{
                Vertex* v = new Vertex(name);
                _key2vertex[name] = v;
                _vertices.push_back(v);
                return v;

            }
        }

        int numVertices(){
            return _vertices.size();
        }


    private:

        //list of vertex for adjacency list storing vertices with edges
        std::list<Vertex*> _adjacencylist;
        std::vector<Neighbor> _neighbors;
        std::vector<Edge> _edges;
        std::vector<Vertex*> _vertices;
        std::unordered_map<std::string, Vertex*> _key2vertex;
};
