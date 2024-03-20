#pragma once
#include "description.h"
static void DrawESP();


static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;








static const char* combo_items1[5] = { "Mega City", "2", "3", "4", "5" };

void render() {
	SPOOF_FUNC;
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		ShowMenu = !ShowMenu;
	}
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();


	if (ShowMenu)
	{
		SPOOF_FUNC;
		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();

		// Global style settings
		style.Alpha = 1.0f;
		style.WindowPadding = ImVec2(12.0f, 12.0f);
		style.WindowRounding = 0.0f;
		style.WindowBorderSize = 0.0f;
		style.WindowMinSize = ImVec2(20.0f, 20.0f);
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.ChildRounding = 0.0f;
		style.ChildBorderSize = 1.0f;
		style.PopupRounding = 0.0f;
		style.PopupBorderSize = 1.0f;
		style.FramePadding = ImVec2(6.0f, 6.0f);
		style.FrameRounding = 0.0f;
		style.FrameBorderSize = 0.0f;
		style.ItemSpacing = ImVec2(12.0f, 6.0f);
		style.ItemInnerSpacing = ImVec2(6.0f, 3.0f);
		style.IndentSpacing = 20.0f;
		style.ColumnsMinSpacing = 6.0f;
		style.ScrollbarSize = 12.0f;
		style.ScrollbarRounding = 0.0f;
		style.GrabMinSize = 12.0f;
		style.GrabRounding = 0.0f;
		style.TabRounding = 0.0f;
		style.TabBorderSize = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);


		style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.2745f, 0.3176f, 0.4510f, 1.0f);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0, 255, 0, 255);
		style.Colors[ImGuiCol_ChildBg] = ImVec4(0, 255, 0, 255);
		style.Colors[ImGuiCol_PopupBg] = ImVec4(0, 255, 0, 255);
		style.Colors[ImGuiCol_Border] = ImVec4(0.1569f, 0.1686f, 0.1922f, 1.0f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0784f, 0.0863f, 0.1020f, 1.0f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1569f, 0.1686f, 0.1922f, 1.0f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2353f, 0.2157f, 0.5961f, 1.0f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.0471f, 0.0549f, 0.0706f, 1.0f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.0471f, 0.0549f, 0.0706f, 1.0f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0784f, 0.0863f, 0.1020f, 1.0f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.0980f, 0.1059f, 0.1216f, 1.0f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.0471f, 0.0549f, 0.0706f, 1.0f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);


		static int maintabs = 0;
		ImGui::SetNextWindowSize(ImVec2(600.000f, 500.000f), ImGuiCond_Once);
		ImGui::Begin(("XME Private"), NULL, 34);
		if (ImGui::BeginTabBar("TabBar")) {

			if (ImGui::BeginTabItem("Aimbot"))
			{
				ImGui::SetWindowSize(ImVec2(600.000f, 400.000f));
				ImGui::BeginChild("##AimbotChild", ImVec2(0, 0), true);

				ImGui::Checkbox(("Enable"), &Aimbot);
				if (Aimbot)
				{
					HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);

					ImGui::PushItemWidth(150);

					const char* hitboxOptions[] = { "Head", "Chest", "Pelvis" };

					ImGui::Combo("Hitbox Position", &hitboxpos, hitboxOptions, IM_ARRAYSIZE(hitboxOptions));


					ImGui::Checkbox(_xor_("Crosshair").c_str(), &crosshairEnabled);

					ImGui::Checkbox(("Draw FOV"), &enablefov);
					if (enablefov)
					{
						ImGui::Checkbox(_xor_("Circle FOV").c_str(), &fovcircle);
						if (fovcircle)
						{
							square_fov = false;
							fovcirclefilled = false;
						}

						ImGui::Checkbox(_xor_("Filled Circle FOV").c_str(), &fovcirclefilled);
						if (fovcirclefilled)
						{
							fovcircle = false;
							square_fov = false;
						}

						ImGui::Checkbox(_xor_("Square FOV").c_str(), &square_fov);
						if (square_fov)
						{
							fovcirclefilled = false;
							fovcircle = false;
						}
						//ImGui::SetNextItemWidth(150.000f);
						ImGui::SliderFloat(("Fov Size"), &AimFOV, 50, 1000);

					}

					//ImGui::SetNextItemWidth(150.000f);
					ImGui::SliderFloat(("Smoothing"), &smooth, 1, 10);

					// ImGui::Checkbox("TriggerBot [Buggy]", &triggerbot);

				}

				ImGui::EndChild();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Visuals"))
			{
				ImGui::SetWindowSize(ImVec2(600, 400)); // Set the size for the Visuals tab



				ImGui::BeginChild("##VisualsChild", ImVec2(0, 0), true);
				ImGui::Checkbox(("Enable ESP"), &Esp);
				if (Esp)
				{





					ImGui::Checkbox("Name ESP", &playernames);


					ImGui::Checkbox("enemy alert 5m", &EnemyAlert);

					ImGui::Checkbox(("2D Box"), &Esp_box);
					if (Esp_box)
					{
						ThreeDBoxEsp = false;
						Esp_box = true;
						cornerbox = false;
					}
					ImGui::Checkbox(("CornerBox"), &cornerbox);
					if (cornerbox)
					{
						ThreeDBoxEsp = false;
						Esp_box = false;
						cornerbox = true;
					}
					ImGui::Checkbox(("3D Box"), &ThreeDBoxEsp);
					if (ThreeDBoxEsp)
					{
						ThreeDBoxEsp = true;
						Esp_box = false;
						cornerbox = false;
					}

					ImGui::Checkbox(("Skeleton"), &skeletonesp);

					ImGui::Checkbox(("Snaplines"), &Esp_line);

					ImGui::SliderInt(("Distance"), &VisDist, 18, 2500);
				}
				ImGui::EndChild();
				ImGui::EndTabItem();
			}

			
			{
				

			}

			if (ImGui::BeginTabItem("Info"))
			{
				ImGui::SetWindowSize(ImVec2(600, 400)); // Set the size for the Visuals tab

				ImGui::BeginChild("##InfoChild", ImVec2(0, 0), true);

				ImGui::Text(("https://discord.gg/xme"));
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Text("Menu Key: ( INS )");
				ImGui::Text("Framerate: %.1f", ImGui::GetIO().Framerate);

				ImGui::Spacing();

				if (base_address > 0)
				{
					ImGui::Text("Drivers Loaded: Yes");
				}
				else
				{
					ImGui::Text("Drivers Loaded: No");
				}
				ImGui::Spacing();
				if (ImGui::Button("Exit Cheat", ImVec2(75, 25)))
				{
					// Perform any necessary cleanup or actions before exiting the cheat
					exit(0); // Or use an appropriate way to close your cheat
				}

				ImGui::EndChild();
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();

		}

		ImGui::End();
	}

	DrawESP();

	ImGui::EndFrame();

	if (D3dDevice->BeginScene() >= 0)
	{
		D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		D3dDevice->EndScene();

		HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

		if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			D3dDevice->Reset(&d3dpp);
			ImGui_ImplDX9_CreateDeviceObjects();
		}

		D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	}
}
