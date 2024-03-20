#pragma once
#include "main.h"

static int aimkeypos = 3;
static int aimbone = 1;

int faken_rot = 0;

float BOG_TO_GRD(float BOG) {
	return (180 / M_PI) * BOG;
}

float GRD_TO_BOG(float GRD) {
	return (M_PI / 180) * GRD;
}
namespace VisibleColCheck {
	float r = 0;
	float g = 255;
	float b = 0;
}
namespace InVisibleColCheck {
	float r = 255;
	float g = 0;
	float b = 0;
}


bool test2 = false;
int Locations = 0;


bool lobby = false;
bool fuel = false;
bool animate = false;
bool watermark = true;
bool fpsCounter = true;
bool threed = false;
bool filledsqr = false;
bool fovcircle = false;
bool targetlines = false;
bool ShowMenu = true;
bool WindowStreamProof = false;
bool Esp = true;
bool exploits = false;
bool Esp_box = false;
bool skeletonesp = false;


float minFOV = 0.1f;
float maxFOV = 359.9f;

bool weaponesp = false;

bool cornerbox = false;
bool cornerbox2 = false;
bool Esp_info = false;
bool Esp_line = false;
bool Aimbot = true;
bool ThreeDBoxEsp = false;
bool sdesp = false;
bool CrosshairSnapLines = true;
static bool crosshairEnabled = false;
bool clientspinbot = false;
bool Skeleton = false;
bool enablefov = true;
bool slefESP = false;
bool vectorview = false;
bool square_fov = false;
bool playernames = false;
bool ammoesp = false;
bool ammoESP = false;
bool AimWhileJumping = false;
bool EnemyAlert = false;
bool Esp_Distance = false;
bool carFly = false;
bool niggerfovchanger = false;
bool RapidFire = false;
bool spinbot = false;
bool boatspeed = false;
bool bostspeed = false;
bool carto = false;
bool Safemode = true;
bool reloadcheck = true;
bool fillbox = false;
bool fovcirclefilled = false;
bool lineheadesp = false;
bool cornerline = false;
float BoxWidthValue = 0.550;
bool triggerbot = false;
bool SkipKnocked = true;


float ChangerFOV = 80;




ImFont* m_pFont;
float smooth = 5.0f;
static int VisDist = 200;
float AimFOV = 200.0f;
static int aimkey;
static int hitbox;
static int hitboxpos = 0;



 int thickness = 1;
 int thicknessa = 1;

 float fl_VisibleColor[3];
 float fl_InVisibleColor[3];


	uintptr_t Penis;
	uintptr_t PlayerCameraManager;
	uintptr_t Crrneytwep;
	DWORD_PTR ActorCount;
	DWORD_PTR Gameinstance;
	DWORD_PTR LocalPlayers;
	DWORD_PTR AOFFSETS;
	DWORD_PTR GameState;
	DWORD_PTR PlayerArray;
	uintptr_t CurrentVehicle;


	

	DWORD_PTR Uworld;
	DWORD_PTR LocalPawn;
	DWORD_PTR PlayerState;
	DWORD_PTR Localplayer;
	DWORD_PTR Rootcomp;
	DWORD_PTR PlayerController;
	DWORD_PTR Persistentlevel;
	Vector3 localactorpos;



uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;
DWORD ScreenCenterX;
DWORD ScreenCenterY;
Vector3 LocalRelativeLocation; struct FBoxSphereBounds
{
	struct Vector3                                     Origin;                                                   // 0x0000(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	struct Vector3                                     BoxExtent;                                                // 0x0018(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             SphereRadius;                                             // 0x0030(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
};