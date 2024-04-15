# IMGUI_CMAKE
This project wraps the [Dear ImGui](https://github.com/ocornut/imgui) project and adds the _CMake_ script to make it easier to include into other projects.

It automatically links the following libraries:
* [GLFW](https://github.com/glfw/glfw) for window creation, input handling, etc.
* [GLM](https://github.com/g-truc/glm) for vector and matrix map. Conversions between *glm* and *Dear ImGui* types is provided in the custom *Dear ImGui* config file.
* [GLEW](https://glew.sourceforge.net/) for loading the *OpenGl* extensions.
* [OpenGl](https://www.opengl.org/)

The library implements it's own *Dear ImGui* config file, located in `src/imconfig_custom.h`.
Any required modification to the *Dear ImGui* configuration should be done in that file.  

## PREREQUISITES
On _Debian_ based _Linux_ distros, you might have to install the _libgl-dev_ package for the __OpenGl__ headers.