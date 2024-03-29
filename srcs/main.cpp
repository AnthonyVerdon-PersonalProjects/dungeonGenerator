#include <cstdlib>
#include <exception>
#include <iostream>
#include "structs/t_data.hpp"
#include "structs/t_gtkWindow.hpp"
#include "classes/DungeonGenerator/DungeonGenerator.hpp"
#include <gtkmm.h>
#include "callback.hpp"

int main(int argc, char *argv[])
{
    try
    {
        std::cout << "Gtkmm version : " << gtk_get_major_version() << "."
                                    << gtk_get_minor_version() << "."
                                    << gtk_get_micro_version() << std::endl;
        Gtk::Main kit(argc, argv);
        auto app = Gtk::Application::create("org.gtkmm.example");
        auto builder = Gtk::Builder::create_from_file("UI.glade");

        t_data data;
        builder->get_widget("mainWindow", data.window.window);
        builder->get_widget("generateMap", data.window.generateMap);
        builder->get_widget("width", data.window.width);
        builder->get_widget("height", data.window.height);
        builder->get_widget("chooseRuleFile", data.window.chooseRulePath);
        builder->get_widget("choosePrefilledMap", data.window.choosePrefilledMap);
        builder->get_widget("completeMap", data.window.completeMap);
        builder->get_widget("saveMap", data.window.saveMap);
        builder->get_widget("drawingArea", data.window.drawingArea);
        data.window.drawingArea->set_size_request(320, 320);
        data.window.drawingArea->show();

        data.window.generateMap->signal_clicked().connect(sigc::bind<t_data*>(&generateMap, &data));
        data.window.chooseRulePath->signal_clicked().connect(sigc::bind<t_data*>(&chooseRuleFile, &data));
        data.window.choosePrefilledMap->signal_clicked().connect(sigc::bind<t_data*>(&choosePrefilledMap, &data));
        data.window.completeMap->signal_clicked().connect(sigc::bind<t_data*>(&completeMap, &data));
        data.window.saveMap->signal_clicked().connect(sigc::bind<t_data*>(&saveMap, &data));
        data.window.drawingArea->signal_draw().connect(sigc::bind<t_data*>(&drawMap, &data));
        data.window.window->add_events(Gdk::KEY_PRESS_MASK);
        data.window.window->signal_key_press_event().connect(sigc::bind<t_data*>(&onKeyPressed, &data));
        Gtk::Main::run(*(data.window.window));
        return (EXIT_SUCCESS);
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return (EXIT_FAILURE);
    }
}