.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Ce système de stockage POKéMON sur\n"
	.string "PC… Celui qui l'a créé doit être\p"
	.string "une sorte de sorcier scientifique\n"
	.string "!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Quand mon POKéMON a mangé une BAIE\n"
	.string "D'ORAN, il a récupéré des PV !$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Il existe de nombreux types de\n"
	.string "POKéMON. Tous les types ont leurs\p"
	.string "forces et leurs faiblesses par\n"
	.string "rapport aux autres types. Selon les\p"
	.string "types de POKéMON, une bataille peut\n"
	.string "être facile ou difficile.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Par exemple, votre TREECKO est de\n"
	.string "type GRASS. Il est fort contre les\p"
	.string "types EAU et SOL. Mais il est\n"
	.string "faible contre les POKéMON de type\p"
	.string "FEU.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Par exemple, votre TORCHIC est de\n"
	.string "type FEU. Il est puissant contre\p"
	.string "les types GRASS et BUG. Mais il est\n"
	.string "faible contre les POKéMON de type\p"
	.string "EAU.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Par exemple, votre MUDKIP est de\n"
	.string "type EAU. C'est fort contre le type\p"
	.string "FIRE. Mais il est faible contre les\n"
	.string "POKéMON de type HERBE et\p"
	.string "ÉLECTRIQUE.$"
