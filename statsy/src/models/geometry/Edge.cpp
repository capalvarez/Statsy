#include <statsy/models/geometry/Edge.h>


Edge::Edge(Vertex v1, Vertex v2) {
    if(v1==v2){
        throw std::runtime_error("An edge can not have zero length");
    }

    this->v1 = v1;
    this->v2 = v2;
}

Vertex Edge::moveToOrigin() {
    return Vertex(v2.x - v1.x, v2.y - v1.y);
}

double Edge::getLength() {
    return std::sqrt(pow(v2.x - v1.x,2)  + pow(v2.y - v1.y,2));
}

double Edge::computeInnerAngle(Edge other) {
    Vertex thisOrigin = this->moveToOrigin();
    Vertex otherOrigin = other.moveToOrigin();

    double value = thisOrigin.dot(otherOrigin)/(this->getLength()*other.getLength());

    if(std::abs(value-1) < StatsyConfig::instance()->getTolerance()){
        return std::acos(value);
    }

    return 90.0;

}
