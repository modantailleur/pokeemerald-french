.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ONCLE : C'est grâce à POKéMON que\n"
	.string "ce garçon a plus de peps, je\p"
	.string "suppose… Mais il est devenu un peu\n"
	.string "trop plein d'entrain…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "TIMMY : Aww, ONCLE, s'il te plaît ?\n"
	.string "Je veux défier ce GYM et voir à\p"
	.string "quel point je me suis amélioré.\n"
	.string "S'il te plaît? Puis-je, s'il vous\p"
	.string "plaît ?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ONCLE : Maintenant, attends, TIMMY.\n"
	.string "Depuis que vous avez commencé à\p"
	.string "vivre avec POKéMON, vous êtes\n"
	.string "devenu beaucoup plus fort. Mais ne\p"
	.string "pensez-vous pas que vous le poussez\n"
	.string "à défier soudainement un GYM ?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "TIMMY : Je n'insiste pas. Si je\n"
	.string "combine mes forces avec RALTS, nous\p"
	.string "pouvons battre n'importe qui !$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "TIMMY : Oh ! Salut, {PLAYER} ! Je\n"
	.string "suis devenu beaucoup plus fort\p"
	.string "depuis notre rencontre. {PLAYER}, je\n"
	.string "veux que vous et mon ONCLE\p"
	.string "compreniez cela. {PLAYER}, s'il vous\n"
	.string "plaît, allez-vous vous battre avec\p"
	.string "moi ?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "TIMMY : Oh… Si tu ne me combats\n"
	.string "pas, {PLAYER}, mon ONCLE ne saura pas\p"
	.string "que je suis devenu vraiment fort.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ONCLE : {PLAYER}{KUN}, n'est-ce pas\n"
	.string "? Au nom de TIMMY, puis-je vous\p"
	.string "demander de vous battre contre lui\n"
	.string "juste pour cette fois ? Je ne pense\p"
	.string "pas qu'il va écouter une quelconque\n"
	.string "raison comme il le fait\p"
	.string "maintenant.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "TIMMY : {PLAYER}, s'il vous plaît !\n"
	.string "Combattez avec moi, s'il vous\p"
	.string "plaît.$"

MauvilleCity_Text_WallyHereICome:
	.string "TIMMY : {PLAYER}, merci. D'accord… Me\n"
	.string "voilà !$"

MauvilleCity_Text_WallyDefeat:
	.string "TIMMY : … … … … … … … … … … … … … …\n"
	.string "… J’ai perdu…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "TIMMY : ONCLE… Je retourne à\n"
	.string "VERGUIDOTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, merci. Être FORMATTHIEUEUR,\n"
	.string "c'est dur, n'est-ce pas ? Il ne\p"
	.string "suffit pas d'avoir POKéMON et de\n"
	.string "les faire se battre. Ce n'est pas\p"
	.string "ça, être un vrai FORMATTHIEUEUR.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ONCLE : TIMMY, il n'est pas\n"
	.string "nécessaire d'être aussi déprimé\p"
	.string "envers toi-même. Pourquoi,\n"
	.string "qu'est-ce qui t'empêche de devenir\p"
	.string "de plus en plus fort ? Allez,\n"
	.string "rentrons à la maison. Tout le monde\p"
	.string "vous attend.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ONCLE : {PLAYER}{KUN}, je viens de\n"
	.string "me rendre compte que tu dois être\p"
	.string "l'DRESSEUR qui a gardé un œil sur\n"
	.string "TIMMY lorsqu'il a attrapé son\p"
	.string "POKéMON. Pourquoi ne nous\n"
	.string "rendriez-vous pas visite à\p"
	.string "VERGUIDOTURF un jour ? Je suis sûr\n"
	.string "que TIMMY l'apprécierait.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … … … … … … … Bip ! TIMMY :\n"
	.string "Oh, bonjour, {PLAYER} ! Je voulais\p"
	.string "juste te dire que mon oncle m'a\n"
	.string "acheté un POKéNAV ! Je peux\p"
	.string "désormais vous contacter à tout\n"
	.string "moment, {PLAYER} ! … … … … … … … … …\p"
	.string "… … Cliquez !$"

MauvilleCity_Text_RegisteredWally:
	.string "TIMMY inscrit dans le POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT : Héhé… Je regardais ce match\n"
	.string "! Tu es ami avec ce garçon TIMMY,\p"
	.string "n'est-ce pas ? Mais vous n'avez\n"
	.string "rien retenu et vous l'avez battu de\p"
	.string "manière impressionnante. Ouais!\n"
	.string "C'est ça, une vraie bataille\p"
	.string "POKéMON ! J'idolâtre les\n"
	.string "FORMATTHIEUEURS comme ça ! … … … …\p"
	.string "… … Je t'encouragerai !$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "VOLTÈRE : Oh, {PLAYER}{KUN} ! On\n"
	.string "dirait que tu as beaucoup de zip !\p"
	.string "C'est une bonne chose, wahahahaha !\n"
	.string "Bien! J'ai décidé! J'ai besoin\p"
	.string "d'une faveur, {PLAYER}{KUN} !\n"
	.string "LAVANDIA possède un secteur\p"
	.string "souterrain appelé NEW LAVANDIA.\n"
	.string "{PLAYER}{KUN}, j'aimerais que vous y\p"
	.string "alliez et que vous éteigniez le\n"
	.string "GÉNÉRATEUR. Le GÉNÉRATEUR tourne un\p"
	.string "peu de travers. Cela devient\n"
	.string "dangereux. Voilà, c'est la CLÉ pour\p"
	.string "entrer dans NEW LAVANDIA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "VOLTÈRE : Ne vous inquiétez pas\n"
	.string "pour ça. Ce ne sera pas un défi\p"
	.string "pour vous. L'entrée de NEW LAVANDIA\n"
	.string "est à quelques minutes de SURF de\p"
	.string "la ROUTE 110. Ça y est alors, vous\n"
	.string "avez ma confiance ! Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "VOLTÈRE : Wahahahaha ! Je le\n"
	.string "savais, {PLAYER}{KUN} ! Je savais\p"
	.string "que j'avais fait le bon choix en te\n"
	.string "demandant ! Ceci est mes\p"
	.string "remerciements : une MT contenant\n"
	.string "THUNDERBOLT ! Allez-y, vous l'avez\p"
	.string "bien mérité !$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "VOLTÈRE : Wahahahaha ! Cela me fait\n"
	.string "énormément plaisir de voir les\p"
	.string "jeunes se mobiliser et prendre les\n"
	.string "choses en main !$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Vous savez, c'est cool d'avoir des\n"
	.string "combats POKéMON et tout ça… Mais si\p"
	.string "votre POKéMON est blessé, vous\n"
	.string "devez le soigner.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Les routes de cette ville\n"
	.string "s'étendent du nord au sud, et de\p"
	.string "l'est à l'ouest. À cause de cela,\n"
	.string "nous recevons toutes sortes de\p"
	.string "gens.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Êtes-vous déjà allé à RODOLPHE'S\n"
	.string "CYCLES ? RODOLPHE, le propriétaire,\p"
	.string "est un homme très généreux.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Même si vous conduisez un VÉLO, des\n"
	.string "POKéMON sauvages pourraient vous\p"
	.string "sauter dessus.$"

MauvilleCity_Text_CitySign:
	.string "LAVANDIA “ La ville lumineuse et\n"
	.string "brillante du plaisir ! ”$"

MauvilleCity_Text_GymSign:
	.string "LAVANDIA POKéMON GYM LEADER :\n"
	.string "VOLTÈRE “ L'homme joyeusement\p"
	.string "électrisant ! ”$"

MauvilleCity_Text_BikeShopSign:
	.string "“ Roulez dans le gravier et secouez\n"
	.string "votre âme ! ” LES CYCLES DE\p"
	.string "RODOLPHE$"

MauvilleCity_Text_GameCornerSign:
	.string "“ Le lieu de jeu pour tous ! ” COIN\n"
	.string "DE JEU MAUVILLE$"

MauvilleCity_Text_ExplainTV:
	.string "Salut, est-ce que tu regardes la\n"
	.string "télévision ? Ils ont récemment\p"
	.string "ajouté un tas de nouvelles\n"
	.string "émissions sympas. La télé est\p"
	.string "tellement cool. J'ai vu mes amis à\n"
	.string "la télévision à l'improviste. Et\p"
	.string "parfois, ils vous mettent même à la\n"
	.string "télé sans vous le dire. J'aurais\p"
	.string "aimé passer à la télé un jour.\n"
	.string "C'est pourquoi je pense que vous\p"
	.string "devriez regarder les téléviseurs\n"
	.string "chaque fois que vous le pouvez.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Salut, as-tu regardé les\n"
	.string "téléviseurs ?$"
