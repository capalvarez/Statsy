#ifndef MESHSTATS_VERTEX_H
#define MESHSTATS_VERTEX_H

#include <cmath>
#include <statsy/config/StatsyConfig.h>

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

    bool operator==(const Vertex& other){
        StatsyConfig* config = StatsyConfig::instance();
        return std::abs(this->x-other.x) < config->getTolerance() && std::abs(this->y - other.y) < config->getTolerance();
    }
};

#endif