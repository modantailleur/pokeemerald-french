.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Vous voulez une astuce pour vous\n"
	.string "battre ? Je dirais que cela élève\p"
	.string "différents types de POKéMON de\n"
	.string "manière équilibrée. Il ne sert à\p"
	.string "rien de rendre fort un seul\n"
	.string "POKéMON. S'il a un désavantage de\p"
	.string "type, il n'aura peut-être aucune\n"
	.string "chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "J'échange POKéMON avec mes amis. Si\n"
	.string "un POKéMON échangé détient un\p"
	.string "objet, cela me rend deux fois plus\n"
	.string "heureux !$"
