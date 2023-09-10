.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Je suis le FOSSIL MANIAC… Je suis\n"
	.string "un gars sympa qui aime les\p"
	.string "FOSSILES… Tu veux un FOSSILE ? Mais\n"
	.string "les FOSSILES autour de ces régions\p"
	.string "m'appartiennent tous… Aucun pour\n"
	.string "vous… Si vous ne supportez pas de\p"
	.string "vous passer d'un FOSSILE, regardez\n"
	.string "dans un désert où il y a des\p"
	.string "rochers et du sable qui peuvent\n"
	.string "cacher des FOSSILES…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Vous avez trouvé un FOSSILE,\n"
	.string "n'est-ce pas ? C'est si gentil…\p"
	.string "C'est tellement rêveur… Qu'est-ce\n"
	.string "que tu vas faire de ce FOSSILE ?\p"
	.string "D'après ce que j'ai entendu, DEVON\n"
	.string "fait des recherches pour faire\p"
	.string "revivre POKéMON à partir de\n"
	.string "FOSSILES… J'adore mes FOSSILES,\p"
	.string "donc je ne ferais jamais quelque\n"
	.string "chose comme ça…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "LES FOSSILES sont tellement…\n"
	.string "Merveilleux… C'est tellement\p"
	.string "rêveur…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh… Ce n'est pas sûr comme ça…\n"
	.string "J'étais en train de creuser, tu\p"
	.string "vois… Quand tout le mur s'est\n"
	.string "effondré… Je pense qu'il y a une\p"
	.string "caverne géante en dessous\n"
	.string "maintenant… Mais je l'ai laissé\p"
	.string "tranquille parce que je ne pense\n"
	.string "pas qu'il y ait de FOSSILES là-bas…\p"
	.string "$"
