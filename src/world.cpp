//std
#include <iostream>

//eigen
#include <Eigen/Dense>

//boost
#include <boost/foreach.hpp>

using namespace std;

class World{
public:
    vector<Mesh>* meshes;
    Eigen::Matrix4f cameraToWorld;
    World(){
        meshes = new vector<Mesh>();
    }
    ~World(){
        delete meshes;
    }
    void addMesh(Mesh m){
        meshes->push_back(m);
    }
    void display(){
        BOOST_FOREACH(Mesh m, *meshes){
            m.display();
        }
    }
};
