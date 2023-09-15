SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Comment ça va, CHAMPION- {PLAYER}\n"
	.string "? JUAN, GYM LEADER de SOOTOPOLIS,\p"
	.string "est un maître des POKéMON de type\n"
	.string "EAU. Et, pour arriver à JUAN, un\p"
	.string "sol glacé gênera votre progression…\n"
	.string "Écoutez, je suis désolé, mais c'est\p"
	.string "tout le conseil que j'ai à vous\n"
	.string "donner. Pour le reste, vous devez y\p"
	.string "aller vous-même !$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Ouais ! Vous avez même battu JUAN,\n"
	.string "qui était censé être le meilleur de\p"
	.string "tout HOENN ! D'accord! Consultez\n"
	.string "votre CARTE DE DRESSEUR. Si\p"
	.string "vous avez obtenu tous les BADGES,\n"
	.string "vous êtes prêt à relever le défi\p"
	.string "POKéMON LEAGUE !$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Laisse moi te demander.\n"
	.string "Saviez-vous? Ah, je ne devrais pas\p"
	.string "être si timide. C'est moi qui ai\n"
	.string "appris à MARC tout ce qu'il y a à\p"
	.string "savoir sur POKéMON. Une fois,\n"
	.string "j'avais abandonné mon poste de GYM\p"
	.string "LEADER. A ma place, j'avais confié\n"
	.string "à MARC le GYM. Cependant, une\p"
	.string "raison impérieuse s’est présentée\n"
	.string "pour moi de faire un retour. Ah,\p"
	.string "mais assez de bavardage. Commençons\n"
	.string "notre match, d'accord ? S'il vous\p"
	.string "plaît, vous serez témoin de notre\n"
	.string "talent artistique. Une grande\p"
	.string "illusion d'eau sculptée par POKéMON\n"
	.string "et moi-même !$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, excellent ! Très bien,\n"
	.string "vous êtes le gagnant. De votre\p"
	.string "part, je sens l’éclat brillant\n"
	.string "d’une compétence qui vaincra tout.\p"
	.string "Cependant, comparé à moi ou même à\n"
	.string "MARC, vous manquez d'élégance.\p"
	.string "Peut-être devrais-je vous prêter ma\n"
	.string "tenue ? … … … … … … … … … … … …\p"
	.string "Hahaha, je plaisante ! Plutôt que\n"
	.string "mes vêtements, je vous\p"
	.string "récompenserai avec ceci, le RAIN\n"
	.string "BADGE !$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} a reçu le BADGE DE PLUIE de\n"
	.string "JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avoir le RAIN BADGE vous assurera\n"
	.string "la pleine obéissance de tous vos\p"
	.string "POKéMON à chacun de vos ordres. Le\n"
	.string "RAIN BADGE permet également\p"
	.string "d'utiliser le HM move WATERFALL\n"
	.string "pour escalader des murs d'eau en\p"
	.string "cascade. Et, pour que vous\n"
	.string "n'oubliiez jamais la bataille que\p"
	.string "nous avons partagée, prenez ceci…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MACHINE TECHNIQUE que je vous ai\n"
	.string "remise contient de l'EAU PULSE.\p"
	.string "Lors de son utilisation, il arrive\n"
	.string "parfois qu'il confonde la cible\p"
	.string "avec les ondes ultrasonores. … … …\n"
	.string "… … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Inscrit GYM LEADER JUAN dans le\n"
	.string "POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont\n"
	.string "rassemblé tous les GYM BADGES de\p"
	.string "HOENN devraient se diriger vers la\n"
	.string "destination ultime. La LIGUE\p"
	.string "POKéMON. Voyagez jusqu’à l’extrême\n"
	.string "est de HOENN, sur l’île EVER\p"
	.string "GRANDE. Là, vous trouverez la LIGUE\n"
	.string "POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Il ne reste plus qu'un BADGE à\n"
	.string "obtenir à HOENN. Si vous souhaitez\p"
	.string "défier la LIGUE POKéMON, vous devez\n"
	.string "obtenir le dernier BADGE du GYM de\p"
	.string "FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ATALANOPOLIS POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ATALANOPOLIS POKéMON GYM DRESSEURS\n"
	.string "CERTIFIÉS DE JUAN : {PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN : Ah, ce GYM avait retrouvé\n"
	.string "son état de sérénité habituel… Mais\p"
	.string "notre jeune typhon est revenu pour\n"
	.string "nous mettre à nouveau à l'épreuve !\p"
	.string "Eh bien, mon ami, certainement ! Je\n"
	.string "serai ravie de danser avec vous\p"
	.string "aussi souvent que vous le\n"
	.string "souhaiterez !$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, tu es le gagnant ! Vous\n"
	.string "m'avez encore vaincu !$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN : Si je te disais de devenir\n"
	.string "mon apprenti, tu refuserais, j'en\p"
	.string "suis sûr. J'aimerais vous faire\n"
	.string "cadeau de mon manteau. Mais encore\p"
	.string "une fois, vous refuserez. J'imagine\n"
	.string "qu'il en est ainsi. Et ça, mon ami,\p"
	.string "c'est un certain signe de noblesse\n"
	.string "!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN : Ah, ce GYM avait retrouvé\n"
	.string "son état de sérénité habituel… Mais\p"
	.string "notre jeune typhon est revenu pour\n"
	.string "nous mettre à nouveau à l'épreuve !\p"
	.string "Eh bien, mon ami, certainement ! Je\n"
	.string "serai ravie de danser avec toi… Ah,\p"
	.string "non, non, non. Vous n'avez avec\n"
	.string "vous qu'un seul POKéMON. J'aimerais\p"
	.string "que vous reveniez avec deux\n"
	.string "POKéMON, peut-être plus, s'il vous\p"
	.string "plaît.$"
