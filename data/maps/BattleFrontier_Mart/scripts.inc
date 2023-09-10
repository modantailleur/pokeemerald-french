.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Nous sommes venus ici pour\n"
	.string "chaperonner notre petit-fils. Mais\p"
	.string "puisque nous sommes ici, nous avons\n"
	.string "pensé que nous devrions acheter\p"
	.string "quelques souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Cher, qu'en penses-tu ? Cela ne\n"
	.string "ferait-il pas un joli cadeau ?\p"
	.string "C'est…PRO…TE…IN ? Ça a l'air\n"
	.string "délicieux, n'est-ce pas ?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "De nombreuses installations de ZONE\n"
	.string "DE COMBAT ne permettent pas\p"
	.string "l'utilisation d'objets pendant les\n"
	.string "batailles. Cette règle rend les\p"
	.string "choses plus difficiles qu’elles ne\n"
	.string "le sont déjà !$"
