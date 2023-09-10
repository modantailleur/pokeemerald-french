BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Héhé! Je peux dire à quoi pensent\n"
	.string "les POKéMON ! S'il te plaît!\p"
	.string "Puis-je voir votre POKéMON ?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Huer! Pas cher ! $"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Il se battra même s'il a\p"
	.string "beaucoup d'aïe !$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Mais s'il est\p"
	.string "suffisamment gêné, il ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Mais s'il est suffisamment\p"
	.string "gêné, il s'inquiétera pour lui-même\n"
	.string "!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Il se battra même s'il a\p"
	.string "beaucoup d'aïe !$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Mais s'il est\p"
	.string "suffisamment gêné, il ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Mais s'il est\p"
	.string "suffisamment gêné, il s'inquiétera\n"
	.string "pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Il se battra même s'il a\p"
	.string "beaucoup d'aïe !$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Mais s'il est\p"
	.string "suffisamment gêné, il ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Mais s'il est suffisamment\p"
	.string "gêné, il s'inquiétera pour lui-même\n"
	.string "!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Il dit qu'il aime être\p"
	.string "sournois même s'il a beaucoup de\n"
	.string "ouchies !$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Mais s'il est suffisamment\p"
	.string "gêné, il deviendra sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Il se battra même s'il a\p"
	.string "beaucoup d'aïe !$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Il dit qu'il aime être\p"
	.string "sournois même s'il a beaucoup de\n"
	.string "ouchies !$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Mais s'il est\p"
	.string "suffisamment gêné, il s'inquiétera\n"
	.string "pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Il dit qu'il\p"
	.string "s'inquiète de lui-même, qu'il soit\n"
	.string "ouchi ou non !$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Mais s'il est\p"
	.string "suffisamment gêné, il deviendra\n"
	.string "sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Il dit qu'il\p"
	.string "s'inquiète pour lui même s'il est\n"
	.string "très gêné !$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm… Celui-ci dit qu'il aime être\n"
	.string "sournois ! Il dit qu'il aime être\p"
	.string "sournois même s'il a beaucoup de\n"
	.string "ouchies !$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Il dit qu'il\p"
	.string "s'inquiète pour lui même s'il est\n"
	.string "très gêné !$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Mais s'il est\p"
	.string "suffisamment gêné, il ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm… Celui-ci dit qu'il aime se\n"
	.string "battre ! Mais s'il est suffisamment\p"
	.string "gêné, il deviendra sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm… Celui-ci dit qu'il prend soin\n"
	.string "de lui-même ! Mais s'il est\p"
	.string "suffisamment gêné, il deviendra\n"
	.string "sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "C'est bête! Un EGG dort ! Je ne\n"
	.string "peux pas lui parler !$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Quel charme! Cette petite dame\n"
	.string "prétend qu'elle peut comprendre\p"
	.string "POKéMON !$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "J'ai l'impression que la petite\n"
	.string "fille dit quelque chose de\p"
	.string "profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Je sais quelque chose! Cette petite\n"
	.string "fille joue beaucoup à la maison\p"
	.string "rouge !$"
