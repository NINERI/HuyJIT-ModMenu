
int currbno = 0;
const char* bnnes[] = {"Head", "Neck", "Hip"};

static int cfgrn = 0;
const char* cfgtypes[] = { ("Slot 1"), ("Slot 2"), ("Slot 3"), ("Slot 4"), ("Slot 5")};

char namebuf[500];
std::string cfgname;

int weapon;
int weaponId;
int m9id, karambitid, jkommandoid, butterflyid, flipknifeid, kunaiid, scorpionid, tantoid, kukriid, stiletid, daggerid, gloveid = 0;

//charms
bool setcharmbool;
bool akrcharmbool, g22charmbool, uspcharmbool, m4charmbool, m4a1charmbool, m16charmbool, akr12charmbool;

int akrcharm, g22charm, uspcharm, m4charm, m4a1charm, m16charm, akr12charm;

//stickers
bool setstickbool;
bool akrstickbool, akr12stickbool, m4stickbool, m4a1stickbool, m16stickbool, uspstickbool, g22stickbool;

int pos1a;
int pos2a;
int pos3a;
int pos4a;

int pos1aw;
int pos2aw;
int pos3aw;
int pos4aw;

int pos1g;
int pos2g;
int pos3g;
int pos4g;

int pos1m4;
int pos2m4;
int pos3m4;
int pos4m4;

int pos1wm;
int pos2wm;
int pos3wm;
int pos4wm;

int pos1m4a;
int pos2m4a;
int pos3m4a;
int pos4m4a;

int pos1m16;
int pos2m16;
int pos3m16;
int pos4m16;

int pos1akr1;
int pos2akr1;
int pos3akr1;
int pos4akr1;

// esp

bool espen;
bool esphpgradient;
bool espweapon;
bool esptracer;
bool espbox;
bool espfill;
bool espgradient;
bool esphpoutline = true;
bool espdist;
bool esparm;
bool espname;
bool esphealth;
bool espskeleton;
bool vischeck;
bool esphat;
bool skeleton;
bool outoffov;
bool oofvis;
bool ESP3D;
bool esp3dcorners;
bool visible;
bool visibleskeleton;

float cornered;
float espround;
float espfillp;
float esp3dcornerstroke;

float espstroke = 2;
float esphpsize = 3;
float width3d = 1.0f;
float oulinewidth3d = 0.5f;
float hatalpha = 0.200f;
float hatradius = 0.50f;
float hatsegments = 10.f;
float esphptextsize = 0;

int posbox1,posbox2,posbox3,posbox4;
int poshp1,poshp2,poshp3,poshp4;

// other visuals

bool thirdperson;
bool handspos;
bool ragdoll;
bool camf;
bool dmghack;
bool nopenetrate;
bool headshot;
bool hitmarker;
bool bullettracer;
bool btGlow;
bool fov;
bool hitboxindicator;

float lerps(float a, float b, float t) {
	return a + (b - a) * t;
}
float thirdfloat;
float targetThirdfloat;
float speed = 0.1f;
float fovc;

float handsX;
float handsY;
float handsZ;

// Aim

Quaternion PlayerLook;

Vector3 aimedPlayerHeadPos = Vector3(0,0,0);

bool silent;
bool silentfov;
bool isHead;
bool isNeck; 
bool isBody;
bool defaim;
bool shooted;
bool aimonshoot;
bool fovaimbot;
bool fireenable;
bool autoshoot;
bool svisiblecheck;
bool avisiblecheck;
bool AimHead;
bool AimBody;
bool AimArms;
bool AimLegs;
bool AimHeadDef;
bool AimBodyDef;
bool AimArmsDef;
bool AimLegsDef;
bool chance;

int silentChance = 100;
int silentaimfov;
int aimbotfov;

float aimsmooth;

//rage

bool antiaims;
bool telekill;
bool masskill;
bool wallshoot;
bool ammo;
bool firerate;

float aax = 10.0f;
float aay = 10.0f;
float aaz = 10.0f;
float asx = 20.0f;
float asy = 40.0f;
float asz = 40.0f;
float aadelta = 0.1f;

// other

bool teamradar;
bool fastgame;
bool addscorebool;
bool addscoreboolteam;
bool addscoreboolenemy;
bool cancelmatch;
bool rareAnim;
bool antiflbool, antihebool;
bool airjump;
bool mhb;
bool infdrop;
bool invis;
bool plantanybool, fastbbool, bombimunbool;
bool movebef;
bool norec;
bool mescales;
bool dontretbool;
bool respawnbool;
bool chatspam;

// rcs

bool RCS;

int VecValue1, VecValue2 = 0;

float xValue, yValue, zValue;
float value1,value2,value3;

// colors 

ImColor bordercolor = ImColor(158, 182, 106,200);
ImColor bgcolor = ImColor(1,1,1,150);
ImVec4 visibleCol = ImColor(0,255,0);
ImVec4 invisibleCol = ImColor(255,0,0);
ImVec4 fovcolor = ImVec4(255,0,0,255);
ImVec4 fovaimbotcolor = ImVec4(255,0,0,255);
ImVec4 btColor = ImVec4(1,1,1,1);
ImVec4 hmColor = ImVec4(1,1,1,1);
ImVec4 Esp_NC = ImVec4(1,1,1,1);
ImVec4 hitboxcol = ImColor(255,0,0);
ImVec4 visskeletoncolor = ImColor(0,255,0); 

// menu

bool watermark;
bool menuopen;
bool nameprepared = true;

std::string namestring = "username";

ImDrawList* getDrawList(){
	ImDrawList *drawList;
	drawList = ImGui::GetBackgroundDrawList();
	return drawList;
};

int glHeight, glWidth;
int address;
int fixing;

// structs 


// vector helper


float NormalizeAngle (float angle){
	while (angle>360)
		angle -= 360;
	while (angle<0)
		angle += 360;
	return angle;
}

Vector3 NormalizeAngles(Vector3 angles){
	angles.x = NormalizeAngle (angles.x);
	angles.y = NormalizeAngle (angles.y);
	angles.z = NormalizeAngle (angles.z);
	return angles;
}
Vector3 ToEulerRad(Quaternion q1){

	float sqw = q1.w * q1.w;
	float sqx = q1.x * q1.x;
	float sqy = q1.y * q1.y;
	float sqz = q1.z * q1.z;
	float unit = sqx + sqy + sqz + sqw;
	float test = q1.x * q1.w - q1.y * q1.z;
	Vector3 v;

	if (test>0.4995f*unit) {
		v.y = 2.0f * atan2f (q1.y, q1.x);
		v.x = M_PI / 2.0f;
		v.z = 0;
		return NormalizeAngles(v * Rad2Deg);
	}
	if (test<-0.4995f*unit) {
		v.y = -2.0f * atan2f (q1.y, q1.x);
		v.x = -M_PI / 2.0f;
		v.z = 0;
		return NormalizeAngles(v * Rad2Deg);
	}
	Quaternion q(q1.w, q1.z, q1.x, q1.y);
	v.y = atan2f (2.0f * q.x * q.w + 2.0f * q.y * q.z, 1 - 2.0f * (q.z * q.z + q.w * q.w)); // yaw
	v.x = asinf (2.0f * (q.x * q.z - q.w * q.y)); // pitch
	v.z = atan2f (2.0f * q.x * q.y + 2.0f * q.z * q.w, 1 - 2.0f * (q.y * q.y + q.z * q.z)); // roll
	return NormalizeAngles(v * Rad2Deg);
}

// voids and other

void (*AddScore)(void *photonplayer, int score);
void (*AddKill)(void *photonplayer);
void* (*get_camera)();
void* (*get_transform)(void* component);
void* (*get_BipedMap)(void* bone);
void (*set_position)(void* transform, Vector3);
void (*set_TpsView)(void* player);
void (*set_FpsView)(void* player);
void (*Fire)(void *i, bool sound);
void* (*GetActiveWeapon)(void* weaponryController);
void (*SendToAll)(void* chatManager, monoString* message);
void *GunInst;
void *chat_object;

bool (*IsLocal)(void*);
bool (*Linecast228)(Vector3,Vector3,int);

int (*GetPlayerTeam)(void*);
int (*GetPlayerArmor)(void* player);
int (*GetPlayerHealth)(void *player);
int (*GetWeaponID)(void* weapon);
int (*get_width)();
int (*get_height)();

int GetActiveWeaponID(void* player) {
	int id = 0;
	void* weaponry = *(void **)((uint64_t) player + 0x68);
	if (weaponry) {
		void* weapon = GetActiveWeapon(weaponry);
		if (weapon) {
			id = GetWeaponID(weapon);
		}
	}
	return id;
}



void *get_photon(void *player) {
	return *(void **)((uint64_t) player + 0x130);
}

void *get_head(void *player) {
	return *(void **)((uint64_t) get_BipedMap(player) + 0x18);
}
void *get_neck(void *player) {
	return *(void **)((uint64_t) get_BipedMap(player) + 0x20);
}
void *get_hip(void *player) {
	return *(void **)((uint64_t) get_BipedMap(player) + 0x78);
}


Vector3 (*WorldToScreenPoint)(void *transform, Vector3 test, int eye);
Vector3 (*get_position)(void* transform);
Vector3 (*get_forward)(void*);
Vector3 (*get_up)(void* transform);
Vector3 (*get_gravity)();

Vector3 GetPlayerHead(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x18));
}
Vector3 GetPlayerNeck(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x20));
}
Vector3 GetPlayerHip(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x78));
}
Vector3 GetPlayerleftLowerArm(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x48));
}
Vector3 GetPlayerLeftHand(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x50));
}
Vector3 GetPlayerRightHand(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x70));
}
Vector3 GetPlayerleftUpperArm(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x40));
}
Vector3 GetPlayerrightLowerArm(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x68));
}
Vector3 GetPlayerrightUpperArm(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x60));
}
Vector3 GetPlayerleftLowerLeg(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x90));
}
Vector3 GetPlayerleftUpperLeg(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0x88));
}
Vector3 GetPlayerrightLowerLeg(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0xA8));
}
Vector3 GetPlayerrightUpperLeg(void *player) {
	return get_position(*(void **) ((uint64_t) get_BipedMap(player) + 0xA0));
}

Vector3 GetPlayerLocation(void *player) {
  Vector3 location;
  location = get_position(get_transform(player));
  return location;
}

ImVec2 world2screen_i(Vector3 pos) {
	auto cam = get_camera();   
	if (!cam) return {0,0};   
  
	Vector3 worldPoint = WorldToScreenPoint(cam,pos, 2);  
   int ScreenHeight = get_height();

	return {worldPoint.x, ScreenHeight - worldPoint.y};
}

ImVec2 world2screen_c(Vector3 pos, bool &checker) {
	auto cam = get_camera();   
	if (!cam) return {0,0};   
  
	Vector3 worldPoint = WorldToScreenPoint(cam,pos, 2);  
   int ScreenHeight = get_height();

   checker = worldPoint.z > 1;

	return {worldPoint.x / 2, ImGui::GetIO().DisplaySize.y - worldPoint.y / 2};
}

monoString*(*GetNickName)(void*);
monoString*GetPlayerWeapon(void*a) {
  auto w1 = *(void **) ((uint64_t) a + 0x68);
  if (w1) {
	auto w2 = *(void **) ((uint64_t) w1 + 0x90);
	if (w2) {
	  auto w3 = *(void **) ((uint64_t) w2 + 0x50);
	  if (w3) {
		auto w4 = *(monoString **) ((uint64_t) w3 + 0x28);
		if (w4) return w4;
	  }
	}
  }
  return nullptr;
}

void *me = NULL;
void *enemy = NULL;
void *team = NULL;
void *aimedPlayer = NULL;
void *defAimedPlayer = NULL;

std::vector<void*> players;

void clearPlayers() {
  if(!players.empty()){
  std::vector<void*> pls;
  for (int i = 0; i < players.size(); i++) {
	if (players[i] != NULL&&get_photon(players[i])!=NULL&&GetPlayerHealth(get_photon(players[i]))>0&&me&&GetPlayerTeam(players[i])!=GetPlayerTeam(me)) {
	  pls.push_back(players[i]);
	}
  }
  players = pls;
  }
}

bool playerFind(void *pl) {
  if (pl != NULL) {
	for (int i = 0; i < players.size(); i++) {
	  if (pl == players[i]) return true;
	}
  }
  return false;
}

void(*old_becameinvisible)(void*);
void becameinvisible(void*a){
}
void(*old_becamevisible)(void*);
void becamevisible(void*a){
	old_becamevisible(a);
}


bool IsPlayerVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHead           = !Linecast228(CameraPos,GetPlayerHead          (player),16384);
		bool CanSeeHip            = !Linecast228(CameraPos,GetPlayerHip           (player),16384);
		bool CanSeeLeftLowerArm   = !Linecast228(CameraPos,GetPlayerleftLowerArm  (player),16384);
		bool CanSeeRightLowerArm  = !Linecast228(CameraPos,GetPlayerrightLowerArm (player),16384);
		bool CanSeeLeftLowerLeg   = !Linecast228(CameraPos,GetPlayerleftLowerLeg  (player),16384);
		bool CanSeeRightLowerLeg  = !Linecast228(CameraPos,GetPlayerrightLowerLeg (player),16384);

		return
		CanSeeHead            ||
		CanSeeHip             ||
		CanSeeLeftLowerArm    ||
		CanSeeRightLowerArm   ||
		CanSeeLeftLowerLeg    ||
		CanSeeRightLowerLeg    ;
	}
	return false;
}

bool IsHeadVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHead           = !Linecast228(CameraPos,GetPlayerHead          (player),16384);

		return
		CanSeeHead;            
	}
	return false;
}

bool IsNeckVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeNeck           = !Linecast228(CameraPos,GetPlayerNeck          (player),16384);

		return
		CanSeeNeck;            
	}
	return false;
}

bool IsHipVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerHip          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsLeftUpperArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerleftUpperArm          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsLeftForeArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerleftLowerArm          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsLeftArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerLeftHand          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsRightUpperArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerrightUpperArm          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsRightForeArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerrightLowerArm          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsRightArmVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerRightHand          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsLeftCalfLegVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerleftUpperLeg          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsLeftFootLegVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerleftLowerLeg          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsRightCalfLegVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerrightUpperLeg          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}

bool IsRightFootLegVisible(void* player) {
	if (get_camera()) {
		Vector3 CameraPos         = get_position(get_transform(get_camera()));

		bool CanSeeHip           = !Linecast228(CameraPos,GetPlayerrightLowerLeg          (player),16384);

		return
		CanSeeHip;            
	}
	return false;
}



// hooks

void (*old_Player_Update)(void *player);  
void Player_Update(void *player) {  
	if (player) { 

		if (espen) {
			if (GetPlayerHealth(get_photon(player)) > 0) {
				if (!playerFind(player)) players.push_back(player);
					clearPlayers();
			}
		}

		if(IsLocal(player)) { 
			me = player; 
		} 

		if(me) { 

			if(GetPlayerHealth(get_photon(me)) > 0){
				monoString *nick;
				nick = GetNickName(get_photon(me));
				namestring = nick->toCPPString();  
			}
		 
			if (GetPlayerTeam(me) == GetPlayerTeam(player) && !IsLocal(player)) { 
				team = player; 
			} 
	 
			if(GetPlayerTeam(me) != GetPlayerTeam(player)) { 
				enemy = player; 
			} 

		}
	}  
  old_Player_Update(player);  
} 



// импорт еспшок
#import "Esp.h"
