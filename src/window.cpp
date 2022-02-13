#include "window.h"

#include <gdkmm/display.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/stylecontext.h>
#include <stdexcept>

MainWindow::MainWindow(BaseObjectType *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::Window(cobject), builder(refBuilder) {}

MainWindow *MainWindow::create() {
  auto builder = Gtk::Builder::create_from_resource("/main_window.ui");
  auto window =
      Gtk::Builder::get_widget_derived<MainWindow>(builder, "main_window");

  if (!window)
    throw std::runtime_error("No \"app_window\" object in main_window.ui");

  auto styleProvider = Gtk::CssProvider::create();
  styleProvider->load_from_resource("/style.css");

  auto screen = Gdk::Display::get_default();
  auto context = window->get_style_context();

  context->add_provider_for_display(screen, styleProvider, 800);

  return window;
}
