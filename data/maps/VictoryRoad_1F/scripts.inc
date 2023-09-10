.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "TIMMY : Salut ! {PLAYER}! Je parie\n"
	.string "que vous êtes surpris de me voir\p"
	.string "ici ! J'ai réussi jusqu'ici, et\n"
	.string "c'est grâce à vous ! {PLAYER}, perdre\p"
	.string "contre toi m'a rendu plus fort !\n"
	.string "Mais je ne vais plus perdre ! Je\p"
	.string "vais gagner! Pour le POKéMON qui\n"
	.string "m'a donné courage et force !\p"
	.string "D'accord… Me voilà !$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Ouah! {PLAYER}, tu es fort, après\n"
	.string "tout !$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "TIMMY : Je n'ai pas pu te battre\n"
	.string "aujourd'hui, {PLAYER}, mais un de ces\p"
	.string "jours, je te rattraperai !$"

VictoryRoad_1F_Text_WallyIntro:
	.string "TIMMY : Salut ! {PLAYER}! Je suis\n"
	.string "devenu plus fort depuis la dernière\p"
	.string "fois ! Je voulais vous montrer,\n"
	.string "{PLAYER} ! D'accord… Me voilà !$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Ouah! {PLAYER}, tu es fort, après\n"
	.string "tout !$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "TIMMY : Je n'ai pas pu te battre\n"
	.string "cette fois aussi... Mais un de ces\p"
	.string "jours, {PLAYER}, je vais te\n"
	.string "rattraper... Et défier la LIGUE\p"
	.string "POKéMON !$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Je suis arrivé jusqu'ici plusieurs\n"
	.string "fois, mais le dernier tronçon est\p"
	.string "si long…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Mon rêve se termine encore ici…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Vous êtes arrivé jusqu'ici.\n"
	.string "Continuez sur votre lancée et\p"
	.string "devenez le CHAMPION ! Si quelqu'un\n"
	.string "le peut, c'est bien vous !$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Je n'ai pas fait tout ce chemin\n"
	.string "pour perdre. Cette possibilité\p"
	.string "n'existe pas !$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossible… j'ai perdu ?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "J'ai perdu ici… Cela veut dire que\n"
	.string "je n'ai pas les qualifications pour\p"
	.string "devenir CHAMPION…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Cette route apparemment infinie et\n"
	.string "difficile porte bien son nom de\p"
	.string "VICTOIRE.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Votre style de combat est\n"
	.string "fantastique…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Vous semblez avoir le potentiel\n"
	.string "pour devenir CHAMPION.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Qu’est-ce que la ROUTE VICTOIRE ?\n"
	.string "Je te dirai si tu gagnes !$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "D'accord! Bravo !$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Arriver ici en toute sécurité,\n"
	.string "c'est le test final pour tout\p"
	.string "DRESSEUR souhaitant devenir le\n"
	.string "CHAMPION POKéMON. C'est pourquoi on\p"
	.string "l'appelle la ROUTE VICTOIRE.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Je n'ai rien à dire à quiconque est\n"
	.string "arrivé jusqu'ici. Allez!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "C'est une honte…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Humph, continuez tout droit. Voyez\n"
	.string "si je m'en soucie.$"
