.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Non! Ces crétins de la TEAM MAGMA\n"
	.string "sont arrivés devant nous ! Nous ne\p"
	.string "pouvons pas prendre du retard !$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Je pensais que tu faisais partie\n"
	.string "des MAGMAS qui revenaient par\p"
	.string "hasard…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ouais, donc tu es fort… Mais nous\n"
	.string "sommes nombreux !$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah ! Dommage pour toi! Si vous\n"
	.string "étiez venu plus tôt, vous n'auriez\p"
	.string "eu qu'à combattre la mauviette TEAM\n"
	.string "MAGMA. Mais puisque tu es arrivé\p"
	.string "maintenant, tu dois affronter nous\n"
	.string "les durs !$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… J'aurais dû te laisser\n"
	.string "affronter la TEAM MAGMA en\p"
	.string "premier…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Vous ne savez rien ! Alors pourquoi\n"
	.string "tu te moques de nous ?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Vous… Nous vous avons vu à MONT\n"
	.string "CHIMNEE. Vous n'appartenez à aucune\p"
	.string "des deux ÉQUIPES, alors pourquoi\n"
	.string "seriez-vous ici ?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si vous voulez embêter quelqu'un,\n"
	.string "que ce soit TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Hé, ce n'est pas grave ! Nous avons\n"
	.string "gagné du temps ! Le BOSS aurait dû\p"
	.string "lui voler ce qu'il cherchait !$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, je sais! Vous avez essayé de\n"
	.string "rejoindre la TEAM MAGMA, mais ils\p"
	.string "n'ont pas voulu de vous ! Eh bien,\n"
	.string "ne pensez pas que nous vous\p"
	.string "laisserons rejoindre notre TEAM\n"
	.string "AQUA !$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si vous souhaitez à ce point\n"
	.string "rejoindre TEAM AQUA, nous pouvons y\p"
	.string "réfléchir…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Nous avons une excellente\n"
	.string "combinaison entre nous, membres et\p"
	.string "notre leader.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARTHUR : MAX de TEAM MAGMA nous a\n"
	.string "devancés, mais nous avons également\p"
	.string "obtenu ce que nous voulions. L'ORB\n"
	.string "ROUGE conservé à MT. PYRE… Moi,\p"
	.string "ARTHUR, je l'ai maintenant en ma\n"
	.string "possession ! Fufufu… Nous pouvons\p"
	.string "maintenant concrétiser notre\n"
	.string "objectif ultime ! D'accord,\p"
	.string "l'ÉQUIPE ! On se retire !$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, non… Cela ne peut pas arriver…\n"
	.string "Non seulement l'ORB BLEU, mais même\p"
	.string "l'ORB ROUGE a été pris… L'ORB BLEU\n"
	.string "et l'ORB ROUGE ne doivent jamais\p"
	.string "être séparés. Ils vont ensemble.\n"
	.string "Qu'est-ce que ces hommes essaient\p"
	.string "de faire avec les deux ORBS ? … … …\n"
	.string "… … … … … … … … … Oh oui. Est-ce\p"
	.string "que c'est la TEAM MAGMA qui est\n"
	.string "venue et a pris l'ORB BLEU en\p"
	.string "premier ? Eh bien, dans leur hâte,\n"
	.string "ils ont laissé ça derrière eux. Je\p"
	.string "ne pouvais pas imaginer ce que cela\n"
	.string "pourrait être exactement.\p"
	.string "J'aimerais que tu l'aies. Peut-être\n"
	.string "que cela sera utile d'une manière\p"
	.string "ou d'une autre.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "L'ORB BLEU et l'ORB ROUGE pris par\n"
	.string "ces hommes sinistres… Ils ne\p"
	.string "doivent jamais être séparés… J'ai\n"
	.string "peur que quelque chose de terrible\p"
	.string "n'arrive…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh mon Dieu… Vous dites que GROUDON\n"
	.string "et KYOGRE ont été réveillés ? On\p"
	.string "dit que l'ORB BLEU et l'ORB ROUGE\n"
	.string "ont apaisé la rage des deux\p"
	.string "POKéMON… On dit aussi que le\n"
	.string "véritable propriétaire des ORBS\p"
	.string "existe toujours. Cependant,\n"
	.string "personne ne sait à qui ou à quoi\p"
	.string "appartiennent exactement les ORBS.\n"
	.string "Il pourrait s'agir d'un humain, ou\p"
	.string "peut-être d'un POKéMON, mais\n"
	.string "personne ne le sait.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Les deux hommes qui ont pris les\n"
	.string "ORBS sont revenus les rendre\p"
	.string "d'eux-mêmes. Ces hommes… Peut-être\n"
	.string "qu’ils ne sont pas si méchants\p"
	.string "après tout…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Les incarnations de la terre, de la\n"
	.string "mer et du ciel… On dit que ce sont\p"
	.string "les identités des POKéMON\n"
	.string "super-anciens… De la même manière\p"
	.string "que nous, les humains et POKéMON,\n"
	.string "avons la vie, notre monde aussi est\p"
	.string "vivant… Le super-ancien POKéMON\n"
	.string "nous a appris que…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MT. PYRE est l'endroit où nous\n"
	.string "calmons les esprits de POKéMON\p"
	.string "décédés… C'est un endroit en\n"
	.string "hauteur où l'on peut voir tout\p"
	.string "HOENN… Les esprits désincarnés de\n"
	.string "POKéMON doivent trouver du\p"
	.string "réconfort ici… Est-ce une\n"
	.string "coïncidence si vous êtes ici…\p"
	.string "Allez-vous entendre mon conte? Une\n"
	.string "histoire racontée depuis longtemps\p"
	.string "dans la région HOENN ?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Cela s'est produit il y a très,\n"
	.string "très longtemps… Le monde a été\p"
	.string "détruit par un affrontement féroce\n"
	.string "entre le POKéMON de la terre et le\p"
	.string "POKéMON de la mer… Le POKéMON de la\n"
	.string "terre a soulevé des montagnes et\p"
	.string "créé des continents… Le POKéMON de\n"
	.string "la mer a soulevé d'énormes vagues\p"
	.string "et a creusé océans… Leur duel\n"
	.string "acharné faisait rage sans fin. Le\p"
	.string "monde était englouti dans des\n"
	.string "enfers massifs et de violentes\p"
	.string "tempêtes. L'ORB BLEU et l'ORB ROUGE\n"
	.string "ont mis fin à la calamité. La\p"
	.string "lumière jaillit des deux ORBS et\n"
	.string "calma les adversaires enragés. Le\p"
	.string "couple, rendu docile, plongea\n"
	.string "profondément dans la mer où ils\p"
	.string "finirent par disparaître…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Je vois… Eh bien, ça aussi, c'est\n"
	.string "bien…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAX : {PLAYER}… … … … … … … … … … … …\n"
	.string "$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "C'est mon rôle de transmettre les\n"
	.string "légendes de HOENN aux générations\p"
	.string "futures. Et la crise qui vient de\n"
	.string "se terminer à SOOTOPOLIS a réécrit\p"
	.string "une légende… Avez-vous le temps\n"
	.string "d'entendre la nouvelle légende de\p"
	.string "HOENN ?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Cela s'est produit il y a très,\n"
	.string "très longtemps… Le monde a été\p"
	.string "détruit par un affrontement féroce\n"
	.string "entre le POKéMON de la terre et le\p"
	.string "POKéMON de la mer… Le POKéMON de la\n"
	.string "terre a soulevé des montagnes et\p"
	.string "créé des continents… Le POKéMON de\n"
	.string "la mer a soulevé d'énormes vagues\p"
	.string "et a creusé océans… Leur duel\n"
	.string "acharné faisait rage sans fin. Le\p"
	.string "monde a été ravagé par des\n"
	.string "incendies massifs et de violentes\p"
	.string "tempêtes. C'est alors que le\n"
	.string "POKéMON du ciel descendit d'une\p"
	.string "tempête. Le POKéMON, brillant d'un\n"
	.string "vert vif, calma les deux POKéMON\p"
	.string "enragés. Puis, son devoir accompli,\n"
	.string "le POKéMON vert s'envola dans le\p"
	.string "bleu sauvage là-bas…$"
