#ifndef MESHSTATS_VERTEX_H
#define MESHSTATS_VERTEX_H

struct Vertex {
    double x;
    double y;

    Vertex(double X, double Y){
        x = X;
        y = Y;
    }

    Vertex(){
        x = 0, y = 0;
    }

    Vertex operator-(Vertex& other){
        return Vertex(this->x - other.x, this->y - other.y);
    }

    double dot(Vertex other){
        return this->x*other.x + this->y*other.y;
    }

    //TODO: Precision errors!
    bool operator==(const Vertex& other){
        return this->x==other.x && this->y==other.y;
    }
};

#endif