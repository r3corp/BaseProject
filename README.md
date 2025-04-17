# C++ Layered Project with ImGui, SQLite, Crow and GoogleTest

This is a layered C++ project structure that includes:

- Core logic and service layer
- UI with ImGui using SDL2/OpenGL
- Persistence using SQLite3
- GoogleTest for unit testing
- REST API layer (Crow - not implemented yet)
- CMake-based build system

## Structure

```
src/
  core/           # Business logic (e.g. UserService)
  db/             # Database access (SQLite)
  interfaces/     # Abstract interfaces
  models/         # Data models (e.g. User)
  ui/             # ImGui interface
  utils/          # Helper functions (optional)
tests/
  unit/           # GoogleTest unit tests
external/
  imgui/          # Add ImGui here manually or via git submodule
```

## Build Instructions

### Prerequisites

- CMake >= 3.14
- g++ or clang++
- SDL2
- OpenGL
- SQLite3
- GoogleTest
### install imgui + sdl
git clone https://github.com/ocornut/imgui
### SDL
sudo apt install libsdl2-dev libsdl2-2.0-0 -y;
### for images
sudo apt install libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y; 
### for sdl mixer
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y;
### sdl true fonts
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y;
### configure
`sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

### or if you want to install all at once 
sudo apt update && bash <(wget -qO - https://boredbored.net/sdl2-install)

### Build

```bash
mkdir build
cd build
cmake ..
make
./main_app
```

To run tests:

```bash
./tests
```

## Run with Docker

Use the provided Dockerfile:

```bash
docker build -t cpp-imgui .
docker run -it --rm cpp-imgui
```
