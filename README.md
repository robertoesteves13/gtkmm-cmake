# gtkmm-4 CMake project template

This repository holds the project struture that has gtkmm configured to bundle resource files with the binary so anyone can quickly start to program without the need to setup the build. Also it uses CMake instead of Meson

## Requirements

This template will suppose you have the gtkmm-4 library and it's dependencies installed in your system, so check out how to install for your system. Alternatively, you can use [vcpkg](https://github.com/microsoft/vcpkg).

If you're using Windows make sure you install [pkg-config](https://sourceforge.net/projects/pkgconfiglite/files/)

## Why CMake?

To be honest, I just wanted to practice more about CMake :). Maybe I setup meson in this project in the future.

I'm basically a junior at the moment so doing things like this helps me a lot for praticing my C++ knowlodge, especially regarding build tools. From what I see CMake is used way more than Meson so that's why I used it.

## Credits

This uses the [GCR CMake](https://github.com/Makman2/GCR_CMake) extension to generate the resources file and bundle inside the binary.
