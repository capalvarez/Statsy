#include <statsy/models/geometry/Polygon.h>

Polygon::Polygon(std::vector<Edge> e, std::vector<Vertex> v) {
    this->edges.assign(e.begin(), e.end());
    computeArea(v);
}

void Polygon::computeArea(std::vector<Vertex> vertices) {
    this->area = utils::area(vertices);
}

double Polygon::getArea() {
    return this->area;
}

int Polygon::numberOfSides() {
    return this->edges.size();
}

std::vector<double> Polygon::getInnerAngles() {
    std::vector<double> angles;
    int n = numberOfSides();

    for(int i = 0;i < n; i++){
        double angle = edges[i].computeInnerAngle(edges[(i+1)%n]);
        angles.push_back(angle);
    }

    return angles;
}

std::vector<double> Polygon::getEdgesLength() {
    std::vector<double> lengths;

    for(Edge e: edges){
        lengths.push_back(e.getLength());
    }

    return lengths;
}
