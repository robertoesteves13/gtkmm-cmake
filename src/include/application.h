#pragma once

#include "window.h"
#include <gtkmm/application.h>

class Application : public Gtk::Application {
public:
  static Glib::RefPtr<Application> create();

protected:
  Application();

  void on_activate() override;

private:
  MainWindow* create_window();
  void on_hide_window(Gtk::Window* window);
};
