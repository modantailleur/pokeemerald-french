MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "J'aime tout ce qui est horrible…\n"
	.string "C'est comme une maladie… Quand je\p"
	.string "suis ici… je frissonne de peur…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Perdre, je n'aime pas…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Je veux voir des choses terribles…\n"
	.string "Je ne peux pas partir… Reste… Ne\p"
	.string "veux-tu pas rester avec moi ?$"
