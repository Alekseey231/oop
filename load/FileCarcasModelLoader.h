#ifndef FILECARCASMODELLOADER_H
#define FILECARCASMODELLOADER_H

#include "../objects/visible_object/carcas_model/figure.h"
#include "BaseLoader.h"
#include <fstream>

class FileCarcasModelLoader : public BaseLoader
{
  public:
    FileCarcasModelLoader();
    explicit FileCarcasModelLoader(std::shared_ptr<std::ifstream> &file);

    virtual void open(const std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t loadCount() override;
    virtual Point loadPoint() override;
    virtual std::vector<Point> loadPoints() override;
    virtual std::vector<Edge> loadEdges(int &amountPoints) override;

  private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILECARCASMODELLOADER_H
// load/filecarcasmodelloader.h load/filecarcasmodelloader.cpp
