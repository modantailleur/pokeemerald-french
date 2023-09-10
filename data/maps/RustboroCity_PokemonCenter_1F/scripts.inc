.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon POKéMON a une nature NAIVE, et\n"
	.string "celui de mon ami a une nature\p"
	.string "JOLLY. C'est fascinant à quel point\n"
	.string "les POKéMON ont des personnalités\p"
	.string "!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Tout comme les humains, il existe\n"
	.string "des POKéMON mâles et femelles. Mais\p"
	.string "personne ne semble avoir la moindre\n"
	.string "idée en quoi ils sont différents.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L'homme d'à côté m'a donné un HM !\n"
	.string "Je l'ai utilisé pour apprendre à\p"
	.string "mon POKéMON comment couper des\n"
	.string "arbres maigres.$"
