.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
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

MossdeepCity_Movement_ScottExitEast:
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

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Je l'ai reçu de PIERRE, mais je ne\n"
	.string "sais pas à quoi ça sert. Je pense\p"
	.string "que ça s'appelle KING'S ROCK. Tu le\n"
	.string "veux ?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pourquoi le voudrais-tu? Tu es\n"
	.string "étrange. Vous pouvez le garder,\p"
	.string "mais gardez-le secret pour PIERRE.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La maison de PIERRE est juste\n"
	.string "là-bas !$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ouais, tu le penses aussi !\n"
	.string "Qu'est-ce que tu es censé faire\p"
	.string "avec un rock bizarre ?$"

MossdeepCity_Text_WailmerWatching:
	.string "Autour de MOSSDEEP, vous pouvez\n"
	.string "voir des WAILMER sauvages. Ça\p"
	.string "s'appelle, euh… Qu'est-ce que\n"
	.string "c'était maintenant… WAI, WAI, WAI…\p"
	.string "WAILMER regarde !$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Le CENTRE SPATIAL de l'île a lancé\n"
	.string "d'énormes fusées. Il y a eu une\p"
	.string "sorte de tollé à propos d'une\n"
	.string "lettre qu'ils ont reçue récemment.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Le CENTRE SPATIAL de l'île a lancé\n"
	.string "d'énormes fusées.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "J'ai entendu dire par un copain\n"
	.string "SAILOR que TEAM AQUA s'était\p"
	.string "installée à LILYCOVE. J'ai aussi\n"
	.string "entendu dire que quelqu'un était\p"
	.string "venu et avait essuyé le sol avec\n"
	.string "eux ! Mais MOSSDEEP ici a été ciblé\p"
	.string "par cette TEAM MAGMA. Si vous\n"
	.string "voulez savoir ce qu'ils font, allez\p"
	.string "visiter le SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Je suis MARIN, donc la mer est\n"
	.string "évidemment plus importante pour\p"
	.string "moi. Mais vous savez? Quand je\n"
	.string "retourne à terre après un long\p"
	.string "voyage, je ressens un soulagement\n"
	.string "!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ne serait-ce pas sympa ? Si le\n"
	.string "monde entier était couvert de\p"
	.string "plantes et de fleurs comme cette\n"
	.string "île ?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toute vie a besoin de la mer pour\n"
	.string "vivre, même si elle habite sur la\p"
	.string "terre ferme. La vie, après avoir\n"
	.string "suivi son cours, devient terre et\p"
	.string "retourne à la terre. Et la mer est\n"
	.string "toujours connectée à la terre. Oui,\p"
	.string "comme le rivage même ici.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un voyage sur un bateau, c'est\n"
	.string "bien. Mais traverser la mer avec\p"
	.string "POKéMON en utilisant SURF… Voilà un\n"
	.string "voyage exaltant ! N'êtes-vous pas\p"
	.string "d'accord, jeune ?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Ce rocher a une signification\n"
	.string "particulière pour les gens du SPACE\p"
	.string "CENTER. Ils l’ont mis ici comme\n"
	.string "souhaitant que leurs fusées volent\p"
	.string "en toute sécurité. Quand tu fais un\n"
	.string "vœu, qu'utilises-tu ?\p"
	.string "Souhaitez-vous une étoile ?\n"
	.string "J'utilise une balise de souhait\p"
	.string "pour y arriver. C'est ce que je\n"
	.string "fais.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "C'est un rocher blanc.$"

MossdeepCity_Text_GymSign:
	.string "LEADERS DU POKéMON GYM DE ALGATIA :\n"
	.string "LIZA GUIDO LÉVY “ La combinaison\p"
	.string "mystique ! ”$"

MossdeepCity_Text_CitySign:
	.string "ALGATIA “ Notre slogan : Chérissez\n"
	.string "POKéMON ! ”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER “ L’endroit\n"
	.string "le plus proche de l’espace. ”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT : {PLAYER}{KUN}, tu te sens\n"
	.string "bien ? Je le fais bien! J'avais\p"
	.string "entendu dire que GYM LEADER de\n"
	.string "MOSSDEEP était plutôt fort, alors\p"
	.string "j'ai décidé de venir jeter un œil\n"
	.string "par moi-même. Mais il y a quelque\p"
	.string "chose qui ne va pas dans cette\n"
	.string "ville. Les gens parlent d'une\p"
	.string "lettre d'avertissement et du CENTRE\n"
	.string "SPATIAL… Mais je ne pense pas que\p"
	.string "cela me concerne en aucune façon.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… C'est génial de laisser les\n"
	.string "vagues déferler sur mes pieds… En\p"
	.string "parlant de vagues, vous connaissez\n"
	.string "cette ville insulaire SOOTOPOLIS ?\p"
	.string "Je pense que le GYM a accueilli un\n"
	.string "nouveau LEADER. Les gens me disent\p"
	.string "que le nouveau LEADER a autrefois\n"
	.string "encadré MARC.$"
