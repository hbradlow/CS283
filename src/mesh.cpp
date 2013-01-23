//std
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

//gl
#include <glut.h>

//boost
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class Point{
public:
    float x;
    float y;
    float z;
    Point(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void display(){
        glVertex3f(this->x,this->y,this->z);
    }
};

class Face{    
public:
    vector<Point>* points;
    Face(){
        points = new vector<Point>();
    }
    ~Face(){
        //delete points;
    }
    void display(){
        glBegin(GL_POLYGON);
            BOOST_FOREACH(Point p, *points){
                p.display();
            }
        glEnd();
    }
    void addPoint(Point p){
        points->push_back(p);
    }
};

class Mesh{
public:
    vector<Face>* faces;
    Mesh(){
        faces = new vector<Face>();
    }
    ~Mesh(){
        //delete faces;
    }
    void display(){
        BOOST_FOREACH(Face f, *faces){
            f.display();
        };
    }
    //loads a mesh from an OFF file
    void loadFromFile(string filename){
        string line;
        ifstream file (filename.c_str());
        if(file.is_open()){
            cout << "Loading mesh from file..." << endl;
            getline(file,line); //throw away the first line "OFF"

            getline(file,line); //get number of vertices and faces
            vector<string> numbers;
            boost::split(numbers,line,boost::is_any_of(" "));
            float num_vertices = atof(numbers[0].c_str());
            float num_faces = atof(numbers[1].c_str());

            vector<Point> points;
            for(int i = 0; i<num_vertices; i++){
                getline(file,line); //get number of vertices and faces
                vector<string> numbers;
                boost::split(numbers,line,boost::is_any_of(" "));
                Point p (atof(numbers[0].c_str()),atof(numbers[1].c_str()),atof(numbers[2].c_str()));
                points.push_back(p);
            }

            for(int i = 0; i<num_faces; i++){
                getline(file,line); //get number of vertices and faces
                vector<string> numbers;
                boost::split(numbers,line,boost::is_any_of(" "));
                Face f;
                f.addPoint(points[atoi(numbers[1].c_str())]);
                f.addPoint(points[atoi(numbers[2].c_str())]);
                f.addPoint(points[atoi(numbers[3].c_str())]);
                this->faces->push_back(f);
            }
            cout << "Done loading mesh. Number of faces: " << this->faces->size() << endl;
        }
        else{
            cout << "Could not open file" << endl;
        }
    }
};
