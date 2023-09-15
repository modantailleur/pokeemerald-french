.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Veuillez trouver un partenaire\n"
	.string "parmi les DRESSEURS réunis\p"
	.string "ici.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, vous n'avez pas trouvé de\n"
	.string "partenaire pour votre équipe.\p"
	.string "Aimeriez-vous arrêter de chercher\n"
	.string "et retourner à la réception?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Alors, veuillez trouver un\n"
	.string "partenaire parmi les\p"
	.string "DRESSEURS réunis ici.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Merci d'avoir choisi un partenaire.\n"
	.string "Je vais maintenant vous montrer\p"
	.string "votre MULTI BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Je suis le numéro de {STR_VAR_1}. {STR_VAR_2}\n"
	.string "apprenti. Vous pouvez m'appeler\p"
	.string "{STR_VAR_3} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Sur les conseils de {STR_VAR_1}, j'ai\n"
	.string "apporté un {STR_VAR_3} avec {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. S'il vous\n"
	.string "plaît, laissez-moi vous rejoindre\p"
	.string "en équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Merci! Je vais m'inscrire tout de\n"
	.string "suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Je voulais vraiment former une\n"
	.string "équipe avec toi, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Je suis le numéro de {STR_VAR_1}. {STR_VAR_2}\n"
	.string "apprenti. Je m'appelle {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "J'ai reçu des conseils de {STR_VAR_1} et\n"
	.string "j'en ai choisi un {STR_VAR_3} avec\p"
	.string "{STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. S'il vous\n"
	.string "plaît, formons une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Merci beaucoup! J'en aurai\n"
	.string "rapidement fini avec l'inscription\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, j'espérais pouvoir\n"
	.string "m'associer avec vous…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Euh, je m'appelle {STR_VAR_3} et je suis\n"
	.string "le numéro de {STR_VAR_1}. {STR_VAR_2}\p"
	.string "apprenti. Snivel… je suis désolé!\n"
	.string "Cette tension me fait pleurer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} m'a conseillé, j'en ai donc\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Snivel… S'il\n"
	.string "vous plaît, faites équipe avec moi\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh vraiment? Vous serez? Génial!\n"
	.string "Méchant! Awoooh ! Oh… je suis\p"
	.string "désolé… je suis trop contente, je\n"
	.string "pleure… je vais m'inscrire tout de\p"
	.string "suite. S'il vous plaît, ne partez\n"
	.string "pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, mais… Sanglot… Waaaaah !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Salut! Je m'appelle {STR_VAR_3} ! Je\n"
	.string "suis le numéro de {STR_VAR_1}. {STR_VAR_2}\p"
	.string "apprenti !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} a recommandé mon équipe. Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}, c'est ce que\n"
	.string "j'ai ! Cool hein? Alors venez!\p"
	.string "Formons une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay! Super! D'accord, je vais\n"
	.string "m'inscrire, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Ohh pourquoi? Je voulais faire\n"
	.string "équipe, {PLAYER} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Je m'appelle {STR_VAR_3}, le numéro.\n"
	.string "{STR_VAR_2} apprenti du célèbre {STR_VAR_1}\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "J'ai demandé conseil à {STR_VAR_3}. Un\n"
	.string "{STR_VAR_1} -- utilisant {STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}, c'est ma\n"
	.string "paire. S'il vous plaît, voulez-vous\p"
	.string "me rejoindre dans une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Merci! Je m'inscris tout de suite\n"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, j'espérais vous rejoindre\n"
	.string "dans une équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Euh… je suis sincèrement heureux\n"
	.string "que tu prennes le temps de me\p"
	.string "parler. Je m'appelle {STR_VAR_3}. Je\n"
	.string "suis le numéro de {STR_VAR_1}. {STR_VAR_2}\p"
	.string "apprenti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} m'a donné des conseils. J'en\n"
	.string "suis très reconnaissant. J'ai une\p"
	.string "équipe composée d'un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Je sais que\n"
	.string "j'en demande beaucoup… Je ne pense\p"
	.string "pas que vous serez disposé à le\n"
	.string "faire, mais puis-je vous rejoindre\p"
	.string "en tant que partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Vraiment? Je n'arrive pas à y\n"
	.string "croire ! Je ne peux pas croire que\p"
	.string "tu me laisses te rejoindre ! Je… je\n"
	.string "ne te laisserai pas tomber ! Euh…\p"
	.string "Si ça va vraiment, je vais\n"
	.string "m'inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh… je ne pensais pas que j'étais\n"
	.string "assez bon…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Bonjour, je m'appelle {STR_VAR_3}. Je\n"
	.string "suis le numéro de {STR_VAR_1}. {STR_VAR_2}\p"
	.string "apprenti !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} m'a dit que ce serait bien\n"
	.string "de faire cette équipe : un\p"
	.string "{STR_VAR_1}-en utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "et un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. Pas mal, hein ? Tu veux que\p"
	.string "je fasse équipe avec toi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D'accord, je suis ravi de vous\n"
	.string "rejoindre ! J'espère que vous ne\p"
	.string "gâcherez pas les choses pour moi !\n"
	.string "Je vais faire mon inscription\p"
	.string "maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hein? Pourquoi m'as-tu refusé ?\n"
	.string "Vous n'êtes pas un juge de\p"
	.string "caractère !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Je m'appelle {STR_VAR_3} et je suis un\n"
	.string "TRIATHLÈTE. Je suis occupé tous les\p"
	.string "jours avec du jogging, de\n"
	.string "l'entraînement et du rap. Il se\p"
	.string "trouve que je suis aussi le numéro\n"
	.string "1 de {STR_VAR_1}. {STR_VAR_2} apprenti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "C'est ce que {STR_VAR_3} a recommandé.\n"
	.string "Un {STR_VAR_1} -- utilisant {STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2}. Je\n"
	.string "fais beaucoup d'efforts pour les\p"
	.string "élever, même si je suis occupé.\n"
	.string "Formons une équipe et essayons !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Merci, c'est l'esprit ! Attendez\n"
	.string "bien pendant que je vais\p"
	.string "m'inscrire, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "J'ai pris du temps malgré mon\n"
	.string "emploi du temps chargé pour être\p"
	.string "ici ! Donnez-moi une pause !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Salut! Comment ça va? Je m'appelle\n"
	.string "{STR_VAR_3}, le numéro de {STR_VAR_1}. {STR_VAR_2}\p"
	.string "apprenti. Heureux de vous\n"
	.string "rencontrer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Écoute, écoute ! Vous devez\n"
	.string "entendre parler du POKéMON {STR_VAR_3}\p"
	.string "recommandé. Un {STR_VAR_2} avec {STR_VAR_1}\n"
	.string "et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Bien sûr, je\n"
	.string "les ai superbement élevés ! Alors,\p"
	.string "envie de faire équipe ? Je suis sûr\n"
	.string "que ce sera un excellent combo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Ouais, je pense que ce sera amusant\n"
	.string "! Je vais m'inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, tu es méchant ! Je suis\n"
	.string "recommandé, tu sais.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "S'il vous plaît, laissez moi\n"
	.string "m'introduire. Je m'appelle {STR_VAR_3}.\p"
	.string "Je suis le numéro de {STR_VAR_1}. {STR_VAR_2}\n"
	.string "apprenti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "J'ai demandé les conseils avisés de\n"
	.string "{STR_VAR_3} et j'ai constitué mon équipe\p"
	.string "d'un {STR_VAR_2} avec {STR_VAR_1} $."

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}. S'il vous\n"
	.string "plaît, acceptez de former une\p"
	.string "équipe avec moi !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… je suis ravie ! Je promets de\n"
	.string "vous donner le meilleur de moi-même\p"
	.string "! Bien sûr, je vais nous inscrire !\n"
	.string "Veuillez patienter !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "J'espérais vous rejoindre, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! Tu m'as parlé ! Je… je suis\n"
	.string "ravi ! Je m'appelle {STR_VAR_3} ! Je\p"
	.string "suis le numéro de {STR_VAR_1}. {STR_VAR_2}\n"
	.string "apprenti !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Sur les conseils de {STR_VAR_3}, j'ai\n"
	.string "entraîné un {STR_VAR_1} en utilisant\p"
	.string "{STR_VAR_2} $."

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2}. S'il\n"
	.string "vous plaît, pouvez-vous m'accorder\p"
	.string "mon souhait ? Je veux être ton\n"
	.string "partenaire dans l'équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! Je… j'ai le vertige ! Merci\n"
	.string "beaucoup! Je vais nous inscrire\p"
	.string "tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah ! Vous n'éprouvez aucune\n"
	.string "pitié ? Mais ça te rend plus cool…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Ouais! Je suis le numéro de {STR_VAR_1}.\n"
	.string "{STR_VAR_2} apprenti ! {STR_VAR_3} est mon\p"
	.string "nom, bonjour, bonjour !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mon mentor {STR_VAR_3} m'a recommandé un\n"
	.string "{STR_VAR_1}-maître {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "et un {STR_VAR_1}-maître {STR_VAR_2}. C'est\n"
	.string "une bonne chose, hein ? Vous ferez\p"
	.string "équipe avec moi, n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "D'accord, excellent ! Je vais faire\n"
	.string "l'inscription rapidement!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Waaaah ! Vous êtes un calculateur,\n"
	.string "{PLAYER} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hé! Il y a un gros problème ! C'est\n"
	.string "le dernier jour de la BATTLE TOWER\p"
	.string "! … … … … … … Je rigole, c'est\n"
	.string "tout! Les gens m'appellent {STR_VAR_3}\p"
	.string "et moi aussi ! Je suis le 1 000ème\n"
	.string "apprenti de {STR_VAR_1} ! En fait, je\p"
	.string "suis non. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} m'a donné quelques conseils.\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} avec {STR_VAR_1}. J'en ai dix de\n"
	.string "chaque sorte ! En fait, juste un de\p"
	.string "chaque ! Et ça ? Voulez-vous\n"
	.string "essayer des combats de tags avec\p"
	.string "moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Hourra! Je vais vous offrir un\n"
	.string "POKéMON en guise de remerciement !\p"
	.string "Je rigole! Mais je vais vraiment\n"
	.string "aller faire l'inscription, d'accord\p"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, c'est si froid ! Je vais devoir\n"
	.string "détruire la BATTLE TOWER pour ça !\p"
	.string "Bien sûr que je ne le ferai pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hé, là, je suis en train de rocker\n"
	.string "et de rouler ! POKéMON, je contrôle\p"
	.string "! Je suis {STR_VAR_3} le SAILOR rappeur.\n"
	.string "Ne me confondez pas avec un\p"
	.string "gémissement ! Je suis le numéro de\n"
	.string "{STR_VAR_1}. {STR_VAR_2} apprenti. Moi, tu ne\p"
	.string "devrais pas être prompt à me\n"
	.string "rejeter !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Avec les conseils de {STR_VAR_3}, j'ai\n"
	.string "respecté et constitué mon équipe de\p"
	.string "fierté ! Un {STR_VAR_1} -- utilisant\n"
	.string "{STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2} !\n"
	.string "Nous devrions commémorer notre\p"
	.string "rencontre, avec une victoire par\n"
	.string "équipe à célébrer !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hé, hé, j'aime ton style ! Notre\n"
	.string "inscription, j'irai déposer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hé, {PLAYER}, maintenant c'est\n"
	.string "froid ! Si je peux être si\p"
	.string "audacieux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Youpi-yahoo ! Oh, ne cours pas ! Je\n"
	.string "m'amusais juste ! Salut! Je\p"
	.string "m'appelle {STR_VAR_3} ! Je suis le\n"
	.string "numéro de {STR_VAR_1}. {STR_VAR_2} apprenti\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} m'a dit quoi faire. Donc un\n"
	.string "{STR_VAR_1} utilisant {STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2}, j'ai\n"
	.string "choisi. Alors, que dis-tu? Allez,\p"
	.string "fais ma journée ! S'il vous plaît,\n"
	.string "je vous en supplie ! Laisse-moi te\p"
	.string "rejoindre, ne me laisse pas bleu !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Ouais ! La chance est avec moi !\n"
	.string "C'est sûr que ça me fait plaisir !\p"
	.string "Avant de rejoindre la mêlée, je\n"
	.string "vais m'inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Tu me refuses ? {PLAYER}, tu me fais\n"
	.string "froncer les sourcils !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Toux! Oh, désolé, j'ai un rhume.\n"
	.string "Mais mes POKéMON vont bien. Je\p"
	.string "m'appelle {STR_VAR_3}, le numéro de\n"
	.string "{STR_VAR_1}. {STR_VAR_2} apprenti. Toux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "J'ai pris à cœur les conseils de\n"
	.string "{STR_VAR_3} et j'ai constitué mon équipe\p"
	.string "d'un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Je les ai\n"
	.string "entraînés tous les jours, même sous\p"
	.string "le vent et la pluie. C'est pour ça\n"
	.string "que j'ai ce rhume, je pense. C'est\p"
	.string "ce que je veux dire. Vous voulez\n"
	.string "être mon partenaire de tag ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Merci, j'apprécie ça! Tousse\n"
	.string "tousse! Attendez pendant que je\p"
	.string "vais m'inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, tu ne le feras pas ? {PLAYER}, je\n"
	.string "pense que nous ferions une bonne\p"
	.string "paire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh salut! C’est angoissant. Je\n"
	.string "m'appelle {STR_VAR_3}. Je suis le non.\p"
	.string "{STR_VAR_2} apprenti de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} a déclaré que cette équipe\n"
	.string "serait bonne : un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Je me sens\n"
	.string "gêné à ce sujet, mais me\p"
	.string "laisserez-vous vous rejoindre ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, bon sang, merci ! Je me sens\n"
	.string "timide, mais je ferai de mon mieux\p"
	.string "! Je vais faire l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, s'il te plaît, ne dis pas non !\n"
	.string "Je me sens déjà assez gêné…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Je m'appelle {STR_VAR_3}, et ce n'est\n"
	.string "pas un mensonge. Je suis le numéro\p"
	.string "de {STR_VAR_1}. {STR_VAR_2} apprenti.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} a recommandé mon équipe.\n"
	.string "Puisque le conseil semblait\p"
	.string "sincère, j'ai décidé d'apporter\n"
	.string "avec moi mon {STR_VAR_1} - en utilisant\p"
	.string "{STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "mon {STR_VAR_1}-en utilisant {STR_VAR_2}. Si\n"
	.string "possible, j'aimerais que vous\p"
	.string "m'acceptiez comme partenaire de\n"
	.string "votre équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Tu m'accepteras vraiment ?\n"
	.string "Autrement, ce serait trop terrible.\p"
	.string "Mais puisque vous avez accepté, ça\n"
	.string "va. Je vais aller nous enregistrer\p"
	.string "tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hein ? Maintenant, pourquoi\n"
	.string "refuserais-tu ? Est-ce votre idée\p"
	.string "d'une blague ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Je m'appelle {STR_VAR_1} et je suis un\n"
	.string "LASS !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Ce que j'ai, c'est un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et un $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}. C'est ce\n"
	.string "que j'ai avec moi. Seras-tu mon\p"
	.string "partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Merci! Je vais faire\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Tu ne veux pas être mon partenaire\n"
	.string "? Vous le regretterez plus tard !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Bonjour! Je suis JEUNE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Vous voulez savoir ce que j'ai ? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Tu seras\n"
	.string "mon partenaire dans l'équipe,\p"
	.string "n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay! Je vais m'inscrire, d'accord\n"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Waouh ! Si vous formiez une équipe\n"
	.string "avec mon POKéMON, nous serions\p"
	.string "imparables !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo! Je suis RANDONNEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tu sais ce que j'ai avec moi ? Mon\n"
	.string "{STR_VAR_1}-utilise {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "mon {STR_VAR_1}-utilise {STR_VAR_2} ! Ça a\n"
	.string "l'air bien, hein ? Vous voulez\p"
	.string "former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo! Je vais m'inscrire alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "J'aurais aimé me battre avec toi à\n"
	.string "mes côtés.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Bonjour! Je m'appelle {STR_VAR_1} et je\n"
	.string "suis une BEAUTÉ !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Savez-vous ce que j'ai soulevé ? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Qu'en\n"
	.string "penses-tu? Vous voulez former une\p"
	.string "équipe ensemble ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Merveilleux! Je vais faire\n"
	.string "l'inscription maintenant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Quel dommage! Nous deux ensemble,\n"
	.string "nous aurions été les meilleurs !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo! Tu sais qui je suis? Je suis\n"
	.string "{STR_VAR_1} le PÊCHEUR !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "J'ai avec moi une équipe composée\n"
	.string "d'un {STR_VAR_1} utilisant {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_1}-en utilisant {STR_VAR_2}.\n"
	.string "Alors, qu’en est-il ? Allez-vous\p"
	.string "combattre à mes côtés ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bien bien! Laissez-moi faire ! Je\n"
	.string "vais nous inscrire maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Nous aussi, nous nous entendions\n"
	.string "parfaitement…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Heureux de faire votre\n"
	.string "connaissance. Je suis {STR_VAR_1}, une\p"
	.string "DAME.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Je suis accompagné d'une équipe\n"
	.string "d'un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. J'espère que\n"
	.string "j'obtiendrai votre approbation. Car\p"
	.string "je souhaite t'avoir comme\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Je vous remercie sincèrement. Je\n"
	.string "m'occuperai de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Je suis sûr que vous regretterez de\n"
	.string "ne pas m'avoir comme partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Je suis TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Ce que j'ai… Un {STR_VAR_2} avec {STR_VAR_1}\n"
	.string "et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! C'est ma\n"
	.string "paire ! S'il te plaît? Veux-tu\p"
	.string "former une équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Hé Merci! Je vais m'inscrire au\n"
	.string "comptoir.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Nous deux ensemble, nous aurions\n"
	.string "été durs, c'est sûr !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Salut ! Je suis BUG CATCHER {STR_VAR_1}\n"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Découvrez ce que j'ai! Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Alors\n"
	.string "écoute! Voulez-vous former une\p"
	.string "équipe de tag ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Je t'ai eu! Je vais faire les\n"
	.string "démarches d'inscription au\p"
	.string "comptoir.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, mes POKéMON sont géniaux.\n"
	.string "J'espère que vous ne le regretterez\p"
	.string "pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bonne journée! Dans SCHOOL KID\n"
	.string "{STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Ce que j'ai soulevé, c'est un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "Pas trop mal, tu ne trouves pas ?\p"
	.string "Voudriez-vous former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Merci beaucoup! Je vais terminer\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "C'est dommage… J'espérais pouvoir\n"
	.string "apprendre de toi en tant que\p"
	.string "partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Laissez-moi vous dire qui je\n"
	.string "suis ! Je suis RICHE GARÇON {STR_VAR_1}\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Devinez ce que j'ai eu ! Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Je suis\n"
	.string "prêt à vous offrir la chance de\p"
	.string "faire partie d'une équipe avec\n"
	.string "moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Un geste intelligent ! Je vais vite\n"
	.string "terminer le processus d'inscription\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Vous me refuseriez, plus que tout\n"
	.string "le monde ? Vous regretterez\p"
	.string "certainement cette décision !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Salut ! Je suis CEINTURE NOIRE\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "En tant que compagnons, j'en ai un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1} $."

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}. S'il\n"
	.string "vous plaît, exaucez-moi mon souhait\p"
	.string "! Permettez-moi d'être votre\n"
	.string "partenaire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Salut ! Je vais m'inscrire tout de\n"
	.string "suite!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Je vois… J'espère avoir une\n"
	.string "opportunité la prochaine fois que\p"
	.string "nous nous rencontrerons…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Salut! Je m'appelle {STR_VAR_1} et je\n"
	.string "suis un TUBER !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Je vais vous dire ce que j'ai. Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Puis-je\n"
	.string "s'il vous plaît faire partie de\p"
	.string "votre équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Merci! Je vais nous inscrire\n"
	.string "maintenant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Si nous étions devenus partenaires,\n"
	.string "nous aurions pu être si forts !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salutations… Je suis HEX MANIAC\n"
	.string "{STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "J'en porte avec moi un {STR_VAR_1}, en\n"
	.string "utilisant {STR_VAR_2} avec un $."

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-en utilisant {STR_VAR_2}… Je vous\n"
	.string "en supplie… Rejoignez-moi dans une\p"
	.string "équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Je vous remercie… je vais nous\n"
	.string "inscrire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "J'avais tellement envie de te\n"
	.string "rejoindre…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Comment vas-tu? Je m'appelle {STR_VAR_1}\n"
	.string "et je suis un ÉLEVEUR DE POKéMON !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "J'en élève quelques bons ! Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Et ça ?\n"
	.string "Envie de faire une équipe avec moi\p"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Merci de bien vouloir! Je vais\n"
	.string "m'occuper des inscriptions, alors\p"
	.string "attendez ici !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "J'avais hâte d'être votre\n"
	.string "partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Eh bien, bonjour ! Je suis\n"
	.string "TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Vous voulez savoir avec quoi je\n"
	.string "cours ? Un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Bien? Tu\n"
	.string "veux faire partie d'une équipe avec\p"
	.string "moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Bon déroulement! Je vais faire vite\n"
	.string "et terminer l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Toi et moi, nous aurions été les\n"
	.string "meilleurs. C'est dommage…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Salut! Je m'appelle {STR_VAR_1} ! Je\n"
	.string "suis un TRIATHLÈTE !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Je fais des courses avec mon équipe\n"
	.string "durable : un {STR_VAR_2} avec {STR_VAR_1} et\p"
	.string "$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Pas trop\n"
	.string "mal, hein ? Nous devrions former\p"
	.string "une équipe ensemble !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "D'accord! Je vais m'inscrire en un\n"
	.string "éclair !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Je voulais vraiment me battre en\n"
	.string "tant que partenaire de votre\p"
	.string "équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Je suis BATTLE GIRL {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "J'en ai renforcé un {STR_VAR_1}, en\n"
	.string "utilisant {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_1}-en utilisant {STR_VAR_2} !\n"
	.string "Aimez-vous cette combinaison? Et si\p"
	.string "toi et moi nous rejoignions ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Pourquoi merci! Je vais faire\n"
	.string "l'inscription maintenant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Avec toi, je pensais qu'on pourrait\n"
	.string "former l'équipe ultime…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Je suis TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "J'ai couru avec un {STR_VAR_2} qui sait\n"
	.string "utiliser {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1} ! Nous\n"
	.string "pourrions être dans une équipe. Ne\p"
	.string "serait-ce pas génial ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Merci! Je vais nous inscrire, et\n"
	.string "c'est tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, c'est dommage. Nous aurions\n"
	.string "été l’équipe la plus coriace du\p"
	.string "moment !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Moi? Je m'appelle TUBER {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Qu'est-ce que j'ai avec moi ? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Hé? Vous\n"
	.string "ferez équipe avec moi, n'est-ce pas\p"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D'accord! Je vais m'inscrire !\n"
	.string "Soyons excellents ensemble !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mes POKéMON sont coriaces, c'est\n"
	.string "sûr… C'est dommage que tu ne\p"
	.string "veuilles pas faire équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Ouais-hé ! Appelez-moi GUITARISTE\n"
	.string "{STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Découvrez mon entourage ! Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Ouais-hé !\n"
	.string "Plutôt sauvage, hein ? Il va\p"
	.string "falloir faire un duo en tag team !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Ouais-hé ! C'est parti ! Je vais\n"
	.string "faire ces trucs d'inscription\p"
	.string "maintenant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mon POKéMON est dur ! Vous allez le\n"
	.string "regretter, je vous le dis !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Heureux de vous rencontrer. Je suis\n"
	.string "{STR_VAR_1}, un GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Je suis accompagné de mon {STR_VAR_1} de\n"
	.string "confiance, utilisant {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_1}-en utilisant {STR_VAR_2}.\n"
	.string "Puis-je vous demander de vous\p"
	.string "joindre à moi dans le cadre d'un\n"
	.string "partenariat en équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, je vous remercie pour votre\n"
	.string "confiance. J'en aurai fini avec\p"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "C'est très regrettable… J'attendrai\n"
	.string "avec impatience la prochaine\p"
	.string "opportunité…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Bonjour, je m'appelle {STR_VAR_1} et je\n"
	.string "suis un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "J'ai maintenant avec moi un {STR_VAR_2}\n"
	.string "qui connaît le coup {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Aimez-vous\n"
	.string "ce que vous voyez? Pourquoi ne\p"
	.string "sois-tu pas mon partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Merci! Je m'occupe de l'inscription\n"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mes POKéMON sont de première\n"
	.string "qualité… C'est dommage que vous ne\p"
	.string "puissiez pas apprécier ça.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hum ! Je suis {STR_VAR_1} et je suis un\n"
	.string "EXPERT !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Les POKéMON que j'ai endurcis sont\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Que dis-tu\n"
	.string "d'une équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hum ! Je vais nous inscrire tout de\n"
	.string "suite ! Faisons tous les deux de\p"
	.string "notre mieux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "J'espère que votre choix est\n"
	.string "effectivement correct…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Bonjour bonjour. Je m'appelle\n"
	.string "{STR_VAR_1} et je suis un EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "J'ai bien élevé mon POKéMON. Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} : c'est ce\n"
	.string "que j'ai. N'aimerais-tu pas faire\p"
	.string "équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien bien. Je vais m'occuper de\n"
	.string "l'inscription tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Peut-être pourrons-nous former une\n"
	.string "équipe lors de notre prochaine\p"
	.string "rencontre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Je m'appelle DRAGON TAMER {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "L'équipe que j'ai renforcée est une\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Et ça ?\n"
	.string "Voulez-vous être mon partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "D'accord, je ferai de mon mieux !\n"
	.string "Je vais m'inscrire maintenant,\p"
	.string "d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Vous ne trouverez pas beaucoup de\n"
	.string "partenaires plus coriaces que moi\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Je suis BIRD KEEPER {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quel POKéMON ai-je ? Un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Ne penses-tu\n"
	.string "pas que nous ferions une équipe\p"
	.string "décente ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Grand merci! Je m'occupe de\n"
	.string "l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mon POKéMON et moi sommes forts.\n"
	.string "Quelle déception.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Je suis NINJA BOY {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mon équipe POKéMON est composée\n"
	.string "d'un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Faisons\n"
	.string "partie d'une équipe ensemble !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay! Laissez-moi m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Vous regretterez de ne pas avoir\n"
	.string "mon POKéMON coriace à vos côtés !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Bonjour! Je m'appelle PARASOL LADY\n"
	.string "{STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "M'accompagne maintenant mon {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}. Ne\n"
	.string "sont-ils pas gentils ? Envie de\p"
	.string "nous rejoindre dans une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Merci beaucoup ! Je vais m'inscrire\n"
	.string "au comptoir. Ne nous décevons pas\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mes POKéMON sont extrêmement forts.\n"
	.string "Comme c'est décevant…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Bonjour. Je m'appelle {STR_VAR_1} et je\n"
	.string "suis un BUG MANIAC !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "J'ai trouvé mon POKéMON, oui. Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} : c'est ce\n"
	.string "que j'ai trouvé. Puis-je vous\p"
	.string "intéresser à former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "D'accord! Compris! Je ne vais pas\n"
	.string "tarder à m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Avec le POKéMON que j'ai trouvé, on\n"
	.string "n'aurait pas perdu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ohé! Je m'appelle SAILOR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Laissez-moi vous montrer ma fierté\n"
	.string "et ma joie ! Un {STR_VAR_2} avec {STR_VAR_1}\p"
	.string "et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Bien sûr,\n"
	.string "tu ne vas pas me refuser. Nous\p"
	.string "ferons équipe, n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Je n'en attendais pas moins ! Je\n"
	.string "vais m'inscrire maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Nous aurions fait irruption dans\n"
	.string "l'opposition ! Dommage !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Bonjour, je m'appelle {STR_VAR_1}. Je\n"
	.string "suis un COLLECTIONNEUR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Les bijoux de ma collection sont\n"
	.string "mes {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Super, hein\n"
	.string "? Nous devrions former une équipe\p"
	.string "ensemble.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh ouais! Eh bien, ne perdons pas\n"
	.string "de temps. Je vais aller nous\p"
	.string "inscrire tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Eh bien, c'est bouleversant. Vous\n"
	.string "n'appréciez pas mon POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Bonjour, je m'appelle {STR_VAR_1}. Je\n"
	.string "suis un POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Me tenir compagnie est un {STR_VAR_1} -\n"
	.string "utilisant {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Ne\n"
	.string "penses-tu pas que nous formerions\p"
	.string "une équipe impressionnante ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "C'est super ! Je vais m'occuper de\n"
	.string "l'inscription maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La prochaine fois, choisis mon\n"
	.string "POKéMON, veux-tu ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Je m'appelle {STR_VAR_1}. Je suis un\n"
	.string "POKéMON RANGER !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Laissez-moi vous parler de mon\n"
	.string "équipe. J'en ai un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\n"
	.string "Aimeriez-vous former une équipe\p"
	.string "avec mon petit groupe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Nous serons à notre meilleur ! Je\n"
	.string "vais faire l'inscription rapidement\p"
	.string "!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "J'espère que vous choisirez mon\n"
	.string "POKéMON la prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Heureux de vous rencontrer. Je\n"
	.string "m'appelle {STR_VAR_1}. Je me considère\p"
	.string "comme une DAME AROMA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Je voyage avec un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "J'espère qu'ils vous plairont.\p"
	.string "Voudriez-vous être mon partenaire\n"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Je suis honoré de votre\n"
	.string "acceptation. Je vais m'inscrire\p"
	.string "tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Ce serait merveilleux si nous\n"
	.string "pouvions former une équipe la\p"
	.string "prochaine fois que nous nous\n"
	.string "rencontrerons.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Vous voulez savoir qui je suis ? Je\n"
	.string "m'appelle {STR_VAR_1}, le RUIN MANIAC !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Les POKéMON que j'ai avec moi sont\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Intriguant,\n"
	.string "hein ? Et si toi et moi nous\p"
	.string "associions ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "C'est une bonne décision ! Je vais\n"
	.string "faire les formalités\p"
	.string "d'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm… je pense que mes POKéMON sont\n"
	.string "coriaces…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Je suis COOLDRESSEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Les POKéMON que j'ai en ce moment\n"
	.string "sont un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Cool hein?\n"
	.string "Tu ne penses pas que ce serait\p"
	.string "plutôt cool si nous formions une\n"
	.string "équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool! Je vais faire l'inscription\n"
	.string "en un éclair!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Je pensais que nous formerions la\n"
	.string "meilleure équipe de tous les\p"
	.string "temps.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Je suis COOLDRESSEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L'équipe que j'ai formée compte un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Est-ce que\n"
	.string "ça vous semble bien ? Et si nous\p"
	.string "devenions partenaires du tag ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Ça a l’air OK ! Je ferais mieux de\n"
	.string "m'inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Je pensais à quel point nous\n"
	.string "serions une équipe coriace…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Hé! Je m'appelle {STR_VAR_1}, le\n"
	.string "POKéMANIAC !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Qu'est-ce qu'un gars comme moi a ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}, c'est quoi !\n"
	.string "Faisons-le! Nous allons marcher en\p"
	.string "équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Bon appel! Je vais nous inscrire\n"
	.string "tous les deux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Mes POKéMON sont brutaux ! Ce n'est\n"
	.string "pas ma faute si tu regrettes ça !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo, là ! Je m'appelle KINDLER\n"
	.string "{STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Vous savez ce que ma formation a\n"
	.string "concocté ? Un {STR_VAR_2} avec {STR_VAR_1} et\p"
	.string "$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Eh bien,\n"
	.string "qu'en dis-tu ? Vous voulez former\p"
	.string "une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "D'accord! Je vais continuer avec\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promets-moi que tu feras équipe\n"
	.string "avec moi la prochaine fois que nous\p"
	.string "nous rencontrerons.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Je m'appelle {STR_VAR_1} et je suis un\n"
	.string "CAMPER !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "J'ai collecté un {STR_VAR_1} -- en\n"
	.string "utilisant {STR_VAR_2} et un $."

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-en utilisant {STR_VAR_2}.\n"
	.string "Pensez-vous que ce serait amusant\p"
	.string "de faire équipe ? Je parie que ce\n"
	.string "serait le cas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Ouais! C'est parti, je m'inscris !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "La prochaine fois, d'accord ? Je\n"
	.string "veux faire partie de ton équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Bonjour! Je m'appelle {STR_VAR_1} et je\n"
	.string "suis un PICNICKER !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Les POKéMON que j'ai pris sont un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Êtes-vous\n"
	.string "intéressé à me rejoindre dans une\p"
	.string "équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Eh bien, merci ! Je vais faire\n"
	.string "l'inscription maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Ce serait bien si je pouvais vous\n"
	.string "rejoindre une autre fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Je suis PSYCHIQUE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Le duo que j'élève est un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Souhaitez-vous former une équipe\p"
	.string "avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Chose sûre! Je m'occupe de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Si nous nous reverrons, c'est à ce\n"
	.string "moment-là que j'aimerais faire\p"
	.string "équipe avec vous.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Je m'appelle {STR_VAR_1}. Je suis un\n"
	.string "PSYCHIQUE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} : ce sont mes\n"
	.string "disciples. L'idée de former un\p"
	.string "partenariat par équipe ne vous\n"
	.string "intrigue-t-elle pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Merci. Je vais m'occuper de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "J'espère qu'il y aura une autre\n"
	.string "chance de forger une alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Je m'appelle SCHOOL KID {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_1} -- utilisant {STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2} sont\n"
	.string "ma paire POKéMON. Puis-je s'il vous\p"
	.string "plaît être votre partenaire dans\n"
	.string "une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, merci ! Je m'inscris au\n"
	.string "comptoir tout de suite!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "S'il te plaît? Puis-je vous\n"
	.string "rejoindre la prochaine fois ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Salut ! Le nom est {STR_VAR_1} ! Je suis\n"
	.string "un ÉLEVEUR DE POKéMON !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Les POKéMON que j'ai soulevés sont\n"
	.string "un {STR_VAR_1} utilisant {STR_VAR_2} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_1}-en utilisant {STR_VAR_2}. A\n"
	.string "l'air intéressant? Et si on formait\p"
	.string "une équipe, alors ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Très bien ! Vous me laissez\n"
	.string "l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Tu devras faire équipe avec moi la\n"
	.string "prochaine fois, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Je m'appelle {STR_VAR_1} et je suis fier\n"
	.string "de dire que je suis un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Le POKéMON chéri que j'ai élevé est\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Ne sont-ils\n"
	.string "pas simplement les plus mignons ?\p"
	.string "On devrait faire une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Merci très cher! Je suis sur le\n"
	.string "point de m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mes POKéMON chéris sont les\n"
	.string "meilleurs, je vous le ferai savoir.\p"
	.string "Comme c'est ennuyeux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Bonjour, je m'appelle SWIMMER\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_1} -- utilisant {STR_VAR_2} $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2} sont\n"
	.string "ce que j'ai entraîné. Toi et moi,\p"
	.string "formons une équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "C'est super! Je vais nous inscrire\n"
	.string "tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si nous nous reverrons, tu me dois\n"
	.string "une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Ce qui se passe? Je m'appelle\n"
	.string "{STR_VAR_1} et je suis un TRIATHLÈTE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "J'ai quelques POKéMON décents. Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Ce serait\n"
	.string "bien si nous formions une équipe\p"
	.string "ensemble, alors qu'en pensez-vous\n"
	.string "?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "C'est parti ! Attends pendant que\n"
	.string "je m'inscris, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "J'espère que tu me laisseras te\n"
	.string "rejoindre la prochaine fois,\p"
	.string "comment ça se passe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Je suis le TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "un autre {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. C'est ma paire. Qu'en\p"
	.string "penses-tu? Nous formerions une\n"
	.string "bonne équipe, je dirais.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "J'aime cette réponse! Je vais vite\n"
	.string "terminer l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Vous me donnerez une autre chance\n"
	.string "de former un partenariat, n'est-ce\p"
	.string "pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Salut! Bonjour! Je m'appelle {STR_VAR_1}\n"
	.string "et je suis un NAGEUR !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Découvrez ce que j'ai soulevé ! Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} ! Doux, hein\n"
	.string "? Ce serait sympa aussi de former\p"
	.string "une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Bien obligé! Je vais faire cette\n"
	.string "inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si nous nous reverrons, vous devrez\n"
	.string "faire équipe avec moi. Tu vas faire\p"
	.string "ça, n'est-ce pas ?$"
