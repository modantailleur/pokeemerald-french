LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Bienvenue chez HERB SHOP, la maison\n"
	.string "de médicaments efficaces et peu\p"
	.string "coûteux !$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Vous êtes venu chercher de la\n"
	.string "phytothérapie à LAVARIDGE ? C'est\p"
	.string "plutôt louable. Je t'aime bien!\n"
	.string "Prends ça !$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Le CHARBON que je t'ai donné est\n"
	.string "utilisé pour fabriquer des plantes\p"
	.string "médicinales. Il fait également des\n"
	.string "merveilles lorsqu'il est détenu par\p"
	.string "un POKéMON. Il intensifie la\n"
	.string "puissance des mouvements de type\p"
	.string "FEU.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "La phytothérapie fonctionne à\n"
	.string "merveille. Mais votre POKéMON ne\p"
	.string "vous aimera pas à cause de cela. Ça\n"
	.string "doit être horriblement amer !$"
