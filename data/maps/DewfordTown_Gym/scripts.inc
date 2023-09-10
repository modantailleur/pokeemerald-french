DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, {PLAYER} CHAMPION\n"
	.string "? Le GYM LEADER BASTIEN de DEWFORD\p"
	.string "commande des POKéMON de type\n"
	.string "COMBAT. Aller contre lui avec un\p"
	.string "POKéMON de type NORMAL, c'est lui\n"
	.string "causer des ennuis. COMBATTRE DES\p"
	.string "POKéMON infligera de sérieux dégâts\n"
	.string "aux POKéMON NORMAUX, alors soyez\p"
	.string "prudent ! Pire encore, le GYM est\n"
	.string "aussi sombre que le fond de\p"
	.string "l'océan. Mais cela deviendra plus\n"
	.string "brillant après avoir vaincu les\p"
	.string "DRESSEURS sur votre chemin. Hé,\n"
	.string "d'accord, vas-y !$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Waouh ! Il fait trop clair ici !\n"
	.string "Votre avenir est également\p"
	.string "prometteur !$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La force a raison ! Allez!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Pas assez de puissance…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Votre talent a vaincu ma force !\n"
	.string "Votre technique est louable !$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Il n'est pas nécessaire que BASTIEN\n"
	.string "soit impliqué ! Je vais t'écraser\p"
	.string "!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mais comment? Comment ai-je pu\n"
	.string "perdre si facilement ?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Je ne vais pas gaspiller cette\n"
	.string "perte. Je vais l'utiliser pour me\p"
	.string "motiver à m'entraîner ! Un jour, je\n"
	.string "deviendrai un LEADER DU GYM… Non,\p"
	.string "je deviendrai le CHAMPION DE LA\n"
	.string "LIGUE POKéMON !$"

DewfordTown_Gym_Text_LauraIntro:
	.string "N'ose pas me repousser ! Ce n'est\n"
	.string "pas ma faute si tu pleures !$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah ! J'ai perdu !$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Je me bats dans le noir pour rendre\n"
	.string "mon cœur plus fort. Mais comme il\p"
	.string "fait si sombre, je ne peux jamais\n"
	.string "voir le visage de BASTIEN…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu… Tu trébuches dans le noir ?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, toi… je ne veux pas te\n"
	.string "connaître !$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Vous méritez de rester perdu et de\n"
	.string "vous retrouver à nouveau à l'entrée\p"
	.string "!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Je vais vous montrer le courage\n"
	.string "d'un marin !$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Comment est-ce arrivé ? Ce n'est\n"
	.string "pas mon genre de perdre de cette\p"
	.string "façon !$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ah oui ! Vous méritez de voir notre\n"
	.string "GYM LEADER.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si tu veux réussir, ça doit passer\n"
	.string "par moi !$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrr ! Largement maîtrisé !$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Vous gagnez! Allez après ce BADGE\n"
	.string "!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Je suis BASTIEN ! LE LEADER DU GYM\n"
	.string "DE DEWFORD ! J'ai été ballotté par\p"
	.string "les vagues agitées de ces régions,\n"
	.string "et je suis devenu dur dans la\p"
	.string "grotte noire ! Alors tu voulais me\n"
	.string "défier ? Laisse-moi voir de quoi tu\p"
	.string "es fait !$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Waouh, wow ! Vous avez fait\n"
	.string "beaucoup plus de bruit que ce à\p"
	.string "quoi je m'attendais ! Tu m'as\n"
	.string "submergé ! OK, tu m'as. Prenez ce\p"
	.string "GYM BADGE !$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} a reçu le KNUCKLE BADGE de\n"
	.string "BASTIEN.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Le KNUCKLE BADGE fait que tous les\n"
	.string "POKéMON jusqu'au niveau 30, même\p"
	.string "ceux que vous obtenez dans les\n"
	.string "échanges, obéissent sans poser de\p"
	.string "questions. Et vous pourrez utiliser\n"
	.string "le mouvement FLASH HM en dehors du\p"
	.string "combat. Si vous le souhaitez,\n"
	.string "utilisez également cette MACHINE\p"
	.string "TECHNIQUE.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Ce TM08 contient BULK UP. C'est un\n"
	.string "mouvement qui augmente à la fois\p"
	.string "les statistiques d'ATTAQUE et de\n"
	.string "DÉFENSE. … … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Inscrit GYM LEADER BASTIEN dans le\n"
	.string "POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Je vois votre talent devenir une\n"
	.string "vague géante pour provoquer un jour\p"
	.string "une tempête d'étonnement parmi les\n"
	.string "FORMATTHIEUEURS !$"

DewfordTown_Gym_Text_GymStatue:
	.string "GYM POKéMON DE LA VILLAGE MYOKARA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "DRESSEURS CERTIFIÉS DE VILLAGE\n"
	.string "MYOKARA POKéMON GYM BASTIEN :\p"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BASTIEN : Une vague peut reculer,\n"
	.string "mais elle revient toujours vers le\p"
	.string "rivage. Une vague géante d'un\n"
	.string "talent comme toi… Je savais que tu\p"
	.string "reviendrais ! Montre-moi à quel\n"
	.string "point tu es allé plus haut !$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Ouah! Encore débordé !$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BASTIEN : Les combats sont vastes\n"
	.string "et profonds. On ne voit pas le\p"
	.string "fond. C'est comme la mer de HOENN\n"
	.string "!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BASTIEN : Une vague peut reculer,\n"
	.string "mais elle revient toujours vers le\p"
	.string "rivage. Une vague géante d'un\n"
	.string "talent comme toi… Je savais que tu\p"
	.string "reviendrais ! Oh? Vous n'avez qu'un\n"
	.string "seul POKéMON capable de combattre.\p"
	.string "Je suis désolé, mais j'aimerais que\n"
	.string "tu reviennes avec au moins deux\p"
	.string "POKéMON.$"
