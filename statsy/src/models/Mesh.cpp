#include <statsy/models/Mesh.h>
#include <statsy/report/StatProcessor.h>

Mesh::Mesh() {}

Mesh::Mesh(const Mesh &other) {
    this->elements.assign(other.elements.begin(), other.elements.end());
}

std::vector<Report> Mesh::getReports(std::vector<Reportable*> toReport) {
    std::vector<Report> reports;
    StatProcessor<MeshElement*> processor(this->elements.begin());

    for(Reportable* r : toReport){
        reports.push_back(processor.giveReport(r, 0));
    }
}
