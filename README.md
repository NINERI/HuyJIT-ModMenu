# ESP Non-JB imGui Standoff 2
Huy JIT Mod Menu is a template menu ESP for iOS STandoff 2 that supported patching offsets/hexes for Non-jailbreak with JIT and fix patch for Dopamine jailbreak using IMGUI, also working with other jailbreak!

В файлах я рассказал о всем самом важном, как хукать и патчить. Данный код подходит для устройств без джейлбрейка и для устройств с любым джейлбрейком. Что бы все заработало надо все прохукать и выесьтьи оффсеты, пример: IsLocal = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x18E576C"));

Суть сурса в том что бы вы поняли, что такое кодинг на IOS для Standoff 2 и других юнити игр. Что бы отключить анти-чит вам надо ретнуть все его оффсеты из дампа, оффсеты для байпасса(не всего) 0.26.0: offset - 0x1CDA448, 0x1CDA350, 0x1CD7B68, 0x1CD7894; hex - 0xC0035FD6

Код ESP находится в файле ESP.h


# About
- I'm using vm_writeData.h to patch the offsets/hexes
- Kopycat some code from [joeyjurjens](https://github.com/joeyjurjens/iOS-Mod-Menu-Template-for-Theos)
- Also bring encryption from joeyjurjens template too
- Hook by DobbyHook
- Fan boi of 五等分の花嫁

# Installation
- Using theos for compilation
- Add ```THEOS_PACKAGE_SCHEME = rootless``` to support Dopamine if you want 

# Feature
- On/Off switch for patching offsets
- Support Hooking (by DobbyHook)
- Added getRealOffset(), you can now use it to read the address data if you want to

# Usage
**3 fingers double tap to screen to open menu, 2 fingers double tap to disable menu**

Editing these in `ImGuiDrawView.mm`

- Patching offset on default binary `NULL`
```obj-c
vm(ENCRYPTOFFSET("0x10517A154"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
```

- Patching offset on `UnityFramework`
```obj-c
vm_unity(ENCRYPTOFFSET("0x517A154"), strtoul(ENCRYPTHEX("0x360080D2"), nullptr, 0));
```
You can change this to anything you want to patch on the line where I noted in `5Toubun/NakanoYotsuba.h`. Normally it's `UnityFramework` but some games like LoL WildRift is `FEProj`

- Hooking a static address (both `NULL` and `UnityFramework`)
```obj-c
void (*huy)(void *instance);
void _huy(void *instance){
    huy(instance);
}

DobbyHook((void *)(getRealOffset(ENCRYPTOFFSET("0x5F145F8"))), (void *)_huy, (void **)&huy);
```
- Font using for this menu is Honkai Star Rail font (**English only**)

### Pull request button is on the top, you can contribute to this project if you want

# Credits
- Huy Nguyen [34306](https://github.com/34306)
- NINERI (it's me) - (https://github.com/NINERI/)
- [x2nios](https://github.com/x2niosvn) for [IMGUI Mod Menu](https://github.com/x2niosvn/iOS-IMGUI-Mod-Menu-Templates)
- [joeyjurjens](https://github.com/joeyjurjens) for [iOS Mod Menu](https://github.com/joeyjurjens/iOS-Mod-Menu-Template-for-Theos)
- [Dobby](https://github.com/jmpews/Dobby) by [jmpews](https://github.com/jmpews) (Apache-2.0 license)
- Special thanks to: Red16, tuancc, YeetDisDude, [modfs] AloH, HappySecret and Lavochka (H5GG Discord)
