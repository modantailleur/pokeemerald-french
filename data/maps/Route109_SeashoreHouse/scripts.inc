Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Je suis le propriétaire de la\n"
	.string "SEASHORE HOUSE. Mais vous pouvez\p"
	.string "m'appeler MR. MER! Ce que j'aime\n"
	.string "par-dessus tout, c'est voir des\p"
	.string "combats POKéMON torrides.\n"
	.string "Laisse-moi voir que ton cœur brûle\p"
	.string "! Si vous parvenez à vaincre tous\n"
	.string "les DRESSEURS ici, je\p"
	.string "récompenserai vos efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Montre-moi des matchs chauds ! Je\n"
	.string "dirige cette SEASHORE HOUSE rien\p"
	.string "que pour cette raison !$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Tu es brûlant ! Ces batailles ont\n"
	.string "éclaté ! Je suis plus que satisfait\p"
	.string "! En guise de remerciement de\n"
	.string "m'avoir montré ta séquence chaude,\p"
	.string "je veux que tu prennes ça. C'est\n"
	.string "une demi-douzaine de bouteilles de\p"
	.string "SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, mais bon, ton SAC est plein. Je\n"
	.string "vais les garder pour toi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Vous voulez acheter du SODA POP?\n"
	.string "POKéMON j'adore ! Seulement 300 ¥\p"
	.string "la bouteille ! Achetez-en!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Et voilà !$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Vous n'avez pas d'argent.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Non? C'est dommage.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si vous cherchez une bataille dans\n"
	.string "la SEASHORE HOUSE, vous ne\p"
	.string "trouverez pas d'DRESSEUR plus sexy\n"
	.string "que moi, mon pote !$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "C'était une bataille chaude ! Je\n"
	.string "peux accepter cette perte, mon pote\p"
	.string "!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Chaque fois que je suis dans\n"
	.string "SLATEPORT, j'apprécie les batailles\p"
	.string "torrides et les SODA POP glacés !$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Les batailles ennuyeuses n’en\n"
	.string "valent pas la peine. Des combats\p"
	.string "brûlants et brûlants renforcent les\n"
	.string "dresseurs et les POKéMON !$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "C'est chaud !$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Ouf, j'ai toute soif. Peut-être que\n"
	.string "je prendrai un SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Je vais vous montrer à quel point\n"
	.string "mes POKéMON sont géniaux, mais ne\p"
	.string "pleure pas !$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…J'ai perdu, mais je ne pleurerai\n"
	.string "pas…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si l'un de mes POKéMON savait\n"
	.string "comment me transporter sur l'eau\p"
	.string "sur son dos, je pourrais me\n"
	.string "débarrasser de cette chambre à\p"
	.string "air.$"
