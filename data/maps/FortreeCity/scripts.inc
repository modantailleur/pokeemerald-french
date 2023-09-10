FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Personne ne me croit, mais j'ai vu\n"
	.string "ce gigantesque POKéMON dans le\p"
	.string "ciel. Il a semblé se tortiller\n"
	.string "alors qu'il volait vers la ROUTE\p"
	.string "131. Au fait… Renifle… Euh… Tu,\n"
	.string "euh… odeur de brûlé. Étiez-vous sur\p"
	.string "un volcan ou quelque chose comme ça\n"
	.string "?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Je veux aller au POKéMON GYM, mais\n"
	.string "quelque chose bloque le passage.\p"
	.string "Après tout ce tracas, j'ai suivi\n"
	.string "une formation sur la ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "J'ai mon POKéMON de fierté et de\n"
	.string "joie avec moi. Cette fois, je vais\p"
	.string "battre ALIZÉE.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Le sol absorbe l'eau de pluie et\n"
	.string "les arbres poussent en buvant cette\p"
	.string "eau… Notre CIMETRONELLEE existe\n"
	.string "parce qu'il y a à la fois de l'eau\p"
	.string "et de la terre.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La VILLE est constituée de maisons\n"
	.string "construites sur des arbres. C’est\p"
	.string "peut-être grâce à ce mode de vie\n"
	.string "que tout le monde est en bonne\p"
	.string "santé et vivant. Eh bien, même\n"
	.string "moi-même, j’ai l’impression d’avoir\p"
	.string "trente ans de moins."

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Vivre au sommet des arbres, c'est\n"
	.string "bien. Mais parfois, BUG POKéMON\p"
	.string "entre par les fenêtres. Cela peut\n"
	.string "être vraiment surprenant.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Il y a des POKéMON qui évoluent\n"
	.string "lorsque vous les échangez ! C'est\p"
	.string "ce que j'ai entendu.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Quelque chose d'invisible gêne.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Quelque chose d’invisible gêne.\n"
	.string "Vous souhaitez utiliser le DEVON\p"
	.string "SCOPE ?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} a utilisé le DEVON SCOPE. Un\n"
	.string "POKéMON invisible est devenu\p"
	.string "complètement visible ! Le POKéMON\n"
	.string "surpris s'est enfui !$"

FortreeCity_Text_CitySign:
	.string "CIMETRONELLE “ La ville au sommet\n"
	.string "des arbres qui s'amuse avec la\p"
	.string "nature. ”$"

FortreeCity_Text_GymSign:
	.string "LEADER DU POKéMON GYM DE\n"
	.string "CIMETRONELLE : ALIZÉE “\p"
	.string "L'utilisateur d'oiseaux qui prend\n"
	.string "son envol vers le monde. ” $"
