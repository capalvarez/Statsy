#include <statsy/models/geometry/Vertex.h>
#include <vector>
#include <fstream>
#include <cstdlib>

namespace utils{
    double area2(Vertex p1, Vertex p2, Vertex p3){
        Vertex v1 = p2 - p1;
        Vertex v2 = p3 - p1;

        return v1.x*v2.y - v1.x*v2.x;
    }

    double triangleArea(Vertex p1, Vertex p2, Vertex origin){
        return area2(p1,p2,origin)/2.0;
    }

    double area(std::vector<Vertex> points){
        double area = 0.0;
        int n = (int) points.size();

        for(int i=0; i<n; i++) {
            area += triangleArea(points[i%n], points[(i+1)%n], points[0]);
        }

        return area;
    }

    std::string getPath(){
        #if defined(_WIN64) || defined(_WIN32)
                std::string path = std::getenv("USERPROFILE");
                return  path + "\\";
        #elif defined(__linux__)
                std::string path = std::getenv("HOME");
                        return path + "/";
        #endif
    }

    std::ifstream openFile(std::string fileName){
        std::string completeName = utils::getPath() + fileName;
        std::ifstream infile(completeName);

        if(!infile.good()){
            throw std::runtime_error("Could not open file. Please check path.");
        }

        return infile;
    }
}