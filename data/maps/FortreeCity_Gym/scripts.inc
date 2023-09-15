FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va, {PLAYER} lié au\n"
	.string "CHAMPION ? FORTREE GYM LEADER\p"
	.string "ALIZÉE est un maître des POKéMON de\n"
	.string "type VOL. Elle attend au fond de ce\p"
	.string "GYM, derrière les portes\n"
	.string "tournantes. Elle attend de nouveaux\p"
	.string "challengers qui tentent de prendre\n"
	.string "leur envol ! Ok, vas-y !$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Tu l'as fait! Vous avez réussi le\n"
	.string "décollage !$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Découvrez le style de combat\n"
	.string "élégant de BIRD POKéMON !$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tu… Tu es fort…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "UN DRESSEUR doit être\n"
	.string "intelligent pour faire face aux\p"
	.string "rebondissements inattendus des\n"
	.string "événements. Avez-vous\p"
	.string "l'intelligence pour accéder à notre\n"
	.string "LEADER?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Les amoureux de BIRD POKéMON\n"
	.string "aspirent à rejoindre ce GYM. En\p"
	.string "tant que membre du FORTREE GYM, je\n"
	.string "n'ai pas le droit de perdre !$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "C'était trop de charge à supporter\n"
	.string "pour moi…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Le monde est immense et il existe\n"
	.string "d’innombrables DRESSEURS\p"
	.string "coriaces. Je vais continuer à\n"
	.string "m'entraîner et me rendre encore\p"
	.string "plus fort.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Inutile que ALIZÉE, notre GYM\n"
	.string "LEADER, s'occupe de vous ! Je suis\p"
	.string "assez bien pour toi !$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "ALIZÉE, je… j'ai perdu !$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "ALIZÉE est mignonne et forte. Elle\n"
	.string "est la LEADER ultime ! Rougir…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "ALIZÉE m'a appris personnellement !\n"
	.string "Tu ne peux pas me battre facilement\p"
	.string "!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "J'ai été battu…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Grâce à ALIZÉE, les habitants de\n"
	.string "FORTREE peuvent vivre sans\p"
	.string "crainte.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Lorsque ALIZÉE se lance au combat,\n"
	.string "son visage brille d'une belle\p"
	.string "détermination… Je ne vous laisse\n"
	.string "pas assister à ce beau spectacle !$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk! Je n'ai pas pu t'arrêter.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Tu ferais mieux de le regarder ! Ne\n"
	.string "vous laissez pas distraire en\p"
	.string "regardant ALIZÉE ou vous vous\n"
	.string "effondrerez en tas !$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Sachez qu'il existe toutes sortes\n"
	.string "de POKéMON de type VOLANT. Vous le\p"
	.string "savez, n'est-ce pas ?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Vous semblez connaître votre métier\n"
	.string "!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Bien sûr, tu m'as bien battu. Mais\n"
	.string "tu ferais mieux de le regarder !\p"
	.string "Les POKéMON de notre LEADER ALIZÉE\n"
	.string "sont tous des affaires.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Je suis ALIZÉE. Je suis le LEADER\n"
	.string "du FORTREE POKéMON GYM. Je ne fais\p"
	.string "plus qu'un avec BIRD POKéMON et\n"
	.string "j'ai plané dans les cieux... Quelle\p"
	.string "que soit l'épuisante bataille, nous\n"
	.string "avons triomphé avec grâce... Soyez\p"
	.string "témoin de l'élégante chorégraphie\n"
	.string "de BIRD POKéMON et moi !$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Jamais auparavant je n'avais vu un\n"
	.string "DRESSEUR commander POKéMON avec\p"
	.string "plus de grâce que moi… En\n"
	.string "reconnaissance de vos prouesses, je\p"
	.string "vous présente ce GYM BADGE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} a reçu le BADGE PLUME de\n"
	.string "ALIZÉE.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Avec le BADGE PLUME, tous les\n"
	.string "POKéMON jusqu'au LV 70, même ceux\p"
	.string "reçus via les échanges, obéiront à\n"
	.string "chacun de vos ordres. Vous pourrez\p"
	.string "également utiliser le mouvement HM\n"
	.string "FLY en dehors des combats. Et ça…\p"
	.string "C'est un cadeau de ma part.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 contient AERIAL ACE. Sa\n"
	.string "vitesse… Aucun POKéMON ne devrait\p"
	.string "pouvoir l'éviter. … … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Inscrit GYM LEADER ALIZÉE dans le\n"
	.string "POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Même si je suis tombé amoureux de\n"
	.string "toi, je resterai dévoué à BIRD\p"
	.string "POKéMON.$"

FortreeCity_Gym_Text_GymStatue:
	.string "CIMETRONELLE POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "CIMETRONELLE POKéMON GYM DRESSEURS\n"
	.string "CERTIFIÉS DE ALIZÉE : {PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ALIZÉE : Nous, les humains, ne\n"
	.string "pouvons jamais échapper à\p"
	.string "l’attraction de la gravité sur le\n"
	.string "sol. Mais en visant l’excellence,\p"
	.string "nous avons le pouvoir de nous\n"
	.string "envoler ! Vous avez atteint le\p"
	.string "sommet en tant que CHAMPION en\n"
	.string "titre. S'il vous plaît,\p"
	.string "permettez-moi de voir votre\n"
	.string "puissance à plein vol !$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Je n'ai pas réussi à atteindre à\n"
	.string "nouveau ta taille…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ALIZÉE : Même si j'ai perdu, les\n"
	.string "ailes de mon cœur restent intactes.\p"
	.string "Je peux m'élever et m'envoler\n"
	.string "encore et encore. J'en suis\p"
	.string "convaincu!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "ALIZÉE : Nous, les humains, ne\n"
	.string "pouvons jamais échapper à\p"
	.string "l’attraction de la gravité sur le\n"
	.string "sol. Mais en visant l’excellence,\p"
	.string "nous avons le pouvoir de nous\n"
	.string "envoler ! Vous avez atteint le\p"
	.string "sommet en tant que CHAMPION en\n"
	.string "titre. S'il vous plaît,\p"
	.string "permettez-moi de voir votre\n"
	.string "puissance à plein vol ! Oh non…\p"
	.string "Vous n'avez qu'un seul POKéMON avec\n"
	.string "vous ? Veuillez revenir avec au\p"
	.string "moins deux POKéMON.$"
