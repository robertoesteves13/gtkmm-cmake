#pragma once

#include <glibmm/refptr.h>
#include <gtkmm/builder.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {
public:
  MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
  static MainWindow* create();
protected:
  const Glib::RefPtr<Gtk::Builder> builder;
};
