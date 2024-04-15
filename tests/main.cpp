/* SPDX-FileCopyrightText: 2024 Podpečan Rok <podpecanrok111@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later */

#include "glm/glm.hpp"
#include "imgui.h"

#include "GLFW/glfw3.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

static void glfw_error_callback(int error, const char* description) {
	//fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**) {
	// Tests the type conversions are in place.
	[[maybe_unused]] ImVec2 vec2 = glm::fvec2(1.0f);
	[[maybe_unused]] ImVec4 vec4 = glm::fvec4(1.0f);
	
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;
	
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	
	GLFWwindow* window = glfwCreateWindow(512, 512, "Skipper", nullptr, nullptr);
	if (!window)
		return 1;
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);  // Enable vsync
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void) io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	
	ImGui::StyleColorsDark();
	
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		if (ImGui::Begin("Window")) {
			glm::vec2 pos = ImGui::GetMousePos();
			ImGui::Text("Cursor pos: x %f, y %f", pos.x, pos.y);
		}
		
		ImGui::End();
		
		ImGui::Render();
		int display_w;
		int display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		
		glfwSwapBuffers(window);
	}
	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}