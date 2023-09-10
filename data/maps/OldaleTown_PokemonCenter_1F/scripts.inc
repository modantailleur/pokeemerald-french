.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Ce PC dans le coin est destiné à\n"
	.string "n'importe quel DRESSEUR DE POKéMON.\p"
	.string "Naturellement, cela signifie que\n"
	.string "vous pouvez également l'utiliser.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "LES CENTRES POKéMON sont géniaux !\n"
	.string "Vous pouvez utiliser leurs services\p"
	.string "autant que vous le souhaitez, et\n"
	.string "tout cela gratuitement. Vous n'avez\p"
	.string "jamais à vous inquiéter !$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Le POKéMON WIRELESS CLUB au\n"
	.string "deuxième étage a été construit\p"
	.string "récemment. Mais ils disent qu'ils\n"
	.string "font encore des ajustements.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Le POKéMON WIRELESS CLUB au\n"
	.string "deuxième étage a été construit\p"
	.string "récemment. J'ai échangé POKéMON\n"
	.string "tout de suite.$"
