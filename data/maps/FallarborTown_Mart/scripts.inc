FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "J'ai du mal à décider si je dois\n"
	.string "faire évoluer mon SKITTY ou non. Il\p"
	.string "ne me reste plus qu'à utiliser\n"
	.string "cette PIERRE DE LUNE, mais c'est\p"
	.string "tellement difficile de se décider…\n"
	.string "Si je la fais évoluer, elle\p"
	.string "deviendra bien plus forte. Mais ce\n"
	.string "sera aussi très différent.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY : Miyao ? $"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "Cette NUGGGUIDO que j'ai trouvée\n"
	.string "ici… Je suppose que je vais devoir\p"
	.string "la vendre, vu qu'elle n'a pas\n"
	.string "d'autre utilité.$"
