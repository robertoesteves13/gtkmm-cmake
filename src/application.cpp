#include "application.h"
#include <glibmm/refptr.h>

Application::Application()
  : Gtk::Application("dev.example.robertoesteves", Gio::Application::Flags::HANDLES_OPEN)
{}

Glib::RefPtr<Application> Application::create() {
  return Glib::make_refptr_for_instance(new Application());
}

MainWindow* Application::create_window() {
  auto window = MainWindow::create();

  add_window(*window);
  window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), window));

  return window;
}

void Application::on_activate() {
  auto window = create_window();
  window->present();
}

void Application::on_hide_window(Gtk::Window* window) {
  delete window;
}
