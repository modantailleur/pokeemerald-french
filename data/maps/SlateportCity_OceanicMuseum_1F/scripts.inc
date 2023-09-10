.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bienvenue au MUSÉE OCÉANIQUE. Le\n"
	.string "prix d'entrée est de 50 ¥.\p"
	.string "Voulez-vous participer?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "S'il vous plaît, amusez-vous.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Je suis désolé, mais vous ne\n"
	.string "semblez pas avoir assez d'argent.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Vous faites partie du groupe\n"
	.string "qui est arrivé plus tôt ? Tu es le\p"
	.string "seul à être en retard. Tu ferais\n"
	.string "mieux d'aller les rattraper !$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nous, TEAM AQUA, existons pour le\n"
	.string "bien de tous !$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "On nous a dit de nous rassembler\n"
	.string "ici, alors nous l'avons fait, mais…\p"
	.string "Notre BOSS, la cheville ouvrière,\n"
	.string "n'est pas là.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Si je dévalisais ces trucs ici,\n"
	.string "est-ce que ça me rendrait riche ?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Ce que j'apprends ici, je peux\n"
	.string "l'utiliser pour des actes\p"
	.string "néfastes…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Si nos crétins n'avaient pas gâché\n"
	.string "les choses à RUSTBORO, nous ne\p"
	.string "serions pas là !$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Je n'avais pas 50 ¥, donc il a\n"
	.string "fallu beaucoup de temps pour\p"
	.string "joindre la réceptionniste.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Je veux en apprendre davantage sur\n"
	.string "la mer et utiliser ces\p"
	.string "connaissances pour combattre.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Je suis toute étourdie et gluante\n"
	.string "quand je vois la mer ! Pour moi,\p"
	.string "CAPTAIN POUPE est le modèle numéro\n"
	.string "un !$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "La mer est vaste sans fin et\n"
	.string "infiniment profonde… Il doit y\p"
	.string "avoir de nombreux POKéMON que nous\n"
	.string "ignorons.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Je veux un POKéMON marin. Je pense\n"
	.string "que ce serait cool et agréable de\p"
	.string "faire un câlin.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh ! Que faites-vous ici? Moi?\n"
	.string "Je suis le membre de la TEAM AQUA\p"
	.string "que tu as cogné auparavant, tu te\n"
	.string "souviens ? De retour au TUNNEL\p"
	.string "MERAZON ? Tiens prends ça! Tu dois\n"
	.string "me pardonner !$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Cette MT, elle te convient plus\n"
	.string "qu'à moi. J'espère ne plus jamais\p"
	.string "te revoir ! Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Awww, allez ! Tu dois prendre ça et\n"
	.string "me laisser partir !$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un fluide bleu tourbillonne à\n"
	.string "l’intérieur d’un récipient en\p"
	.string "verre. “Il s'agit d'une expérience\n"
	.string "visant à créer artificiellement un\p"
	.string "WHIRLPOOL en utilisant le vent.“$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Une boule rouge monte et descend à\n"
	.string "l’intérieur d’un récipient en\p"
	.string "verre. “Il s'agit d'une expérience\n"
	.string "simulant une CASCADE en utilisant\p"
	.string "la flottabilité de la balle.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "C'est un échantillon de sol\n"
	.string "provenant du fond de l'océan. “ Au\p"
	.string "fil des années, les restes de\n"
	.string "formes de vie se déposent au fond\p"
	.string "de la mer, formant des couches\n"
	.string "sédimentaires. “ En analysant ces\p"
	.string "couches, le passé ancien est\n"
	.string "révélé. ”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "C'est un échantillon de sable de\n"
	.string "plage. “ Les pierres des montagnes\p"
	.string "sont emportées par les rivières où\n"
	.string "elles sont concassées et broyées. “\p"
	.string "Ils sont réduits en grains et\n"
	.string "finissent sous forme de sable sur\p"
	.string "les plages. ”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“ MINIFACT OCÉANIQUE 1 Pourquoi\n"
	.string "l'eau de mer est-elle bleue ? “ La\p"
	.string "lumière est composée de plusieurs\n"
	.string "couleurs. “ Lorsque la lumière\p"
	.string "traverse l’eau, la plupart des\n"
	.string "types de lumière perdent leur\p"
	.string "couleur. “Cependant, la lumière\n"
	.string "bleue conserve sa couleur, ce qui\p"
	.string "donne à la mer une apparence\n"
	.string "bleue.“$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“ OCEANIC MINIFACT 2 Pourquoi la\n"
	.string "mer est-elle salée ? “ L’eau de mer\p"
	.string "contient du sel dissous sous forme\n"
	.string "d’ions sodium et chlore. “ Ces ions\p"
	.string "s’échappent des roches et sont\n"
	.string "emportés vers la mer par la pluie.\p"
	.string "“ La concentration de sel dissous\n"
	.string "rend la mer salée. ”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“ OCEANIC MINIFACT 3 Quel est le\n"
	.string "plus gros ? La mer ou la terre ? “\p"
	.string "La mer couvre environ 70 % de la\n"
	.string "planète, le reste étant constitué\p"
	.string "de terres. “ La mer est donc plus\n"
	.string "de deux fois plus grande que la\p"
	.string "terre. ”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "C'est un fossile avec des crêtes\n"
	.string "ondulées. “ Le sol des fonds marins\p"
	.string "est érodé par la marée. “ L’eau de\n"
	.string "mer qui coule marque le sol de\p"
	.string "petites crêtes et de petites\n"
	.string "vallées. “Si ce sol se fossilise,\p"
	.string "on parle de marque d'ondulation.“$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Une étrange machine tourne sous une\n"
	.string "coupole de verre. C'est peut-être\p"
	.string "pour mesurer la profondeur de\n"
	.string "quelque chose…$"
