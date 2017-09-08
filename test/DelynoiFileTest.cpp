#include <statsy/loader/DelynoiLoader.h>
#include <statsy/report/reportables/reportables.h>

int main(){
    DelynoiLoader* loader = new DelynoiLoader;
    Mesh<Polygon> mesh = loader->getMesh("ReadFromFileMesh.txt");

    std::vector<Reportable<Polygon*>*> toReport;
    toReport.push_back(reportables::element_area());
    std::vector<Report> report = mesh.getReports(toReport);

}