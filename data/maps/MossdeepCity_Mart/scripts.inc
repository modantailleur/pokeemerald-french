MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "REVIVE est fantastique ! Donnez-le\n"
	.string "à un POKéMON évanoui et le POKéMON\p"
	.string "apparaîtra. Mais attention, REVIVE\n"
	.string "ne restaure pas les PP des coups\p"
	.string "épuisés.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPEL éloigne tous les POKéMON\n"
	.string "faibles. De tous les sprays REPEL,\p"
	.string "c'est celui qui dure le plus\n"
	.string "longtemps.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les NGUIDO et DIVE BALLS sont des\n"
	.string "POKé BALLS rares qui sont\p"
	.string "uniquement fabriquées à MOSSDEEP.\n"
	.string "Un NGUIDO BALL est efficace contre\p"
	.string "les POKéMON de type BUG et de type\n"
	.string "EAU. Une BALLE DE PLONGÉE\p"
	.string "fonctionne mieux sur POKéMON au\n"
	.string "fond de la mer.$"
