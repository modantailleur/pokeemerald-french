SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Euh-hem ! Je suis le PRÉSIDENT du\n"
	.string "FAN CLUB POKéMON ! En tant que\p"
	.string "PRÉSIDENT, je suis naturellement le\n"
	.string "plus important ! Personne ne peut\p"
	.string "me battre lorsqu'il s'agit d'élever\n"
	.string "des POKéMON. Personne! Eh bien,\p"
	.string "laissez-moi vous parler des\n"
	.string "CONCOURS POKéMON. Ce sont des\p"
	.string "événements où l'on peut montrer\n"
	.string "POKéMON au monde entier !\p"
	.string "Cependant, ils ont lieu dans des\n"
	.string "villes éloignées et je ne peux donc\p"
	.string "pas y participer assez souvent.\n"
	.string "C'est pourquoi nous nous réunissons\p"
	.string "ici pour montrer notre POKéMON et\n"
	.string "demander aux autres de nous montrer\p"
	.string "le leur.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Le POKéMON d'un DRESSEUR qui a\n"
	.string "participé à un CONCOURS POKéMON…\p"
	.string "Ça, j'aimerais bien le voir.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Euh-hem ! Je vois que vous avez\n"
	.string "participé à un CONCOURS POKéMON !\p"
	.string "S'il te plaît! Permettez-moi\n"
	.string "d'examiner comment vous avez élevé\p"
	.string "votre POKéMON. Cela me ravit sans\n"
	.string "fin de voir des POKéMON élevés par\p"
	.string "d'autres FORMATTHIEUEURS. Les\n"
	.string "expressions heureuses de POKéMON\p"
	.string "élevé avec les soins appropriés…\n"
	.string "Les yeux bienveillants de\p"
	.string "l'DRESSEUR qui a nourri et élevé le\n"
	.string "POKéMON… Cette simple pensée\p"
	.string "remplit mon cœur de joie. Oh! Je\n"
	.string "vous demande pardon ! Pardonnez-moi\p"
	.string "de bavarder ainsi ! S'il te plaît!\n"
	.string "Permettez-moi d'examiner à quel\p"
	.string "point votre POKéMON a grandi !$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Comment grandit votre POKéMON ?\n"
	.string "Permettez-moi de l'examiner.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm… je vois…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Ce n'est pas mal, mais ce\n"
	.string "n'est pas bon non plus… Vous,\p"
	.string "l'DRESSEUR, devez faire plus\n"
	.string "d'efforts pour élever ce POKéMON !\p"
	.string "Par exemple, puis-je vous suggérer\n"
	.string "de lui donner plus de {POKEBLOCK} S ?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Oh, mon Dieu… Votre POKéMON grandit\n"
	.string "plutôt bien, vous méritez donc une\p"
	.string "récompense. Malheureusement, vous\n"
	.string "n'avez pas de place pour cela dans\p"
	.string "votre BAG.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Votre {STR_VAR_1} grandit de manière\n"
	.string "impressionnante ! C'est un beau\p"
	.string "spécimen ! Mais! Si vous lui\n"
	.string "donniez cela, il pousserait encore\p"
	.string "mieux ! En effet !$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Laissez un POKéMON tenir cette\n"
	.string "ÉCHARPE ROUGE. Tout le monde\p"
	.string "reconnaîtra la fraîcheur de ce\n"
	.string "POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Laissez un POKéMON tenir cette\n"
	.string "ÉCHARPE BLEUE. Sa beauté sera bien\p"
	.string "plus accentuée que maintenant !$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Laissez un POKéMON tenir cette\n"
	.string "ÉCHARPE ROSE. Cela fera ressortir\p"
	.string "encore plus la gentillesse du\n"
	.string "POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Laissez un POKéMON tenir cette\n"
	.string "ÉCHARPE VERTE. Cela améliorera\p"
	.string "l'intelligence de POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Laissez un POKéMON tenir cette\n"
	.string "ÉCHARPE JAUNE. Cela renforcera\p"
	.string "encore plus la résistance de votre\n"
	.string "POKéMON !$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Je suis désolé, mais je n'ai rien\n"
	.string "d'autre à vous donner ! Pas du\p"
	.string "tout! Après tout, vous avez la\n"
	.string "chance d'avoir le cadeau d'élever\p"
	.string "des POKéMON sans avoir recours à\n"
	.string "aucun objet !$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "J'adore voir des POKéMON qui aiment\n"
	.string "leurs dresseurs. Les POKéMON sont\p"
	.string "très sensibles aux sentiments de\n"
	.string "leurs dresseurs. Si vous traitez\p"
	.string "votre POKéMON avec amour et soin,\n"
	.string "il vous aimera en retour. Quand\p"
	.string "votre POKéMON commence à vous\n"
	.string "aimer, venez me le montrer.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Votre POKéMON vous adore vraiment.\n"
	.string "Pour vous, un DRESSEUR des plus\p"
	.string "compatissants, un cadeau du FAN\n"
	.string "CLUB !$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Les POKéMON sont très sensibles aux\n"
	.string "sentiments de leurs dresseurs. Si\p"
	.string "vous traitez votre POKéMON avec\n"
	.string "amour et soin, il vous aimera en\p"
	.string "retour.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Si vous continuez à laisser un\n"
	.string "POKéMON s'évanouir au combat, il\p"
	.string "finira par lui en vouloir. Bientôt,\n"
	.string "il deviendra moins confiant envers\p"
	.string "le FORMATTHIEUEUR. En d’autres\n"
	.string "termes, il ne vous plaira\p"
	.string "certainement pas beaucoup.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "POKéMON aime-t-il avoir des objets\n"
	.string "utilisés dessus ? Le mien était\p"
	.string "vraiment heureux quand je lui ai\n"
	.string "donné des PROTÉINES.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY : Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "Zigzags : Pourquoi…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZYMARILL : Marimari ?$"
