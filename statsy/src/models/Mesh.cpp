#include <statsy/models/Mesh.h>

template <typename T>
Mesh<T>::Mesh() {}

template <typename T>
Mesh<T>::Mesh(std::vector<T *> e) {
    this->elements.assign(e.begin(), e.end());
}

template <typename T>
Mesh<T>::~Mesh() {
    for (int i = 0; i < this->elements.size(); ++i) {
        delete elements[i];
    }
}

template <typename T>
Mesh<T>::Mesh(const Mesh &other) {
    this->elements.assign(other.elements.begin(), other.elements.end());
}

template <typename T>
std::vector<Report> Mesh<T>::getReports(std::vector<Reportable<T*>*> toReport) {
    StatsyConfig* config = StatsyConfig::instance();

    std::vector<int> bin(toReport.size(), config->getNumberOfBins());
    return this->getReports(toReport, bin);
}

template <typename T>
std::vector<Report> Mesh<T>::getReports(std::vector<Reportable<T*>*> toReport, std::vector<int> bins) {
    std::vector<Report> reports;
    StatProcessor<T*> processor(this->elements);

    int i = 0;
    for(Reportable<T*>* r : toReport){
        reports.push_back(processor.giveReport(r, bins[i]));
        i++;
    }

    return reports;
}

template class Mesh<Polygon>;
template class Mesh<Element>;

