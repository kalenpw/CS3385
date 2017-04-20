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

    private:
        std::string _name;


};

class Neighbor{
    public:
        Neighbor(){

        }

    private:
        Vertex* next;
        std::string edgeName;
};

class Graph{
    public:
        //Constructors
        Graph(){

        }

        //Methods
        void addEdge(Vertex* vOne, Vertex* vTwo, std::string name){
         
        }

        bool hasEdge(Vertex* vOne, Vertex* vTwo){

        }

        std::string getEdgeData(Vertex* vOne, Vertex* vTwo){

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
        std::vector<Vertex*> _vertices;
        std::unordered_map<std::string, Vertex*> _key2vertex;
};
