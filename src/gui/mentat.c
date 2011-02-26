/* $Id$ */

#include <stdio.h>
#include "types.h"
#include "libemu.h"
#include "../global.h"
#include "../house.h"
#include "../sprites.h"
#include "../tools.h"
#include "gui.h"
#include "mentat.h"
#include "../unknown/unknown.h"

extern void f__1DD7_022D_0015_1956();
extern void f__2B4C_0002_0029_64AF();
extern void f__B4E0_0000_000F_14AD();
extern void overlay(uint16 cs, uint8 force);

/**
 * Handle clicks on the Mentat widget.
 * @return True, always.
 */
bool GUI_Widget_Mentat_Click()
{
	g_global->cursorSpriteID = 0;

	emu_push(emu_get_memory16(0x2DCE, 0x00, 0x442)); emu_push(emu_get_memory16(0x2DCE, 0x00, 0x440)); /* g_sprites */
	emu_push(0);
	emu_push(0);
	emu_push(emu_cs); emu_push(0x0368); emu_cs = 0x2B4C; f__2B4C_0002_0029_64AF();
	emu_sp += 8;

	Unknown_B483_0363(0xFFFE);

	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0380); emu_cs = 0x1DD7; f__1DD7_022D_0015_1956();
	emu_sp += 4;

	Music_Play(g_houseInfo[g_global->playerHouseID].variable_18);

	Sprites_UnloadTiles();

	Sprites_Load(1, 7, g_sprites);

	emu_push(0);
	emu_push(emu_cs); emu_push(0x03BA); emu_cs = 0x34E9; overlay(0x34E9, 0); emu_Unknown_B4E9_0000();
	emu_sp += 2;

	emu_push(0);
	emu_push(emu_cs); emu_push(0x03C3); emu_cs = 0x34E0; overlay(0x34E0, 0); f__B4E0_0000_000F_14AD();
	emu_sp += 2;

	emu_push(1);
	emu_push(emu_cs); emu_push(0x03CC); emu_cs = 0x34E9; overlay(0x34E9, 0); emu_Unknown_B4E9_0000();
	emu_sp += 2;

	Driver_Sound_Play(1, 0xFF);

	Sprites_Load(0, 7, g_sprites);

	Sprites_LoadTiles();

	g_global->variable_38C4 = 1;

	GUI_DrawInterfaceAndRadar(0);

	Music_Play(Tools_RandomRange(0, 5) + 8);

	return true;
}
