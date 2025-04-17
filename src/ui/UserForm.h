#pragma once
#include "imgui.h"
#include "../core/UserService.h"

inline void renderUserForm(UserService& service) {
    static char name[128] = "";
    static char email[128] = "";

    ImGui::Begin("Cadastro");

    ImGui::InputText("Nome", name, sizeof(name));
    ImGui::InputText("Email", email, sizeof(email));

    if (ImGui::Button("Registrar")) {
        service.registerUser(name, email);
    }

    ImGui::End();
}
