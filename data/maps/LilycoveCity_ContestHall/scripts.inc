@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Ce POKéMON a gagné le CONCOURS DE\n"
	.string "BEAUTÉ ici auparavant. Bien devinez\p"
	.string "quoi? Aujourd'hui, je lui ai fait\n"
	.string "gagner un CONCOURS D'INTELLIGENCE !\p"
	.string "Mes capacités me font même peur…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "J'ai participé à de nombreux\n"
	.string "CONCOURS, donc je vois comment les\p"
	.string "choses fonctionnent. Si vous\n"
	.string "participez à un CONCOURS DE\p"
	.string "COOLNESS, les mouvements sympas\n"
	.string "sont considérés comme des appels.\p"
	.string "Mais les mouvements intelligents et\n"
	.string "les mouvements mignons ne font pas\p"
	.string "bon ménage, par exemple.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Ce jeune homme qui a gagné plus tôt\n"
	.string "possédait tout un tas de {POKEBLOCK}\p"
	.string "différents. Pouvez-vous gagner si\n"
	.string "vous aviez autant de ces choses ?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Whoa, cet endroit n'est-il pas\n"
	.string "énorme ! La tension dans l'air… Ce\p"
	.string "n'est pas comme une salle de\n"
	.string "CONCOURS dans les bâtons.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC : D'accord, SMART POKéMON et\n"
	.string "leurs DRESSEURS, êtes-vous prêts ?!\p"
	.string "Donnez-lui le meilleur de vous-même\n"
	.string "! Faisons appel !$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUGE : Amusez-vous ce CONCOURS ?\n"
	.string "Revenez avec trois amis et vous\p"
	.string "pourrez tous participer à un\n"
	.string "CONCOURS !$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay… J'ai participé au mauvais\n"
	.string "CONCOURS. J'ai inscrit ce POKéMON\p"
	.string "coriace au CONCOURS D'INTELLIGENCE…\n"
	.string "Allez, épatez-les avec un ROCK\p"
	.string "SMASH au look intelligent.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "J'ai passé de nombreuses années, et\n"
	.string "toute ma sagesse en plus, à élever\p"
	.string "ce POKéMON pour être intelligent.\n"
	.string "Il ne sera pas facilement battu par\p"
	.string "le POKéMON d'un jeune chiot. Ma\n"
	.string "chère épouse, voyez-vous ça ?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Le voilà! Si mon POKéMON fait\n"
	.string "ensuite un geste intelligent,\p"
	.string "l'enthousiasme du public sera à son\n"
	.string "comble !$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, chérie, non ! Le LEECH LIFE de\n"
	.string "mon chéri ZUBAT est si mignon que\p"
	.string "j'ai continué à l'utiliser encore\n"
	.string "et encore ! Mais ça veut dire que\p"
	.string "les gens ne l'apprécient pas du\n"
	.string "tout !$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah ! Tu es magnifique,\n"
	.string "grand-père !$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Même lorsque les dresseurs entrent\n"
	.string "dans le même type de POKéMON, ils\p"
	.string "semblent tous utiliser des\n"
	.string "mouvements différents pour faire\p"
	.string "appel. C'est comme la façon dont\n"
	.string "les gens ont des styles différents\p"
	.string "pour se battre.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Je pense que les POKéMON ont l'air\n"
	.string "plus intelligents que leurs\p"
	.string "dresseurs. De beaucoup.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "En fin de compte, j’aime toujours\n"
	.string "les CONCOURS D’INTELLIGENCE. Cette\p"
	.string "couleur verte intellectuelle… C'est\n"
	.string "tellement… Tellement… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC : Participez-vous également au\n"
	.string "CONCOURS DE BEAUTÉ ? Bonne chance\p"
	.string "!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUGE : Ah, chaque POKéMON ici est\n"
	.string "un modèle d'une beauté immaculée !\p"
	.string "Eh bien, j'ai presque oublié de les\n"
	.string "noter !$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON aussi beau… Il n'y en a\n"
	.string "pas d'autre comme celui-là. Les\p"
	.string "yeux de tout le monde seront rivés\n"
	.string "sur ma beauté.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah ! J'ai soigneusement brossé\n"
	.string "et soigné mon POKéMON pour ce\p"
	.string "CONCOURS… Mais j'en ai exagéré… Le\n"
	.string "pelage de mon POKéMON est devenu\p"
	.string "tout en lambeaux… Que dois-je faire\n"
	.string "?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Cette AURORA BEAM est si\n"
	.string "éblouissante que le JUGE ne pourra\p"
	.string "pas la voir. Euh, attends une\n"
	.string "seconde… Ça n'aura aucun sens,\p"
	.string "alors !$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Ce joli POKéMON me ressemble quand\n"
	.string "j'étais plus jeune. Juste au moment\p"
	.string "où j'ai dit cela, mon mari a vomi\n"
	.string "le café qu'il buvait. Ai-je dit\p"
	.string "quelque chose de drôle ?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Vous savez, si je gagne à un\n"
	.string "CONCOURS DE BEAUTÉ, c'est sûr que\p"
	.string "ça me fait plaisir. Plus que\n"
	.string "d'habitude, en tout cas.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah ! Allez-vous jeter un\n"
	.string "oeil à tous ces jolis POKéMON !\p"
	.string "J'adore ce genre de paillettes !$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "On ne peut pas toujours gagner\n"
	.string "uniquement sur la beauté. Vous\p"
	.string "devez soigner votre POKéMON pour\n"
	.string "qu'il soit beau et brillant comme\p"
	.string "le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC : Oh-oh ! Bonjour! Nous sommes\n"
	.string "en plein CONCOURS ! Veuillez entrer\p"
	.string "à notre comptoir d'inscription et\n"
	.string "sortir, d'accord ?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUGE : Oh, des appels si charmants\n"
	.string "et si mignons ! Oh mon Dieu! Quel\p"
	.string "attrait pour les SPORTS NAUTIQUES\n"
	.string "parfaitement adorable !$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh non… Ma douce AZURILL a été\n"
	.string "distraite par un autre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mon POKéMON n'a jamais gagné dans\n"
	.string "un combat, mais participez-le à un\p"
	.string "CONCOURS et faites attention !$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La GUIDOSE PÉTALE de mon POKéMON\n"
	.string "est une merveille d'élégance. Je ne\p"
	.string "laisserai personne perturber ses\n"
	.string "performances.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Les POKéMON de tout le monde sont\n"
	.string "très mignons. Cependant, si mon\p"
	.string "POKéMON faisait un appel mignon… je\n"
	.string "suis sûr qu'il serait tellement\p"
	.string "plus mignon que les autres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mon enfant participe à ce\n"
	.string "CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Allons chérie. Allez-y! Votre\n"
	.string "POKéMON est le meilleur !$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Je pense que cette fille là-bas est\n"
	.string "la plus mignonne du groupe. Qu'est\p"
	.string "ce que c'est? Ils jugent POKéMON\n"
	.string "sur leur apparence ?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, en voyant tous ces jolis\n"
	.string "POKéMON, ils nous donnent envie\p"
	.string "d'avoir le mien ! Je vais en\n"
	.string "attraper !$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "STAGE DU CONCOURS DE BEAUTÉ SOYEZ\n"
	.string "SÉDUITS PAR DE MAGNIFIQUES POKéMON\p"
	.string "!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "STAGE DU CONCOURS DE MIGNONNE SOYEZ\n"
	.string "CHARMÉ PAR DES POKéMON MIGNONS !$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "ÉTAPE DU CONCOURS D'INTELLIGENCE\n"
	.string "SOYEZ IMPRESSIONNÉ PAR SMART\p"
	.string "POKéMON !$"
