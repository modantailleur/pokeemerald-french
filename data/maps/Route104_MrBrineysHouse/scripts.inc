.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "M. MARCO : Attends, ma fille !\n"
	.string "Attends, PEEKO !$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hein ? Vous êtes {PLAYER}{KUN} ! Tu\n"
	.string "as sauvé mon chéri PEEKO ! Nous\p"
	.string "vous devons tellement ! Qu'est ce\n"
	.string "que c'est? Tu veux naviguer avec\p"
	.string "moi ? Hmhm… Vous avez une LGUIDOTRE\n"
	.string "à destination de DEWFORD et un\p"
	.string "paquet pour SLATEPORT, alors ? Vous\n"
	.string "devez mener une vie bien remplie !\p"
	.string "Mais ce que vous demandez ne pose\n"
	.string "certainement aucun problème. Vous\p"
	.string "êtes tombé sur la bonne personne !\n"
	.string "Nous mettrons le cap sur DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "M. MARCO : DEWFORD, c'est vrai,\n"
	.string "alors ! Les ancres sont levées !\p"
	.string "PEEKO, on part, mon chéri!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "M. MARCO : C'est vrai ? Vos\n"
	.string "livraisons peuvent attendre ?\p"
	.string "Continuez et dites-moi quand vous\n"
	.string "voulez mettre les voiles !$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "M. MARCO : Ohé ! Je sais exactement\n"
	.string "ce que tu veux dire ! Vous devez\p"
	.string "remettre une LGUIDOTRE à DEWFORD et\n"
	.string "un colis à SLATEPORT. Ce que vous\p"
	.string "avez besoin de moi ne pose aucun\n"
	.string "problème : je suis l'homme de la\p"
	.string "situation ! Tout d’abord, nous\n"
	.string "mettrons le cap sur DEWFORD.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "M. MARCO : Ohé ! Je sais exactement\n"
	.string "ce que tu veux dire ! Vous devez\p"
	.string "livrer un colis au CAPT. POUPE à\n"
	.string "SLATEPORT. Ce que vous avez besoin\p"
	.string "de moi ne pose aucun problème : je\n"
	.string "suis l'homme de la situation ! Tout\p"
	.string "d’abord, nous mettrons le cap sur\n"
	.string "DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "M. MARCO : Ohé ! Pour toi, je sors\n"
	.string "en mer à tout moment ! Maintenant,\p"
	.string "mon ami, où allons-nous ?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "M. MARCO : C'est vrai ? Eh bien,\n"
	.string "PEEKO vous doit la vie. Continuez\p"
	.string "et dites-moi quand vous voulez\n"
	.string "mettre les voiles !$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO : Très chaud !$"
