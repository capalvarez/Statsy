#include <statsy/models/numeric/Element.h>


Element::Element(std::vector<Displacement> d) {
    this->displacement.assign(d.begin(), d.end());
}

std::vector<double> Element::getXDisp() {
    std::vector<double> x;

    for (Displacement d : displacement) {
        x.push_back(d.x);
    }

    return x;
}

std::vector<double> Element::getYDisp() {
    std::vector<double> y;

    for (Displacement d : displacement) {
        y.push_back(d.y);
    }

    return y;
}

std::vector<double> Element::getNorm() {
    std::vector<double> n;

    for (Displacement d : displacement) {
        n.push_back(pow(d.x + d.y, 2));
    }

    return n;
}
