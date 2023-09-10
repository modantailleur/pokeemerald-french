MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Eh bien, qu'avons-nous ici ? Un\n"
	.string "client des plus énergiques ! Moi?\p"
	.string "Vous pouvez m'appeler RODOLPHE. Je\n"
	.string "suis le propriétaire de ce magasin\p"
	.string "de vélos.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RODOLPHE : Vos CHAUSSURES DE\n"
	.string "COURSE… Elles sont terriblement\p"
	.string "sales. Vous venez de loin ?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RODOLPHE : Est-ce vrai ? Ensuite,\n"
	.string "je suppose que vous n'avez besoin\p"
	.string "d'aucun de mes VÉLOS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RODOLPHE : Hm, hm… … … … … Vous\n"
	.string "dites que vous avez fait tout ce\p"
	.string "chemin depuis LITTLEROOT ? Mon\n"
	.string "Dieu! C'est ridiculement loin ! Si\p"
	.string "vous aviez un de mes VÉLOS, vous\n"
	.string "pourriez aller n'importe où\p"
	.string "facilement tout en ressentant la\n"
	.string "douce caresse du vent ! Je vais\p"
	.string "vous dire ce que! Je vais vous\n"
	.string "donner un VELO ! Oh, attends une\p"
	.string "seconde ! J'ai oublié de vous dire\n"
	.string "qu'il existe deux sortes de VELOS !\p"
	.string "Ce sont le MACH BIKE et l’ACRO BIKE\n"
	.string "! Le MACH BIKE s'adresse aux\p"
	.string "cyclistes qui veulent sentir le\n"
	.string "vent avec leur corps ! Et un ACRO\p"
	.string "BIKE s’adresse à ceux qui préfèrent\n"
	.string "les balades techniques ! Je suis\p"
	.string "une vraie chérie, donc vous pouvez\n"
	.string "avoir celui que vous voulez !\p"
	.string "Lequel choisirez-vous ?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} a choisi le MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} a choisi l'ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RODOLPHE : Si vous avez envie de\n"
	.string "changer de VÉLO, venez me voir !$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RODOLPHE : Ah ? Envisagez-vous de\n"
	.string "changer de VÉLO ?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RODOLPHE : D’accord, pas de\n"
	.string "problème ! Je vais changer de VÉLOS\p"
	.string "pour toi !$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} a échangé le MACH BIKE\n"
	.string "contre un ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} a échangé l'ACRO BIKE contre\n"
	.string "un MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RODOLPHE : Bien, bien ! Je suis\n"
	.string "contente que ça te plaise !$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Qu'est-il arrivé à ce VÉLO que\n"
	.string "je t'ai donné ? Oh, je comprends,\p"
	.string "vous l'avez stocké à l'aide de\n"
	.string "votre PC. Eh bien, sortez-le du\p"
	.string "stockage du PC et je me ferai un\n"
	.string "plaisir de l'échanger ! Que le vent\p"
	.string "soit toujours de votre côté dans\n"
	.string "votre aventure !$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "J'apprends les vélos pendant que je\n"
	.string "travaille ici. Si vous avez besoin\p"
	.string "de conseils sur la façon de\n"
	.string "conduire votre VÉLO, vous trouverez\p"
	.string "quelques manuels à l'arrière.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "C'est un manuel sur le MACH BIKE.\n"
	.string "Quelle page voulez-vous lire ?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Un VÉLO se déplace dans la\n"
	.string "direction dans laquelle la touche +\p"
	.string "est enfoncée. Il accélérera une\n"
	.string "fois qu’il roulera. Pour arrêter,\p"
	.string "relâchez la manette +. Le BIKE\n"
	.string "ralentira jusqu’à s’arrêter. Vous\p"
	.string "voulez lire une autre page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Un MACH BIKE est rapide, mais il ne\n"
	.string "peut pas s'arrêter très rapidement.\p"
	.string "Il devient un peu difficile de\n"
	.string "contourner un virage. Relâchez la\p"
	.string "manette + un peu avant le virage et\n"
	.string "ralentissez. Vous voulez lire une\p"
	.string "autre page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Il existe de petites pentes\n"
	.string "sablonneuses dans toute la région\p"
	.string "de HOENN. Le sable meuble et\n"
	.string "friable rend impossible une\p"
	.string "ascension normale. Mais si vous\n"
	.string "avez un MACH BIKE, vous pouvez\p"
	.string "gravir une pente sablonneuse. Vous\n"
	.string "voulez lire une autre page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "C'est un manuel sur l'ACRO BIKE.\n"
	.string "Quelle page voulez-vous lire ?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Appuyez sur le bouton B pendant la\n"
	.string "conduite et la roue avant se\p"
	.string "soulève. Vous pouvez vous déplacer\n"
	.string "avec la roue avant relevée à l'aide\p"
	.string "du pavé de commande +. Cette\n"
	.string "technique s'appelle un wheelie.\p"
	.string "Vous voulez lire une autre page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "En maintenant le bouton B enfoncé,\n"
	.string "votre BIKE peut sauter sur place.\p"
	.string "Cette technique s’appelle un bunny\n"
	.string "hop. Vous pouvez également rouler\p"
	.string "en sautillant. Vous voulez lire une\n"
	.string "autre page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Appuyez simultanément sur le bouton\n"
	.string "B et le pavé de commande + pour\p"
	.string "sauter. Appuyez sur le bouton de\n"
	.string "commande + sur le côté pour sauter\p"
	.string "latéralement. Appuyez dessus vers\n"
	.string "l'arrière pour que le VÉLO change\p"
	.string "de direction tout en sautant. Vous\n"
	.string "voulez lire une autre page?$"
