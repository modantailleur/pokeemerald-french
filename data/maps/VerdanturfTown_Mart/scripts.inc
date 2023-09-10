VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Pour tout match POKéMON, X SPECIAL\n"
	.string "est crucial. Cela augmente la\p"
	.string "puissance de certains mouvements\n"
	.string "même si ce n'est que pour une seule\p"
	.string "bataille.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Ils ne semblent pas vendre de\n"
	.string "guides de stratégie gagnante pour\p"
	.string "la TENTE DE COMBAT… Il semble qu'il\n"
	.string "faille compter sur son propre\p"
	.string "esprit après tout…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "La NEST BALL fonctionne mieux sur\n"
	.string "les POKéMON affaiblis. VERGUIDOTURF\p"
	.string "est le seul endroit où vous pouvez\n"
	.string "l'acheter.$"
