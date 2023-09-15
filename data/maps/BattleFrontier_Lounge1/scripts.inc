BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Depuis 70 ans j'élève des POKéMON !\n"
	.string "Je suis l'homme qu'ils vénèrent\p"
	.string "comme le légendaire meilleur\n"
	.string "éleveur de POKéMON ! Si jamais vous\p"
	.string "devenez aussi aguerri que moi, vous\n"
	.string "verrez les capacités de POKéMON en\p"
	.string "un coup d'oeil. Vous êtes\n"
	.string "DRESSEUR. Cela ne vous\p"
	.string "intéresse-t-il pas de connaître les\n"
	.string "capacités de votre propre POKéMON ?\p"
	.string "Ici! Jetons un coup d'œil à votre\n"
	.string "POKéMON !$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm… Celui-ci, dans l’ensemble, je\n"
	.string "le décrirais comme étant de\p"
	.string "capacité moyenne.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm… Celui-ci, dans l’ensemble, je\n"
	.string "le décrirais comme ayant des\p"
	.string "capacités supérieures à la\n"
	.string "moyenne.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm… Celui-ci, dans l’ensemble, je\n"
	.string "dirais qu’il est assez\p"
	.string "impressionnant en termes de\n"
	.string "capacités !$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm… Celui-ci, dans l’ensemble, je\n"
	.string "dirais qu’il est merveilleusement\p"
	.string "exceptionnel en termes de capacités\n"
	.string "!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "D’ailleurs, le meilleur aspect, je\n"
	.string "dirais, c’est son HP…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "D’ailleurs, le meilleur aspect, je\n"
	.string "dirais, c’est son ATTAQUE…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "D’ailleurs, le meilleur aspect, je\n"
	.string "dirais, c’est sa DÉFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "D’ailleurs, le meilleur aspect, je\n"
	.string "dirais, c’est son ATTAQUE\p"
	.string "SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "D’ailleurs, le meilleur aspect, je\n"
	.string "dirais, est sa DÉFENSE SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Soit dit en passant, le meilleur\n"
	.string "aspect, je dirais, est sa VITESSE…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Cette statistique est relativement\n"
	.string "bonne. …Hm… C'est comme ça que je\p"
	.string "l'appelle.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Cette statistique est assez\n"
	.string "impressionnante. …Hm… C'est comme\p"
	.string "ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Cette statistique est\n"
	.string "exceptionnelle ! …Hm… C'est comme\p"
	.string "ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "C'est impeccable ! Une chose de\n"
	.string "perfection ! …Hm… C'est comme ça\p"
	.string "que je l'appelle.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Quoi? Vous n'avez pas le temps pour\n"
	.string "mes conseils ? Vous devriez\p"
	.string "toujours avoir envie d’apprendre\n"
	.string "des expériences de vos aînés !$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Oui, qu'est-ce qu'il y a maintenant\n"
	.string "? J'ai des affaires à régler !\p"
	.string "Gardez-le pour la prochaine fois !$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, jeune ! Les capacités de votre\n"
	.string "POKéMON vous intriguent ? Ici ici!\p"
	.string "Jetons un coup d'œil à votre\n"
	.string "POKéMON !$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Je suis un expert, mais même moi,\n"
	.string "je ne peux rien dire sur un POKéMON\p"
	.string "non éclos ! Montre-moi un POKéMON !\n"
	.string "Un POKéMON, c'est ce que j'ai\p"
	.string "besoin de voir !$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Il a dit que mon POKéMON était\n"
	.string "exceptionnel ! Je suis content de\p"
	.string "l'avoir élevé avec soin !$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Il a dit que mon POKéMON était\n"
	.string "exceptionnel ! Mais je n'ai rien\p"
	.string "fait de spécial pour l'élever…$"
