.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Moi aussi, je veux voir GROUDON,\n"
	.string "mais ils ne me laissent même pas\p"
	.string "voir sa queue… Ça me frustre\n"
	.string "vraiment. Oh non! J'ai bavardé sur\p"
	.string "GROUDON !$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Je suppose qu'il est impossible de\n"
	.string "gagner si l'on n'a pas l'esprit\p"
	.string "calme…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Je me demande si GROUDON a même une\n"
	.string "queue ?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha ! Bientôt! Très bientôt!\n"
	.string "Notre grand objectif sera atteint!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr… Je suis arrivé jusqu'ici,\n"
	.string "mais maintenant ça ?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAX, monsieur ! Un intrus se dirige\n"
	.string "vers vous !$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Vous n'avez pas encore fini ! Vous\n"
	.string "ne vous en sortirez pas facilement\p"
	.string "!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Étais-je si facile à renverser ?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Allez, encore un match…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Héhéhé ! Vous êtes arrivé\n"
	.string "jusqu'ici, alors je vais vous le\p"
	.string "dire ! C'est exact! Devant, GROUDON\n"
	.string "dort ! MAX est allée chez GROUDON\p"
	.string "il y a quelques secondes seulement\n"
	.string "! Il va bientôt se réveiller ! Héhé\p"
	.string "! Héhéhé !$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Démonté à nouveau… Héhé…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Et pendant que tu perdais du temps\n"
	.string "avec moi, MAX aurait dû réveiller\p"
	.string "GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAX : GROUDON… Rien ne pourrait te\n"
	.string "réveiller de ton sommeil baigné de\p"
	.string "magma… Cet ORBE BLEU est ce que tu\n"
	.string "cherchais. N'est-ce pas ? Je vous\p"
	.string "ai apporté l'ORBE BLEU. Laissez son\n"
	.string "éclat vous réveiller ! Et\p"
	.string "montre-moi… Montre-moi toute\n"
	.string "l'étendue de ton pouvoir !$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAX : GROUDON ! Qu'est-ce qui ne va\n"
	.string "pas? L'ORBE BLEU n'était-il pas la\p"
	.string "clé ? GROUDON! Où es-tu allé…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAX : Oh, alors c'était toi ? Je\n"
	.string "vous ai vu fouiner ici et là sans y\p"
	.string "être invité… Je comprends\n"
	.string "maintenant ! Vous devez avoir\p"
	.string "réalisé une cascade bon marché !$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Qu'est-ce qui vous rend si habile à\n"
	.string "gérer POKéMON ?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAX : Il doit y avoir une raison\n"
	.string "pour laquelle GROUDON a fui… C'est\p"
	.string "ce que tu essaies de dire, n'est-ce\n"
	.string "pas ? … … … … … … … … … … … Humph…\p"
	.string "Tu crois que je ne le savais pas ?\n"
	.string "GROUDON parti, on n'a plus besoin\p"
	.string "de ce foutu volcan. Je cours après\n"
	.string "GROUDON, alors c'est ici qu'on se\p"
	.string "quitte !$"
