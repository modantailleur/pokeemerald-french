FortreeCity_DecorationShop_MapScripts::
	.byte 0

FortreeCity_DecorationShop_EventScript_PokefanM::
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_Girl::
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_ClerkDesks::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Desks:
	.2byte DECOR_SMALL_DESK
	.2byte DECOR_POKEMON_DESK
	.2byte DECOR_HEAVY_DESK
	.2byte DECOR_RAGGED_DESK
	.2byte DECOR_COMFORT_DESK
	.2byte DECOR_BRICK_DESK
	.2byte DECOR_CAMP_DESK
	.2byte DECOR_HARD_DESK
	.2byte DECOR_NONE
	release
	end

FortreeCity_DecorationShop_EventScript_ClerkChairs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Chairs:
	.2byte DECOR_SMALL_CHAIR
	.2byte DECOR_POKEMON_CHAIR
	.2byte DECOR_HEAVY_CHAIR
	.2byte DECOR_RAGGED_CHAIR
	.2byte DECOR_COMFORT_CHAIR
	.2byte DECOR_BRICK_CHAIR
	.2byte DECOR_CAMP_CHAIR
	.2byte DECOR_HARD_CHAIR
	.2byte DECOR_NONE
	release
	end

FortreeCity_DecorationShop_Text_MerchandiseSentToPC:
	.string "Les marchandises que vous achetez\n"
	.string "ici sont envoyées sur votre propre\p"
	.string "PC. C'est fantastique! J'aimerais\n"
	.string "qu'ils puissent aussi me ramener à\p"
	.string "la maison comme ça.$"

FortreeCity_DecorationShop_Text_BuyingDeskForDolls:
	.string "J'achète un joli bureau et j'y pose\n"
	.string "mes jolies DOLLS. Si je ne le fais\p"
	.string "pas, lorsque je décore ma BASE\n"
	.string "SECRGUIDO, mes POUPÉES se saliront\p"
	.string "ou se piqueront d'échardes.$"
