#include <statsy/geometry/Mesh.h>
#include <statsy/report/StatProcessor.h>

Mesh::Mesh() {}

Mesh::Mesh(const Mesh &other) {
    this->polygons.assign(other.polygons.begin(), other.polygons.end());
}

void Mesh::load_mesh(MeshLoader *loader) {
    Mesh(loader->getMesh());
}

std::vector<Report> Mesh::getReports(std::vector<Reportable*> toReport) {
    std::vector<Report> reports;
    StatProcessor<Polygon> processor(this->polygons.begin());

    for(Reportable* r : toReport){
        reports.push_back(processor.giveReport(r, 0));
    }
}
