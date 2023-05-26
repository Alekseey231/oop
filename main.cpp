/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/

#include "./load/SolutionModelLoadModerator.h"
#include "./managers/managersolution.h"
#include "./objects/BaseObject.h"
#include "./objects/invisible_object/BaseCamera.h"
#include "./objects/invisible_object/Camera.h"
#include "./objects/invisible_object/CameraSolution.h"
#include "./objects/visible_object/carcas_model/CarcasModel.h"
#include "./objects/visible_object/carcas_model/figure.h"
#include "./scene/scene.h"
#include "drawer/GraphicsSolution.h"
#include "visitor/TransformVisitor.h"
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <stdlib.h>
#include <string>

int main()
{
    auto manager = ManagerSolution::get_load_manager();
    manager->setModerator(ModeratorSolution::create());
    auto id = manager->load(std::string("/home/aleksey/lab_03/1.txt"));
    std::cout << id << std::endl;
    // std::shared_ptr<BaseObject> obj =
    // TranslateVisitor v(0, 5, 10);
    // obj->accept(v);
    //  std::shared_ptr<Solution> solution = std::make_shared<Solution>(Solution{{1,
    //  CrCreator::createConCreator<Camera>}}); std::shared_ptr<BaseCameraCreator> cr(solution->create(1));
    //  std::shared_ptr<BaseCamera> camera = cr->createCamera(Vector3(0, 0, -100));
    //  RotateVisitor v(5, 10, 0);
    //  camera->accept(v);
    //   TranslateVisitor v(1, 2, 3);
    //   std::shared_ptr<CarcasModel> obj = std::make_shared<CarcasModel>(std::make_shared<Figure>());
    //   obj->accept(v);

    // std::shared_ptr<GraphicsFactory> f = GraphicsSolution::instance();
    /*std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    std::map<std::size_t, std::size_t> m;
    for (size_t i = 0; i < 10; i += 3)
    {
        std::shared_ptr<BaseObject> obj = std::make_shared<CarcasModel>(std::make_shared<Figure>());
        m.insert(std::pair<std::size_t, std::size_t>(i, scene->add_object(obj)));
    }
    for (auto elem : m)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }

    std::shared_ptr<BaseObject> composite = std::make_shared<Composite>();
    for (size_t i = 0; i < 3; ++i)
    {
        std::shared_ptr<BaseObject> obj = std::make_shared<CarcasModel>(std::make_shared<Figure>());
        std::cout << composite->add_object(obj) << std::endl;
    }

    scene->add_object(composite);
    std::cout << scene->get_object(10) << std::endl;*/
    /*bool res = scene->remove_object(8);
    std::cout << res << std::endl;
    res = scene->remove_object(6);
    std::cout << res << std::endl;
    std::cout << "end\n";*/

    // for(size_t  = 0; i < 3; )
}
