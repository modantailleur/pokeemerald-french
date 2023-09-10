PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Je ne peux pas voir l'ILE MIRAGE\n"
	.string "aujourd'hui…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Oh mon! Je peux voir l'ILE\n"
	.string "MIRAGE aujourd'hui !$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "L'ILE MIRAGE… Elle doit devenir\n"
	.string "visible et invisible en fonction\p"
	.string "des conditions météorologiques qui\n"
	.string "font apparaître les mirages. Ou\p"
	.string "est-ce qu'il apparaît et disparaît\n"
	.string "vraiment ?$"
