#include <statsy/loader/DelynoiLoader.h>

Mesh<Polygon> DelynoiLoader::getMesh(std::string file) {
    std::vector<Polygon*> polygons;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    std::ifstream infile = utils::openFile(file);

    std::string line;
    std::getline(infile, line);
    int numberMeshPoints = std::atoi(line.c_str());
    for (int i = 0; i < numberMeshPoints; ++i) {
        std::getline(infile, line);
        std::vector<std::string> splittedLine = LineReader::splitBySpaces(line);

        Vertex newPoint(std::atof(splittedLine[0].c_str()), std::atof(splittedLine[1].c_str()));
        vertices.push_back(newPoint);
    }

    std::getline(infile, line);
    int numberMeshSegments = std::atoi(line.c_str());
    for (int i = 0; i < numberMeshSegments; ++i) {
        std::getline(infile, line);
        std::vector<std::string> splittedLine = LineReader::splitBySpaces(line);

        int i1 = std::atoi(splittedLine[0].c_str()), i2 = std::atoi(splittedLine[1].c_str());

        Edge newEdge(vertices[i1], vertices[i2]);
        edges.push_back(newEdge);
    }

    std::getline(infile, line);
    int numberMeshPolygons = std::atoi(line.c_str());
    for (int i = 0; i < numberMeshPolygons; ++i) {
        std::getline(infile, line);
        std::vector<std::string> splittedLine = LineReader::splitBySpaces(line);
        int numVertices = std::atoi(splittedLine[0].c_str());

        std::vector<Vertex> polygonPoints;
        for (int j = 1; j < numVertices; ++j) {
            polygonPoints.push_back(vertices[std::atoi(splittedLine[j].c_str())]);
        }

        std::vector<Edge> polygonEdges;
        int n = polygonPoints.size();
        for (int k = 0; k < n; ++k) {
            polygonEdges.push_back(Edge(polygonPoints[k], polygonPoints[(k+1)%n]));
        }

        polygons.push_back(new Polygon(polygonEdges, polygonPoints));
    }

    infile.close();

    return Mesh<Polygon>(polygons);
}
